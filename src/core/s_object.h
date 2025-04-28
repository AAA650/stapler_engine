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
		SObject();
		virtual ~SObject();
	};

}
#endif