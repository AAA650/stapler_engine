//
#ifndef SE_STRUCTURE_BASE_H
#define SE_STRUCTURE_BASE_H

#include "../s_object.h"
#include <vector>
#include <string>

typedef unsigned int NodeIndex;

namespace stapler_engine::node {
	class DLLAPI_SE Node :public SObject {
	protected:
		Node* parent;
		std::vector<Node*> children;
		char* name;
		void set_name_(char* name);
	public:
		//Add a child
		virtual void add_child_(Node* child);
		//Add a vector of children
		virtual void add_children_(std::vector<Node*>* children);
		//Get child by index
		virtual Node* get_child_(unsigned int index) const;
		//Get child index by name
		virtual Node* get_child_(char* name) const;
		//Earse child by pointer (same as: children.earse();)
		virtual void erase_child_(Node* node);
		//Get name
		virtual char* get_name_() const;
		//Get a vector of children
		virtual std::vector<Node*> get_children_() const;
		//Get the child's parent
		virtual Node* get_parent_() const;
		virtual void destory_();
		Node(char* name);
		Node(Node* child, char* name);
		Node(std::vector<Node*>* children, char* name);
	protected:
		~Node();
	};
}

#endif