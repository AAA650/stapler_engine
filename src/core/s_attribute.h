//s_attribute.h
//define attribute for stapler_engine

#include "s_object.h"

#ifndef S_ATTRIBUTE_H
#define S_ATTRIBUTE_H
namespace stapler_engine
{
	template<typename t_type = void>
	class DLLAPI_SE SAttribute :public SObject
	{
	protected:
		//the value of attribute
		t_type value;

	public:
		//get value
		virtual inline const t_type& get() { return value; };
		//set value
		virtual inline const t_type& set(const t_type& in_arg) { value = *in_arg; return value; };

		inline const t_type& operator()() { return get(); };

		inline const t_type& operator=(const t_type& in_arg) { return set(in_arg); };

	public:
		//init attribute using value
		SAttribute(const t_type& in_arg) { set(in_arg); };
		//move value into attribute
		SAttribute(t_type&& in_arg) { set(in_arg); };

	public:
		SAttribute(const SAttribute&) = delete;
		SAttribute& operator=(const SAttribute&) = delete;
	};

}

#endif