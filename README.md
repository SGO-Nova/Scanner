## Scanner

# This file is meant to take in a .txt file with a specific automata parse tree in mind to make tokens out of the text given.

[Here](https://imgur.com/a/1dNJ1RC) is the automaton used to make this scanner in c++


__NOTE: THIS IS NOT A SYNTAX AUTOMATA TREE, IT WILL NOT POINT OUT SYNTAX ERRORS. IN FACT, IT DOES NOT KNOW WHAT SYNTAX IS__

This means _x := /_ is a legal statement as it is the tokens (id, assign, div) to the automaton here. To a syntax tree this would be an error _in most syntaxes_
