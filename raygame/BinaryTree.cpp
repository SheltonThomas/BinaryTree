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
		else if (a_nValue > currentNode->getData())
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

void BinaryTree::remove(int a_nvValue)
{
	TreeNode* nodeToDelete = nullptr;
	TreeNode* nodesParent = nullptr;
	TreeNode* currentNode = nullptr;
	TreeNode* previousNode = nullptr;

	if(!findNode(a_nvValue, &nodeToDelete, &nodesParent)) return;

	if (nodeToDelete->hasRight())
	{
		currentNode = nodeToDelete->getRight();
		while (currentNode->hasLeft())
		{
			previousNode = currentNode;
			currentNode = currentNode->getLeft();
		}

		
	}
}

TreeNode* BinaryTree::findNode(int a_nValue)
{
	TreeNode* currentNode = m_pRoot;

	while (currentNode != nullptr)
	{
		if (a_nValue < currentNode->getData())
		{
			currentNode = currentNode->getLeft();
		}
		else if (a_nValue > currentNode->getData())
		{
			currentNode = currentNode->getRight();
		}
		else return currentNode;
	}

	return nullptr;
}

bool BinaryTree::findNode(int a_nValue, TreeNode** ppOutNode, TreeNode** ppOutParent)
{
	TreeNode* currentNode = m_pRoot;
	TreeNode* previousNode = nullptr;

	while (currentNode != nullptr)
	{
		if (a_nValue < currentNode->getData())
		{
			previousNode = currentNode;
			ppOutParent = &previousNode;
			currentNode = currentNode->getLeft();
			ppOutNode = &currentNode;
		}
		else if (a_nValue > currentNode->getData())
		{
			previousNode = currentNode;
			ppOutParent = &previousNode;
			currentNode = currentNode->getRight();
			ppOutNode = &currentNode;
		}
		else return true;
	}

	return false;
}

void BinaryTree::draw(TreeNode * selected)
{
	draw(m_pRoot, 640, 100, 640, selected);
}

void BinaryTree::draw(TreeNode * pNode, int x, int y, int horizontalSpacing, TreeNode * selected)
{
	horizontalSpacing /= 2;

	if (pNode) {
		if (pNode->hasLeft())
		{
			DrawLine(x, y, x - horizontalSpacing, y + 80, RED);
			draw(pNode->getLeft(), x - horizontalSpacing, y + 80, horizontalSpacing, selected);
		}
		if (pNode->hasRight())
		{
			DrawLine(x, y, x + horizontalSpacing, y + 80, RED);
			draw(pNode->getRight(), x + horizontalSpacing, y + 80, horizontalSpacing, selected);
		}
		pNode->draw(x, y, (selected == pNode));
	}
}
