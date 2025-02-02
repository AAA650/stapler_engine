// connector.h
#ifndef CONNECTOR_H
#define CONNECTOR_H

#include <vector>

namespace stapler_engine
{
	class Connector :public Object
	{
	protected:
		std::vector<Object>* children;
		Object* parent;
	public:
		void add_(Object*);
		std::vector<Object*> get_children();
		Connector();
	};
}

#endif