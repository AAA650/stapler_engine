//object.h
#ifndef SE_OBJECT_H
#define SE_OBJECT_H
#include "../dll_config.h"
namespace stapler_engine 
{
	class DLLAPI_SE Object
	{
	public:
		//Stapler engine main function
		static void se_main();
	protected:
		Object* child;
		Object* parent;
	public:
		void add_child_(Object*);
		Object* get_child_() const;
		Object* get_parent_() const;
		Object();
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