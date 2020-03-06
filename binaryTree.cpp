/* \fbox{The following functions are from the book.} */
#include <algorithm>
#include "binaryTree.h"
using namespace std;

BinaryTree::BinaryTree()
{
	root = nullptr;
} 

BinaryTree::BinaryTree(string root_data, string root_animal) 
{
	root = new Node;
	root->data = root_data;
	root->animal = root_animal;
	root->left = nullptr;
	root->right = nullptr;
}

BinaryTree::BinaryTree(string root_data, string root_animal, BinaryTree left, BinaryTree right)
{
	root = new Node;
	root->data = root_data;
	root->animal = root_animal;
	root->left = left.root;
	root->right = right.root;
}
/* \newpage */
int BinaryTree::height(const Node* n) const
{
	if (n == nullptr) { return 0; }
	else { return 1 + max(height(n->left), height(n->right)); }
}

int BinaryTree::height() const 
{ 
	return height(root); 
}

bool BinaryTree::empty() const 
{ 
	return root == nullptr; 
}

string BinaryTree::data() const 
{ 
	return root->data; 
}

string BinaryTree::animal() const 
{ 
	return root->animal; 
}
/* \newpage */
BinaryTree BinaryTree::left() const
{ 
	BinaryTree result;
	result.root = root->left; 
	return result;
}

BinaryTree BinaryTree::right() const
{ 
	BinaryTree result;
	result.root = root->right; 
	return result;
}
