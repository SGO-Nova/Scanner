#include <iostream>
#include <fstream>
#include <stdio.h>
#include <cstring>

#define MAX_CHAR 1000

using namespace std;

struct tree_Node{
	char character;       //current state character ie. state 12's character is '='
	char state;           //current state's name
	int terminator;       //a int/boolean (0 or 1) to determine if it is a terminator character to know if it can allow a space/tab/newline as the next character
	tree_Node *child;     //a single child for Node x
	tree_Node *sibling;   //another child for Node x
};

struct saved_token{
	char token;           //name of the token
	saved_token *next;    //next token for the file
};

struct current_token{
	int token;           //the character for the token(ASCII value)
	current_token *next;  //the next character for the token.
};

struct tree_Node *start_tree, *current_tree;
struct saved_token *start_saved, *current_saved;
struct current_token *start_current, *current_current;

void Reading_file(char *file);
void Interpreter(char character);

int main(int argc, char *argv[]){
	FILE *fp;
	fp = fopen(argv[argc - 1], "r");
	char filename[MAX_CHAR];
	

	if(fp == NULL){
		cout << "Unable to open the file designated: " << argv[argc-1] << endl;
		cout << "Ending Program" << endl;
		return 1;
	}
	else{
		Reading_file(argv[argc-1]);
	}
	
	//for later use when printing out the tokens
	
	/* 
	current_saved = start_saved;
	while(current_saved != NULL){
		cout << current_saved -> token;
		if(current_saved -> next != NULL){
			cout << ", ";
		}
	}
	*/
	return 0;
}

void Reading_file(char *file){
	char str[MAX_CHAR];
	FILE *fp;
	fp = fopen(file, "r");
	
	while(fgets(str, MAX_CHAR, fp) != NULL){
		for(int i = 0; i < strlen(str); i++){
			Interpreter(str[i]);
		}
	}
}

void Interpreter(char character){
	if((int)character == 32)
		cout << "space" << endl;
	else if((int)character == 10)
		cout << "newline" << endl;
	else if((int)character == 9)
		cout << "tab" << endl;
	else if((int)character >= 48 && (int)character <= 57)
		cout << "number" << endl;
	else if((int)character >= 65 && (int)character <= 90 || (int)character >= 97 && (int)character <= 122)
		cout << "letter" << endl;
	else
		cout << "some other symbol" << endl;
}
