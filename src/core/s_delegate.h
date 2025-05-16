// delegate.h
// define delegate
//

#include "s_object.h"
#include <vector>

#ifndef S_DELEGATE_H
#define S_DELEGATE_H

namespace stapler_engine
{
	template<typename t_func> class DLLAPI_SE SDelegate;
	template<typename t_type,typename... t_args>
	class DLLAPI_SE SDelegate<t_type(t_args...)> :public SObject
	{
	protected:
		template<typename t_func> class DLLAPI_SE SDelegateMetadata;
		template<typename t_type, typename... t_args>
		class DLLAPI_SE SDelegateMetadata<t_type(t_args...)> :public SObject
		{
			friend class SDelegate<t_type(t_args...)>;

		public:
			virtual t_type invoke(const t_args&... in_args) = 0;
			virtual bool is_valid() = 0;
			virtual bool is_class() = 0;
		};

		template<typename t_func> class DLLAPI_SE SDelegateMetadataMethod;
		template<typename t_type, typename... t_args>
		class DLLAPI_SE SDelegateMetadataMethod<t_type(t_args...)> :public SDelegateMetadata<t_type(t_args...)>
		{
		protected:
			void* target_;
			t_type(*callback_)(t_args...);

		public:
			virtual t_type invoke(const t_args&... in_args) override{
				return (*callback_)(in_args...);
			}

			virtual bool is_class() override {
				return false;
			}

			virtual bool is_valid() override {
				return callback_ == nullptr;
			}

		public:
			SDelegateMetadataMethod(t_type(*in_function)(t_args...))
				: target_(nullptr), callback_(in_function) {

			}
			~SDelegateMetadataMethod() {
				target_ = nullptr;
				callback_ = nullptr;
			}
		};

		template<typename t_targ, typename t_func> class DLLAPI_SE SDelegateMetadataClass;
		template<typename t_targ, typename t_type, typename... t_args>
		class DLLAPI_SE SDelegateMetadataClass<t_targ, t_type(t_args...)> :public SDelegateMetadata<t_type(t_args...)>
		{
		protected:
			t_targ* target_;
			t_type(t_targ::* callback_)(t_args...);

		public:
			virtual t_type invoke(const t_args&... in_args) override{
				return (target_->*callback_)(in_args...);
			}

			virtual bool is_class() override {
				return true;
			}

			virtual bool is_valid() override {
				return target_ == nullptr || callback_ == nullptr;
			}

		public:
			SDelegateMetadataClass(t_targ* in_target, t_type(t_targ::* in_function)(t_args...))
				: target_(in_target), callback_(in_function) {

			}
			~SDelegateMetadataClass() {
				target_ = nullptr;
				callback_ = nullptr;
			}
		};

	protected:
		std::vector<SDelegateMetadata<t_type(t_args...)>*> clients_;

	public:
		void join(t_type(*func)(t_args...)) {
			clients_.push_back(new SDelegateMetadataMethod<t_type(t_args...)>(func));
		}

		template<typename t_targ>
		void join(t_targ* target, t_type(t_targ::* func)(t_args...)) {
			clients_.push_back(new SDelegateMetadataClass<t_targ, t_type(t_args...)>(target, func));
		}

		void invoke(const t_args&... in_args) {
			for (auto& client : clients_) {
				if (client->is_valid()) {
					continue;
				}
				client->invoke(in_args...);
			}
		}

		void invoke(std::vector<t_type>& results, const t_args&... in_args) {
			results.clear();
			results.resize(clients_.size());
			int i = 0;
			for (auto& client : clients_) {
				if (client->is_valid()) {
					continue;
				}
				results[i++] = client->invoke(in_args...);
			}
		}

	};

}

#endif