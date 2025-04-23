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
		t_type value;
	public:
		virtual inline t_type get() { return value; };
		virtual inline t_type set(t_type& in_arg) { value = *in_arg; return value; };
		inline t_type operator()() { return get(); };
		inline t_type operator=(t_type& in_arg) { return set(in_arg); };
		
	public:
		SAttribute(const t_type& in_arg) { set(in_arg); };
		SAttribute(t_type&& in_arg) { set(in_arg); };

	public:
		SAttribute(const SAttribute&) = delete;
		SAttribute& operator=(const SAttribute&) = delete;
	};
}
#endif