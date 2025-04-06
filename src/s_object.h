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
		SObject();
		virtual ~SObject();
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