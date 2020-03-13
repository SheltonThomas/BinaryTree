|Shelton Thomas|
|----|
|s198053|
|Code Design and Data Structures|
|Asteroid Survival Game|

## I. Requirements

1. Description of Problem
    - **Name**: Code Design and Data Structures

    - **Problem Statement**: Create a double-linked list, binary tree, and hash function.

    - **Problem Specifications**: Successful creation of a project that emplements and demonstrated a double-linked list, binary tree, and a hash function.

## II. Design

1. Object Information:

    **Name**: Binary Tree:

    **File**: BinaryTree.h

    Description: Class for the binary tree.

    **Attributes**:

        Name: BinaryTree
            Description: Constructor for the binary tree class.
            Visibility: public

        Name: ~BinaryTree
            Description: Deconstructor for the binary tree class.
            Visibility: public

        Name: isEmpty
            Description: Used to see if the binary tree is empty.
            Type: bool
            Visibility: public

        Name: insert
            Description: Used to insert a node to the binary tree.
            Type: void
            Visibility: public
            Params: int

        Name: remove
            Description: Used to remove a node to the binary tree.
            Type: void
            Visibility: public
            Params: int

        Name: findNode
            Description: Used to find a node in a binary tree.
            Type: TreeNode*
            Visibility: public
            Params: int

        Name: findNode
            Description: Used to find a node in a binary tree and set a parent node and current node for use later.
            Type: bool
            Visibility: private
            Params: int, TreeNode**, TreeNode**

        Name: draw
            Description: Used to draw a node.
            Type: void
            Visibility: private
            Params: TreeNode*, int, int, int, TreeNode*

        Name: m_pRoot
            Description: Used to keep track of the current node for drawing.
            Type: TreeNode*
            Visibility: private

    **File**: TreeNode.h

    Description: Used for the information of the binary tree.

    **Attributes**:

        Name: TreeNode
            Description: Constructor for the TreeNode class.
            Visibility: public
            Params: int

        Name: ~TreeNode
            Description: Deconstructor for the TreeNode class.
            Visibility: public

        Name: hasLeft
            Description: Used to keep track of the the left item of a node.
            Visibility: public

        Name: hasRight
            Description: Used to keep track of the the right item of a node.
            Visibility: public

        Name: getData
            Description: Used to get the data in a node.
            Type: int
            Visibility: public

        Name: getLeft
            Description: Used to get the left of a node.
            Type: TreeNode*
            Visibility: public

        Name: getRight
            Description: Used to get the right node of a node.
            Type: TreeNode*
            Visibility: public

        Name: setData
            Description: Used to set the data of a node.
            Type: void
            Visibility: public
            Params: int

        Name: setLeft
            Description: Used to set the the left node of a node.
            Type: void
            Visibility: public
            Params: TreeNode*

        Name: setRight
            Description: Used to set the the right node of a node.
            Type: void
            Visibility: public
            Params: TreeNode*

        Name: draw
            Description: Used to draw a node on the screen.
            Type: void
            Visibility: public

        Name: m_value
            Description: Used to hold the value of a node.
            Type: Iterator
            Visibility: public

        Name: m_left
            Description: Holds the left node of the node.
            Type: TreeNode*
            Visibility: public

        Name: m_right
            Description: Holds the right node of the node.
            Type: TreeNode*
            Visibility: public
            
            
## License

MIT License - Copyright (c) 2018 Academy of Interactive Entertainment

For more information, see the [license][lic] file.

Third party works are attributed under [thirdparty.md][3p].

[lic]:license.md
[3p]:thirdparty.md
[raylib]:https://github.com/raysan5/raylib
