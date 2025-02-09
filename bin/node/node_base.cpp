//
#include "../../lib/node/node_base.h"

namespace stapler_engine::node {
	DLLAPI_SE void Node::add_child_(Node* node) {
		if (node == nullptr)
			return;
		node->parent = this;
		children.push_back(node);
	}

	DLLAPI_SE void Node::add_children_(std::vector<Node*>* nodes) {
		for (auto it = nodes->begin(); it != nodes->end(); it++) {
			(*it)->parent = this;
		}
		children.insert(children.end(), nodes->begin(), nodes->end());
	}

	DLLAPI_SE Node* Node::get_child_(unsigned int index) const {
		return children[index];
	}

	DLLAPI_SE std::vector<Node*> Node::get_children_() const {
		return children;
	}

	DLLAPI_SE Node* Node::get_parent_() const {
		return parent;
	}

	DLLAPI_SE void Node::destory_() {
		delete this;
	}

	Node::Node() {
		parent = nullptr;
		children = std::vector<Node*>();
	}

	Node::Node(Node* node) {
		add_child_(node);
	}

	Node::Node(std::vector<Node*>* nodes) {
		add_children_(nodes);
	}

	Node::~Node() {
		for (auto it = children.begin(); it != children.end(); it++) {
			delete* it;
		}
		parent = nullptr;
	}

}