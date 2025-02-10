//
#include "../../lib/node/node_base.h"

namespace stapler_engine::node {

	DLLAPI_SE void Node::set_name_(char* name_arg) {
		if (name_arg == nullptr)
			throw("Node: Cannot use nullptr");
		if (strcmp(name_arg, "") == 0)
			throw("Node: Cannot use empty name");
		name = name_arg;
	}

	DLLAPI_SE void Node::add_child_(Node* node) {
		if (node == nullptr)
			throw std::exception("Node: Cannot use nullptr.");
		for (auto it = children.begin(); it != children.end(); it++) {
			if (*it == node)
				throw std::exception("Node: Already have it.");
			if ((*it)->name == node->name)
				throw std::exception("Node: Cannot use same name.");
		}
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
		if (index < children.size())
			return children[index];
		return nullptr;
	}

	DLLAPI_SE Node* Node::get_child_(char* name) const {
		for (auto it = children.begin(); it != children.end(); it++) {
			if ((*it)->name == name)
				return *it;
		}
		return nullptr;
	}

	DLLAPI_SE void Node::erase_child_(Node* node) {
		for (auto it = children.begin(); it != children.end(); it++) {
			if (*it == node)
				children.erase(it);
		}
	}

	DLLAPI_SE char* Node::get_name_() const {
		return name;
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

	Node::Node(char* name_arg) {
		try {
			set_name_(name_arg);
			parent = nullptr;
			children = std::vector<Node*>();
		}
		catch (std::exception ex) {
			delete this;
			throw ex;
		}
	}

	Node::Node(Node* node ,char* name_arg) {
		try {
			set_name_(name_arg);
			parent = nullptr;
			children = std::vector<Node*>();
			add_child_(node);
		}
		catch (std::exception ex) {
			delete this;
			throw ex;
		}
	}

	Node::Node(std::vector<Node*>* nodes,char* name_arg) {
		try {
			set_name_(name_arg);
			parent = nullptr;
			children = std::vector<Node*>();
			add_children_(nodes);
		}
		catch (std::exception ex) {
			delete this;
			throw ex;
		}
	}

	Node::~Node() {
		for (auto it = children.begin(); it != children.end(); it++) {
			delete* it;
		}
		parent = nullptr;
	}

}