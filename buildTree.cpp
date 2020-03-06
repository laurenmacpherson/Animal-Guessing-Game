#include "binaryTree.h"
#include <cstdlib>
#include <iostream>
#include <string>
/* To this tree, which was provided by the book, I added a last "layer"
of questions so the program could confirm if the animal presented was 
correct or not- if it wasn't, the program would ask questions to add a 
new animal to the list.
*/
BinaryTree buildTree() 
{
	BinaryTree question_tree(
	  BinaryTree("Is it a mammal?", "initialization",
		BinaryTree("Does it have stripes?", "none",
		  BinaryTree("Is it a carnivore?", "none",
			BinaryTree("It is a tiger.", "none",
			  BinaryTree("Thank you for playing!","tiger"),
			  BinaryTree("What kind of animal is it: ","new")),
			BinaryTree("It is a zebra.", "none",
			  BinaryTree("Thank you for playing!","zebra"),
			  BinaryTree("What kind of animal is it:","new"))),
		  BinaryTree("Is it a pig.","none",
			BinaryTree("Thank you for playing!","pig"),
			BinaryTree("What kind of animal is it:","new"))),
			/* \newpage*/
		BinaryTree("Does it fly?", "none",
		  BinaryTree("It is an eagle.", "none",
			BinaryTree("Thank you for playing!", "eagle"),
			BinaryTree("What kind of animal is it:","new")),
		  BinaryTree("Does it swim?", "none",
			BinaryTree("It is a penguin.", "none",
			  BinaryTree("Thank you for playing!", "penguin"),
			  BinaryTree("What kind of animal is it:","new")),
			BinaryTree("It is an ostrich.", "ostrich",
			  BinaryTree("Thank you for playing!", "ostrich"),
			  BinaryTree("What kind of animal is it:","new"))))));
	return question_tree;
}
