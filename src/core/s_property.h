//s_property.h
//define property for stapler_engine

#include "s_object.h"

#ifndef S_PROPERTY_H
#define S_PROPERTY_H
namespace stapler_engine
{
	template<typename t_type = int>
	class DLLAPI_SE SProperty :public SObject
	{
	protected:
		//the value of property
		t_type value;

	public:
		//get value
		virtual inline const t_type& get() { return value; };
		//set value
		virtual inline SProperty<t_type>& set(const t_type& in_arg) { value = in_arg; return *this; };

		inline const t_type& operator()() { return get(); };

		inline SProperty<t_type>& operator=(const t_type& in_arg) { return set(in_arg); };

	public:
		//init property using value
		SProperty(const t_type& in_arg) { set(in_arg); };
		//move value into property
		SProperty(t_type&& in_arg) { set(in_arg); };

	public:
		SProperty(const SProperty&) = delete;
		SProperty& operator=(const SProperty&) = delete;
	};

}

#endif