// parser Implementation
#include <iostream>
#include "C:\Users\greyw\VSC_CodeCreations\Math_engine\include\parser.h"
#include "C:\Users\greyw\VSC_CodeCreations\Math_engine\include\ASTNode.h"

Parser::Parser(const vector<Token>& t) : tokens(t) ,pos(0) {}

//View members
Token Parser::peek() {

}

Token Parser::get() {

}

//Parsing member functions
ASTNode* Parser::parseExpression() {
  ASTNode* left = parseTerm();
  while (peek().type == TokenType::OP_PLUS || peek().type == TokenType::OP_MINUS)
  {
    Token opToken = get();
    ASTNode* right = parseTerm();
    ASTNode* opNode = new ASTNode(opToken);
    opNode->right = right;
    opNode->left = left;
    left = opNode;
  }
  return left;
}

ASTNode* Parser::parseTerm() {
  ASTNode* left = parseFactor();
  while (peek().type == TokenType::OP_MUL || peek().type == TokenType::OP_DIV)
  {
    Token OpToken = get();
    ASTNode* right = parseFactor();
    ASTNode* opNode = new ASTNode(OpToken);
    opNode->right = right;
    opNode->left = left;
    left = opNode;
  }
  return left;
}

ASTNode* Parser::parseFactor() {
  if (peek().type == TokenType::OP_PLUS || peek().type == TokenType::OP_MINUS)
  {
    Token opToken = get();
    ASTNode* operand = parseFactor();
    ASTNode* opNode = new ASTNode(opToken);
    opNode->left = operand;
    return opNode;
  }
  if (peek().type == TokenType::NUMBER)
  {
    Token token = get();
    return new ASTNode(token);
  }
  if (peek().type == TokenType::VARIABLE)
  {
    Token token = get();
    return new ASTNode(token);
  }
  if (peek().type == TokenType::FUNCTION)
  {
    Token token = get();
    ASTNode* arg = parseFactor();
    ASTNode* funcNode = new ASTNode(token);
    funcNode->left = arg;
    return funcNode;
  }
}

ASTNode* Parser::parsePrimary() {

}

//Entry
ASTNode* parse() {
}
