#include <iostream>
#include <fstream>
#include <stdio.h>
#include <cstring>
//#include "Token_Tree.h"

#define MAX_CHAR 1000

using namespace std;

struct tree_Node{
	char name[10];            //current state's name
	int state;                //current state's number
	int terminator;           //a int/boolean (0 or 1) to determine if it is a terminator character to know if it can allow a space/tab/newline as the next character
	tree_Node *child;         //a single child for Node x
	tree_Node *sibling;       //another child for Node x
};

struct saved_token{
	char token;               //name of the token
	saved_token *next;        //next token for the file
};

struct current_token{
	int token;                //the character for the token(ASCII value)
	current_token *next;      //the next character for the token.
};

struct tree_Node *start_tree, *current_tree, *tmp;
struct saved_token *start_saved, *current_saved;
struct current_token *start_current, *current_current;

void Reading_file(char *file);
void Interpreter(char character);
void Tree_Create(int state, char character[10], int terminator);

int main(int argc, char *argv[]){
	char arr_char[10][10] = {" ", "div", "lparen", "rparen", "plus", "minus", "times", "assign", "number", "id"};
	
	Tree_Create(1, arr_char[0], 0);
	tmp = current_tree;
	Tree_Create(2, arr_char[1], 1);
	tmp -> child = current_tree;
	tmp = current_tree;
	Tree_Create(3, arr_char[0], 0);
	tmp -> child = current_tree;
	Tree_Create(4, arr_char[0], 0);
	tmp -> child -> sibling = current_tree;
	tmp = current_tree;
	Tree_Create(5, arr_char[0], 0);
	tmp -> child = current_tree;
	tmp = current_tree;
	Tree_Create(6, arr_char[2], 1);
	start_tree -> child -> sibling = current_tree;
	Tree_Create(7, arr_char[3], 1);
	start_tree -> child -> sibling -> sibling = current_tree;
	Tree_Create(8, arr_char[4], 1);
	start_tree -> child -> sibling -> sibling -> sibling = current_tree;
	Tree_Create(9, arr_char[5], 1);
	start_tree -> child -> sibling -> sibling -> sibling -> sibling = current_tree;
	Tree_Create(10, arr_char[6], 1);
	start_tree -> child -> sibling -> sibling -> sibling -> sibling -> sibling = current_tree;
	Tree_Create(11, arr_char[0], 0);
	start_tree -> child -> sibling -> sibling -> sibling -> sibling -> sibling -> sibling = current_tree;
	tmp = current_tree;
	Tree_Create(12, arr_char[7], 1);
	tmp -> child = current_tree;
	Tree_Create(13, arr_char[0], 0);
	start_tree -> child -> sibling -> sibling -> sibling -> sibling -> sibling -> sibling -> sibling = current_tree;
	tmp = current_tree;
	Tree_Create(14, arr_char[8], 1);
	start_tree -> child -> sibling -> sibling -> sibling -> sibling -> sibling -> sibling -> sibling -> sibling = current_tree;
	Tree_Create(15, arr_char[8], 1);
	tmp -> child = current_tree;
	start_tree -> child -> sibling -> sibling -> sibling -> sibling -> sibling -> sibling -> sibling -> sibling -> child = current_tree;
	Tree_Create(16, arr_char[9], 1);
	start_tree -> child -> sibling -> sibling -> sibling -> sibling -> sibling -> sibling -> sibling -> sibling -> sibling = current_tree;

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
	cout << endl;
	
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

void Tree_Create(int state, char character[10], int terminator){
	tree_Node *temp1 = (tree_Node*)malloc(sizeof(tree_Node));	
	for(int i = 0; i < 10; i++)
		temp1 -> name[i] = character[i];
	temp1 -> state = state;
	temp1 -> terminator = terminator;
	temp1 -> child = NULL;
	temp1 -> sibling = NULL;
	if(start_tree == NULL){
		start_tree = temp1;
	}
	current_tree = temp1;
}