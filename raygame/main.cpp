/*******************************************************************************************
*
*   raylib [core] example - basic window
*
*   This example has been created using raylib 1.0 (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Copyright (c) 2013-2016 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include <iostream>
#include "raylib.h"
#include "BinaryTree.h"

int main()
{
	// Initialization
	//--------------------------------------------------------------------------------------
	int screenWidth = 1280;
	int screenHeight = 720;

	InitWindow(screenWidth, screenHeight, "YOTE");

	SetTargetFPS(0);
	//--------------------------------------------------------------------------------------

	BinaryTree tree;
	tree.insert(30);
	tree.insert(10);
	tree.insert(17);
	tree.insert(15);
	tree.insert(21);
	tree.insert(7);
	tree.insert(12);
	tree.insert(14);
	tree.insert(17);
	tree.insert(18);
	tree.insert(25);

	tree.remove(14);

	TreeNode* selected = tree.findNode(12);

	// Main game loop
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		// Update
		//----------------------------------------------------------------------------------
		// TODO: Update your variables here
		//----------------------------------------------------------------------------------

		// Draw
		//----------------------------------------------------------------------------------
		BeginDrawing();

		ClearBackground(BLANK);

		//DrawText("BING BING BONG", 190, 200, 20, YELLOW);

		tree.draw();

		EndDrawing();
		//----------------------------------------------------------------------------------
	}

	// De-Initialization
	//--------------------------------------------------------------------------------------   
	CloseWindow();        // Close window and OpenGL context
	//--------------------------------------------------------------------------------------

	return 0;
}
