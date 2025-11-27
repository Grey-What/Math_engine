// Parser class declaration
// Interface file
// parser.h
#ifndef PARSER_H
#define PARSER_H

#include "token.h"
#include "ASTNode.h"
#include <vector>

class Parser {
private:
    std::vector<Token> tokens;
    size_t pos;

    Token peek();
    Token get();

    // Parsing functions
    ASTNode* parseExpression(); // Handles + and -
    ASTNode* parseTerm();       // Handles * and /
    ASTNode* parseFactor();     // Handles ^ and unary operators
    ASTNode* parsePrimary();    // Handles numbers, variables, functions, parentheses

public:
    Parser(const std::vector<Token>& t);
    ASTNode* parse();                     // Entry point, returns root of AST
};

#endif

