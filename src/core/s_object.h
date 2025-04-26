// s_object.h
// basic class for all se-based objects 

#ifndef S_OBJECT_H
#define S_OBJECT_H

#include "s_config.h"

namespace stapler_engine 
{
	class DLLAPI_SE SObject
	{

	public:
		//Stapler engine main function
		static void se_main();

	public:
		SObject();
		virtual ~SObject();
	};

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