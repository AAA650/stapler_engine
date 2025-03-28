//s_object.h
#ifndef SE_OBJECT_H
#define SE_OBJECT_H
#include "dll_config.h"
namespace stapler_engine 
{
	class DLLAPI_SE SObject
	{
	public:
		//Stapler engine main function
		static void se_main();
		SObject();
	};

	template<typename Tdata>
	class Attribute
	{
	public:
		virtual void get_(Tdata) = 0;
		virtual Tdata set_() = 0;
	};
}
#endif