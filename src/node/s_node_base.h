//
#ifndef S_NODE_BAS_H
#define S_NODE_BAS_H

#include "../s_object.h"
#include <vector>
#include <string>

typedef unsigned int SNodeIndex;

namespace stapler_engine::node {
	class DLLAPI_SE SNode :public SObject {
	protected:
		// using this can make a tree structure
		SNode* parent_;
		std::vector<SNode*> children_;

		// name of SNode
		tstring name_;

	public:
		//Set name
		void set_name_(tchar* name_);

		//Add parent
		virtual void set_parent_(SNode* parent);

		//Disconnect this and its parent
		virtual void erase_parent_();

		//Get child by index
		virtual SNode* get_child_(SNodeIndex index) const noexcept;

		//Get child index by name
		virtual SNode* get_child_(char* name) const noexcept;

		//Get name
		virtual tstring get_name_() const;

		//Get a vector of children
		virtual std::vector<SNode*> get_children_() const;

		//Get the child's parent
		virtual SNode* get_parent_() const;

		virtual void destory_();

		SNode(SNode* parent = nullptr);

		SNode(tchar* name, SNode* parent = nullptr);
	protected:
		~SNode();
	};
}

#endif