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
		public:
			template<typename t_type,typename... t_args>
			t_type invoke(const t_args&... in_args) = 0;

			virtual bool is_class() = 0;
		};

		// delegate metadata
		// metadata for 
		template<typename E> class SDelegateMetadataMethod;
		template<typename t_type,typename... t_args>
		class DLLAPI_SE SDelegateMetadataMethod<t_type(t_args...)> : public SDelegateContainer
		{
		private:
			void* target_;
			t_type(*function_)(t_args...);

		public:
			t_type invoke(const t_args&... in_args) override {
				return function_(in_args...);
			}

			virtual bool is_class() {
				return false;
			}

		public:
			SDelegateMetadataMethod(t_type(*in_function)(t_args...), void* in_target = nullptr)
				: target_(in_target), function_(in_function) {
			}
			~SDelegateMetadataMethod() {
				target_ = nullptr;
				function_ = nullptr;
			}
		};

		template<typename T,typename E> class SDelegateMetadataClass;
		template<typename t_targ,typename t_type, typename... t_args>
		class DLLAPI_SE SDelegateMetadataClass<t_targ,t_type(t_args...)> : public SDelegateContainer
		{
		private:
			t_targ* target_;
			t_type(t_targ::* function_)(t_args...);

		public:
			t_type invoke(const t_args&... in_args) override {
				return (target_->function_)(in_args...);
			}

			virtual bool is_class() {
				return true;
			}

		public:
			SDelegateMetadataClass(t_type(t_targ::* in_function)(t_args...), t_targ* in_target)
				: target_(in_target), function_(in_function) {
			}
			~SDelegateMetadataClass() {
				target_ = nullptr;
				function_ = nullptr;
			}
		};

	protected:
		// clients of delegate
		std::vector<SDelegateContainer*> clients_;
	public:
		/*
		template<typename T, typename E> void join();
		template<typename t_targ,typename t_type,typename... t_args>
		void join<t_targ, t_type(t_args...)>(t_type(*in_function)(t_args...), t_targ* in_target = nullptr) {
			clients_.push_back(new SDelegateMetadataMethod<t_type(t_args...)>(in_function, in_target));
		}
		*/
	};
}

#endif