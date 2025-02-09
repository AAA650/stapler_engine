//
#ifndef SE_STRUCTURE_BASE_H
#define SE_STRUCTURE_BASE_H

#include "../object/object.h"
#include <vector>

namespace stapler_engine::node {
	class DLLAPI_SE Node :public Object {
	protected:
		Node* parent;
		std::vector<Node*> children;
	public:
		virtual void add_child_(Node* child);
		virtual void add_children_(std::vector<Node*>* children);
		virtual Node* get_child_(unsigned int index) const;
		virtual std::vector<Node*> get_children_() const;
		virtual Node* get_parent_() const;
		virtual void destory_();
		Node();
		Node(Node* child);
		Node(std::vector<Node*>* children);
	protected:
		~Node();
	};
}

#endif