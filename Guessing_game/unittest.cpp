/*
\fbox{Unit testing each BinaryTree member function using Catch2.}
*/
#include <iostream>
#include "catch.hpp"
#include "binaryTree.h"    
BinaryTree buildTree();

#ifdef UNIT_TEST
TEST_CASE( "Tests" ){
	SECTION("First Constructor")
	{
		BinaryTree newTree;
		CHECK(newTree.root == nullptr);	
	}
/*This just constructs an empty tree, so we only need to check for nullptr */

	SECTION("Second Constructor")
	{
		BinaryTree newTree("Is this your question?", "animal");
		CHECK(newTree.data() == "Is this your question?");
		CHECK(newTree.animal() == "animal");
	}
/* This function initializes with data values- I tested for both data 
(which the function started with) and animal (which I added on my own)*/
/* \newpage */
	SECTION("Third Constructor")
	{
		BinaryTree left; BinaryTree right;
		BinaryTree thirdTree("Question?", "animal", left, right);
		CHECK(thirdTree.data()== "Question?");
		CHECK(thirdTree.animal()== "animal");
		CHECK(left.empty()); CHECK(right.empty());
	}
/* This function checks that the data values are correct and that there 
are empty branches both "left" and "right"*/
	
	SECTION("Height")
	{
		BinaryTree testTree = buildTree();
		CHECK(testTree.height() == 5);
	}
/*As I extended the tree with a new batch of leaves, my initial tree is 
a height of 5 rather than the 4 the tree the book had.*/	
	
	SECTION("Empty")
	{
		BinaryTree emptyTree;
		CHECK(emptyTree.empty() == true);
	}
/* Checks that the tree is empty. */
/* \newpage */
	SECTION("Data")
	{
		BinaryTree dataTree = buildTree();
		CHECK(dataTree.data() == "Is it a mammal?");
		CHECK(dataTree.animal() == "initialization");	
	}
/* This checks the data from buildTree itself. The first question is of 
course "Is it a mammal?" while I set the first 'animal' string to 
"initialization" to distinguish it.*/

	SECTION("Left")
	{
		BinaryTree testTree = buildTree();
		BinaryTree leftTree = testTree.left();
		CHECK(leftTree.root == testTree.root->left);
	}
/*This in essence reverses the steps of the "left" function for binary 
tree (which sets the root of the tree to "root->left")*/

		SECTION("Right")
	{
		BinaryTree testTree = buildTree();
		BinaryTree rightTree = testTree.right();
		CHECK(rightTree.root == testTree.root->right);
	}
/*This is the same as the left function, but for the right side.*/
}
#endif
