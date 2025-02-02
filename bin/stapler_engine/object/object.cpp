// object.cpp
#include "../../../lib/stapler_engine/object/object.h"

namespace stapler_engine
{
	DLLAPI_SE void Object::se_main()
	{
		return;
	}

	DLLAPI_SE void Object::add_child_(Object* arg)
	{
		if (child != nullptr)
		{
			child->parent = nullptr;
		};
		child = arg;
		child->parent = this;
	}

	DLLAPI_SE Object* Object::get_child_() const
	{
		return child;
	}

	DLLAPI_SE Object* Object::get_parent_() const
	{
		return parent;
	}

	Object::Object()
	{
		child = nullptr;
		parent = nullptr;
	}
}