/* \fbox{These functions were primarily taken from the book.} */
#ifndef BINARY_TREE_H
#define BINARY_TREE_H
#include <string>

using namespace std;

class Node
{
	public:
	
		string data;
		string animal;
		Node* left;
		Node* right;
		friend class BinaryTree;   

};

/*
\newpage   
A binary tree in which each node has two children.*/
class BinaryTree
{
	public:
	
/*	Constructs an empty tree.   */
		BinaryTree();
/********************************************************/
/*	Constructs a tree with one node and no children. */
		BinaryTree(string root_data, string root_animal);	
/********************************************************/
/* Constructs a binary tree. */
		BinaryTree(string root_data, string root_animal, BinaryTree left, BinaryTree right);
/* root data is the data for the root, left the left subtree
right the right subtree */
		
/********************************************************/
/*	Returns the height of this tree. */
		int height() const; 
		
/********************************************************/
/* Checks whether this tree is empty.*/
		bool empty() const;	
	
/********************************************************/
		
/* 
\newpage
Gets the data at the root of this tree. */
		string data() const;	/* return the root data */
		string animal() const;  
/* here I added the string "animal", which I will use in 
my gif search in lab.cpp */
		
/********************************************************/
/* Gets the left subtree of this tree. */
		BinaryTree left() const;	
		
/********************************************************/
/* Gets the right subtree of this tree. */
		BinaryTree right() const;

		Node* root;
/********************************************************/
	private:	
/* Returns the height of the subtree whose root is the given node. */
		int height(const Node* n) const;
/* param n a node or nullptr return the height of the subtree, 
or 0 if n is nullptr */		
};

#endif
