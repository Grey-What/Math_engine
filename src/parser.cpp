// parser Implementation
#include <iostream>
#include "C:\Users\greyw\VSC_CodeCreations\Math_engine\include\parser.h"
#include "C:\Users\greyw\VSC_CodeCreations\Math_engine\include\ASTNode.h"

Parser::Parser(const vector<Token>& t) : tokens(t) ,pos(0) {}

//View members
Token Parser::peek() {}
Token Parser::get() {}

//Parsing member functions
ASTNode* Parser::parseExpression() {}
ASTNode* Parser::parseTerm() {}
ASTNode* Parser::parseFactor() {}
ASTNode* Parser::parsePrimary() {}

//Entry
ASTNode* parse() {};

