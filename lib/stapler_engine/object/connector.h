// connector.h
#ifndef CONNECTOR_H
#define CONNECTOR_H

#include <vector>

namespace stapler_engine
{
	class Connector :public Object
	{
	protected:
		std::vector<Object>* children_list;
	public:
		void add_(Object);
		Connector();
	};
}

#endif