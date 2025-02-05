// connector.h
#ifndef SE_CONNECTOR_H
#define SE_CONNECTOR_H

#include "object.h"

#include <vector>

namespace stapler_engine
{
	class Connector :public Object
	{
	protected:
		std::vector<Object>* children;
		Object* parent;
	public:
		void add_child_(Object*);
		Object* get_child_() const;
		Object* get_parent_() const;
		std::vector<Object*> get_children();
		Connector();
	};
}

#endif