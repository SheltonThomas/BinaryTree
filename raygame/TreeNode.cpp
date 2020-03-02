#include "Treenode.h"

TreeNode::~TreeNode()
{
}

void TreeNode::draw(int x, int y, bool selected)
{
	static char buffer[10];

	Color color = YELLOW;

	sprintf_s(buffer, "%d", m_value);

	DrawCircle(x, y, 30, color);

	if (selected) color = BLUE;
	else color = BLACK;

	DrawCircle(x, y, 28, color);

	DrawText(buffer, x - 12, y - 10, 20, WHITE);
}
