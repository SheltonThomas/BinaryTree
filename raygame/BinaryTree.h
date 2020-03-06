#pragma once
#include "Treenode.h"

class BinaryTree
{
public:
	BinaryTree();
	~BinaryTree();

	bool isEmpty() const;
	void insert(int a_nvValue);
	void remove(int a_nvValue);
	TreeNode* findNode(int a_nValue);

	void draw(TreeNode* selected = nullptr);

private:
	bool findNode(int a_nSearchValue, TreeNode** ppOutNode, TreeNode** ppOutParent);

	void draw(TreeNode* pNode, int x, int y, int horizontalSpacing, TreeNode* selected = nullptr);

	TreeNode* m_pRoot;
};

