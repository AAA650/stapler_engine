// s_node_base.cpp
// implement of SNode

#include "s_node_base.h"

namespace stapler_engine::node
{
	DLLAPI_SE void SNode::set_name(tchar* name_arg)
	{
		// if name is nullptr, throw exception
		if (name_arg == nullptr)
			throw("SNode: Cannot use nullptr");

		// if name is empty, throw exception
		if (tstrcmp(name_arg, L"") == 0)
			throw("SNode: Cannot use empty name_");

		// write name
		*name_ = name_arg;
	}

	DLLAPI_SE void SNode::set_parent(SNode* parent_node)
	{
		// if arg is nullptr, throw exception
		if (parent_node == nullptr)
			throw("SNode: Cannot use nullptr as parent_.");

		// if its parent is already the arg, return
		if (parent_node == parent_)
			return;

		// if have a parent before, remove it from its brothers
		if (parent_ != nullptr) {
			// get brothers
			auto brothers = parent_->children_;
			// find itself, and then erase itself
			for (auto it = brothers->begin(); it != brothers->end(); it++) {
				if (*it == this) {
					brothers->erase(it);
					break;
				}
			}
		}

		// set current parent
		parent_ = parent_node;

		// add into brothers
		parent_->children_->push_back(this);
	}

	DLLAPI_SE void SNode::erase_parent()
	{
		// if have a parent before, remove it from its brothers
		if (parent_ != nullptr) {
			// get brothers
			auto& brothers = parent_->children_;
			// find itself, and then erase itself
			for (auto it = brothers->begin(); it != brothers->end(); it++) {
				if (*it == this) {
					brothers->erase(it);
					break;
				}
			}
		}

		// set parent to nullptr
		parent_ = nullptr;
	}

	DLLAPI_SE SNode* SNode::get_child(SNodeIndex index) const noexcept
	{
		// if is in vector, return the ptr
		if (index < children_->size())
			return (*children_)[index];

		// else return nullptr
		return nullptr;
	}

	DLLAPI_SE SNode* SNode::get_child(char* name_) const noexcept
	{
		// if find a name as same as the arg, return it
		for (auto it = children_->begin(); it != children_->end(); it++) {
			if ((*it)->name_ == this->name_)
				return *it;
		}

		// else return nullptr
		return nullptr;
	}

	DLLAPI_SE const tchar* SNode::get_name() const
	{
		return name_->c_str();
	}

	DLLAPI_SE const std::vector<SNode*>* SNode::get_children() const
	{
		return children_;
	}

	DLLAPI_SE SNode* SNode::get_parent() const
	{
		return parent_;
	}

	DLLAPI_SE void SNode::destory()
	{
		delete this;
	}

	SNode::SNode(SNode* parent_node)
	{
		try {
			set_parent(parent_node);
			children_ = new std::vector<SNode*>;
		}
		catch (std::exception ex) {
			destory();
			throw ex;
		}
	}

	SNode::SNode(tchar* name_arg, SNode* parent_node) {
		try {
			set_name(name_arg);
			set_parent(parent_node);
			children_ = new std::vector<SNode*>;
		}
		catch (std::exception ex) {
			destory();
			throw ex;
		}
	}

	SNode::~SNode() {
		for (auto it = children_->begin(); it != children_->end(); it++) {
			if ((*it) != nullptr)
				delete* it;
		}
		erase_parent();
		delete children_;
	}

}