#include "BinaryTree.h"



BinaryTree::BinaryTree()
{
}


BinaryTree::~BinaryTree()
{
}

bool BinaryTree::isEmpty() const
{
	if (m_pRoot == nullptr) return true;
	return false;
}

void BinaryTree::insert(int a_nValue)
{
	if (m_pRoot == nullptr) m_pRoot = new TreeNode(a_nValue);

	TreeNode* currentNode = m_pRoot;
	TreeNode* previousNode = nullptr;

	while (currentNode != nullptr)
	{
		if (a_nValue < currentNode->getData())
		{
			previousNode = currentNode;
			currentNode = currentNode->getLeft();
		}
		if (a_nValue > currentNode->getData())
		{
			previousNode = currentNode;
			currentNode = currentNode->getRight();
		}
		else return;
	}

	currentNode = previousNode;

	if (a_nValue < currentNode->getData())
	{
		TreeNode* newNode = new TreeNode(a_nValue);
		currentNode->setLeft(newNode);
	}

	if (a_nValue > currentNode->getData())
	{
		TreeNode* newNode = new TreeNode(a_nValue);
		currentNode->setRight(newNode);
	}
}

void BinaryTree::draw(TreeNode * selected)
{
	draw(m_pRoot, 640, 680, 640, selected);
}

void BinaryTree::draw(TreeNode * pNode, int x, int y, int horizontalSpacing, TreeNode * selected)
{
	horizontalSpacing /= 2;

	if (pNode) {
		if (pNode->hasLeft())
		{
			DrawLine(x, y, x - horizontalSpacing, y - 80, RED);
			draw(pNode->getLeft(), x - horizontalSpacing, y - 80, horizontalSpacing, selected);
		}
		if (pNode->hasRight())
		{
			DrawLine(x, y, x - horizontalSpacing, y - 80, RED);
			draw(pNode->getRight(), x - horizontalSpacing, y - 80, horizontalSpacing, selected);
		}
		pNode->draw(x, y, (selected == pNode));
	}
}
