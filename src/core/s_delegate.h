// delegate.h
// define delegate
//

#include "s_object.h"
#include <vector>

#ifndef S_DELEGATE_H
#define S_DELEGATE_H

namespace stapler_engine
{
	class DLLAPI_SE SDelegate : public SObject
	{
	protected:
		// delegate container
		// containing functions
		class DLLAPI_SE SDelegateContainer
		{
		protected:
			void* invk_func_;
			friend class SDelegate;

		public:
			template<typename t_type>
			t_type invoke() {
				union {
					t_type(SDelegateContainer::* func)();
					void* func_ptr;
				} conv_u;
				conv_u.func_ptr = invk_func_;
				return (this->*(conv_u.func))();
			}
			template<typename t_type,typename... t_args>
			t_type invoke(const t_args&... in_args) {
				union {
					t_type(SDelegateContainer::*func)(const t_args&...);
					void* func_ptr;
				} conv_u;
				conv_u.func_ptr = invk_func_;
				return (this->*(conv_u.func))(in_args...);
			}

			virtual bool is_class() = 0;

			virtual bool is_valid() = 0;
		};

		// delegate metadata
		// metadata for methods
		template<typename t_func> class SDelegateMetadataMethod;
		template<typename t_type,typename... t_args>
		class DLLAPI_SE SDelegateMetadataMethod<t_type(t_args...)> : public SDelegateContainer
		{
		protected:
			void* target_;
			t_type(*callback_)(t_args...);

		public:
			t_type invoke(const t_args&... in_args) {
				return (*callback_)(in_args...);
			}

			virtual bool is_class() override {
				return false;
			}

			virtual bool is_valid() override {
				return target_ != nullptr && callback_ != nullptr;
			}

		public:
			SDelegateMetadataMethod(t_type(*in_function)(t_args...), void* in_target = nullptr)
				: target_(in_target), callback_(in_function) {
				union {
					t_type(SDelegateMetadataMethod::*func)(const t_args&...);
					void* func_ptr;
				} conv_u;
				conv_u.func = &SDelegateMetadataMethod::invoke;
				invk_func_ = conv_u.func_ptr;
			}
			~SDelegateMetadataMethod() {
				target_ = nullptr;
				callback_ = nullptr;
			}
		};

		//metadata for classes
		template<typename t_targ,typename t_func> class SDelegateMetadataClass;
		template<typename t_targ,typename t_type, typename... t_args>
		class DLLAPI_SE SDelegateMetadataClass<t_targ,t_type(t_args...)> : public SDelegateContainer
		{
		protected:
			t_targ* target_;
			t_type(t_targ::* callback_)(t_args...);

		public:
			t_type invoke(const t_args&... in_args) {
				return (target_->*callback_)(in_args...);
			}

			virtual bool is_class() override {
				return true;
			}

			virtual bool is_valid() override {
				return target_ != nullptr && callback_ != nullptr;
			}

		public:
			SDelegateMetadataClass(t_type(t_targ::* in_function)(t_args...), t_targ* in_target)
				: target_(in_target), callback_(in_function) {
				union {
					t_type(SDelegateMetadataClass::*func)(const t_args&...);
					void* func_ptr;
				} conv_u;
				conv_u.func = &SDelegateMetadataClass::invoke;
				invk_func_ = conv_u.func_ptr;
			}
			~SDelegateMetadataClass() {
				target_ = nullptr;
				callback_ = nullptr;
			}
		};

	protected:
		// clients of delegate
		std::vector<SDelegateContainer*> clients_;

	public:
		//join methods into delegate
		template<typename t_type>
		void join(t_type(*in_method)()) {
			clients_.push_back(new SDelegateMetadataMethod<t_type()>(in_method));
		}
		template<typename t_type, typename... t_args>
		void join(t_type(*in_method)(t_args...)) {
			clients_.push_back(new SDelegateMetadataMethod<t_type(t_args...)>(in_method));
		}
		template<typename t_targ, typename t_type>
		void join(t_type(t_targ::* in_method)(), t_targ* target) {
			clients_.push_back(new SDelegateMetadataClass<t_targ, t_type()>(in_method, target));
		}
		template<typename t_targ, typename t_type, typename... t_args>
		void join(t_type(t_targ::* in_method)(t_args...), t_targ* target) {
			clients_.push_back(new SDelegateMetadataClass<t_targ, t_type(t_args...)>(in_method, target));
		}

		//invoke delegate
		void invoke() {
			for (auto client : clients_) {
				client->invoke<void>();
			}
		}
		template<typename... t_args>
		void invoke(const t_args&... in_args) {
			for (auto client : clients_) {
				client->invoke<void, t_args...>(in_args...);
			}
		}
		template<typename t_type, typename... t_args>
		t_type invoke(int offset, const t_args&... in_args) {
			if (offset < 0 || offset >= clients_.size()) {
				throw std::out_of_range("SDelegate::invoke: offset out of range");
			}
			return clients_[offset]->invoke<t_type, t_args...>(in_args...);
		}


	public:
		SDelegate() {};
		~SDelegate() {
			for (auto client : clients_) {
				delete client;
			}
			clients_.clear();
		}
	};
}

#endif