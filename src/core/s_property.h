//s_property.h
//define property for stapler_engine

#include "s_object.h"

#ifndef S_PROPERTY_H
#define S_PROPERTY_H
namespace stapler_engine
{
	template<typename t_type>
	class DLLAPI_SE SProperty :public SObject
	{
	protected:
		//the value of property
		t_type value;

	public:
		//get value
		virtual inline const t_type get() { return value; };
		//set value
		virtual inline void set(const t_type& in_arg) { value = in_arg; };

		inline const t_type operator()() { return get(); };

		inline void operator=(const t_type& in_arg) { set(in_arg); };

	public:
		//init property
		SProperty() {};

	public:
		SProperty(const SProperty&) = delete;
		SProperty& operator=(const SProperty&) = delete;
	};

#define PROPERTY(prop_type, prop_name, prop_get_func, prop_set_func) \
	class :public se::SProperty<prop_type> {\
	public:\
		virtual inline const prop_type get() override prop_get_func;\
		virtual inline void set(const prop_type& in_arg) override prop_set_func;\
	}prop_name;

#define GET { return value; }
#define SET { value = in_arg; }

}

#endif