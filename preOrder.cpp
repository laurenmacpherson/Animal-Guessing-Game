#include <fstream>
#include <iostream>
#include <string>
#include "binaryTree.h"
/*This code was provided in class to output the binary tree to our output file.*/
using namespace std;

void preOrder(std::ofstream& o, BinaryTree bt)
{
	if (bt.empty())
	{
		return;
	}
	
	o << bt.data() << std::endl;
	
	preOrder(o, bt.left());
	
	preOrder(o, bt.right());
	
}
