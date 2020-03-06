#include <cstdlib>
#include <iostream>
#include <fstream>
#include <config.h>
#include <curl/curl.h>
#include <FL/Fl_Cairo_Window.H>
#include <FL/Fl_Value_Input.H>
#include <FL/Fl_GIF_Image.H>
#include <FL/Fl_Box.H>
#include <FL/fl_ask.H>
#include "binaryTree.h"

const int WIDTH = 300; const int HEIGHT = 300;

std::string getImageURL(std::string);
void getImage(std::string k);

std::string parseJson(std::string j);
BinaryTree buildTree();
void preOrder(std::ofstream& o, BinaryTree bt);

std::string new_animal;
std::string new_question;

void readFile(std::ifstream& i, BinaryTree bt, Node*& newnode);
/* \newpage */
int main()
{
	BinaryTree question_tree = buildTree();
	std::ofstream ofs("animalsChoice");
	
	preOrder(ofs, question_tree);
	
	bool done = false;
	
/* This is where my "animal" string variable comes into use- with an
animal of "new", the program knows to ask the user for the name of a
new animal and question.*/
	while (!done)
	{
		BinaryTree left = question_tree.left();
		BinaryTree right = question_tree.right();

		if (left.empty() && right.empty())
		{
			if (question_tree.animal() == "new") {
				new_animal = fl_input(
						"Enter new animal: ");
				new_question = fl_input(
						"Enter a question where 'yes' applies to this animal and 'no' applies to the last animal mentioned: ");
						
				    std::string s = getImageURL(new_animal()); 
					s = parseJson(s);
					std::cout << s << std::endl;
					std::cout << "The animal was a(n)" << new_animal << "." << std::endl;
					
					
			}
			else {
				std::cout << question_tree.data() << std::endl;
				std::cout << "The animal was a(n)" << question_tree.animal() << "." << std::endl;
				done = true;
			}
			//done = true;
		}
		
		else 
		{
			std::string question = question_tree.data();
			const char *c = question.c_str();
			
			switch( fl_choice(c, "Yes", "No", 0) )
			{
				case 0:
					{
						std::cout << "Yes" << std::endl; 
						question_tree = left;
						break;
					}	//yes
				case 1:
					{
						std::cout << "No" << std::endl; 
						question_tree = right;
						break;
					}	//No
			}
		}
	}

    std::string s = getImageURL(question_tree.animal()); 
	s = parseJson(s);
    std::cout << s << std::endl;

    Fl_Cairo_Window cw(WIDTH, HEIGHT);
    Fl_Box b(10, 10, WIDTH, HEIGHT);
    
	getImage(s);
    
    /* go get the file returned by getImageURL store in a file */

    Fl_GIF_Image i("animal.gif");
    b.image(&i);

    cw.show();

    return Fl::run();
}
