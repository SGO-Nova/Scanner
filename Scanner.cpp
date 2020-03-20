#include <iostream>
#include <fstream>
#include <stdio.h>
#include <cstring>

using namespace std;

struct Node{
	char character;     //current state character ie. state 12's character is '='
	int terminator;     //a int/boolean (0 or 1) to determine if it is a terminator character to know if it can allow a space/tab/newline as the next character
	Node *child;        //a single child for Node x
	Node *sibling;      //another child for Node x
};

struct Node *start, *current;

int main(int argc, char *argv[]){
	int counter = 0;
	int chars = 100;
	char str[chars];
	FILE *fp;
	fp = fopen(argv[argc - 1], "r");
	

	if(fp == NULL){
		cout << "Unable to open the file designated: " << argv[argc-1] << endl;
		cout << "Ending Program" << endl;
		return 1;
	}
	while(fgets(str, chars, fp) != NULL){
		for(int i = 0; i < strlen(str); i++){
			cout << i << ") " << str[i] << endl;
		}
	}
	fclose(fp);
	
	return 0;
}