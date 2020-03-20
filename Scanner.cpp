#include <iostream>
#include <fstream>

using namespace std;

struct Node{
	char character;     //current state character ie. state 12's character is '='
	int terminator;     //a int/boolean (0 or 1) to determine if it is a terminator character to know if it can allow a space/tab/newline as the next character
	Node *child;        //a single child for Node x
	Node *sibling;      //another child for Node x
}

struct Node *start, *current;

int main(int argc, char *argv[]){
	ofstream pfile("output.txt");
	
	
	pfile << "Test";
	pfile.close();
	
	return 0;
}