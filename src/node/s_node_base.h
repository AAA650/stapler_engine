//
#ifndef S_NODE_BAS_H
#define S_NODE_BAS_H

#include "../core/s_object.h"
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
		void set_name(tchar* name_);

		//Add parent
		virtual void set_parent(SNode* parent);

		//Disconnect this and its parent
		virtual void erase_parent();

		//Get child by index
		virtual SNode* get_child(SNodeIndex index) const noexcept;

		//Get child index by name
		virtual SNode* get_child(char* name) const noexcept;

		//Get name
		virtual tstring get_name() const;

		//Get a vector of children
		virtual std::vector<SNode*> get_children() const;

		//Get the child's parent
		virtual SNode* get_parent() const;

		virtual void destory();

		SNode(SNode* parent = nullptr);

		SNode(tchar* name, SNode* parent = nullptr);
	protected:
		~SNode();
	};
}

#endif