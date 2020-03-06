/* These were the functions I was going to use to add the new 
animals/questions as well as read from the animalsChoice file to create
another tree. It does not work and is not linked to the program.*/

#include <fstream>
#include <iostream>
#include <string>
#include "binaryTree.h"

using namespace std;

void readFile(std::ifstream& i, BinaryTree bt)
{
	fstream file;	
	file.open("animalChoice.txt");	//opens file to read
} 
/* \newpage */
void addNode(Node* root, string choices, int length, string data, string animal)
{
    Node* top = root; 
    int i = 0;
    while (i < length){

/*for these if statements, I was intending to check for something in the
lines that indicated whether the last choice was yes or no, or left or 
right.*/
        if(choices[i] == ''){	
            root = root->left;
        }
        if(choices[i] == ''){
            root = root->right;
        }
        i++;
    }
    Node* newnode = new Node;
    newnode->data = data; newnode->animal = animal;
    root = newnode;		//add recursive function?
}

