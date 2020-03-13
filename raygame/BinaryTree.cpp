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
		previousNode = nodeToDelete;

		while (currentNode->hasLeft())
		{
			previousNode = currentNode;
			currentNode = currentNode->getLeft();
		}
		nodeToDelete->setData(currentNode->getData());
		
		if (currentNode == previousNode->getLeft())
		{
			if (currentNode->hasRight())
			{
				previousNode->setLeft(currentNode->getRight());
				delete currentNode;
			}
			else
			{
				previousNode->setLeft(nullptr);
				delete currentNode;
			}
		}

		if (currentNode == previousNode->getRight())
		{
			if (currentNode->hasRight())
			{
				previousNode->setRight(currentNode->getRight());
				delete currentNode;
			}
			else
			{
				previousNode->setRight(nullptr);
				delete currentNode;
			}
		}
	}

	else
	{
		if (nodeToDelete == nodesParent->getLeft())
		{
			if (nodeToDelete->hasRight())
			{
				nodesParent->setLeft(nodeToDelete->getRight());
				delete nodeToDelete;
			}
			else
			{
				nodesParent->setLeft(nullptr);
				delete nodeToDelete;
			}
		}

		if (nodeToDelete == nodesParent->getRight())
		{
			if (nodeToDelete->hasRight())
			{
				nodesParent->setRight(nodeToDelete->getRight());
				delete nodeToDelete;
			}
			else
			{
				nodesParent->setRight(nullptr);
				delete nodeToDelete;
			}
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
			currentNode = currentNode->getLeft();
		}
		else if (a_nValue > currentNode->getData())
		{
			previousNode = currentNode;
			currentNode = currentNode->getRight();
		}
		else
		{
			*ppOutParent = previousNode;
			*ppOutNode = currentNode;
			return true;
		}
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
