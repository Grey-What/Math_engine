//AST node structure declaration
#ifndef ASTNODE_H
#define ASTNODE_H
#include "token.h"
#include <vector>

struct ASTNode {
  Token token;
  ASTNode* left = nullptr; //for binary operators
  ASTNode* right = nullptr; //for unary operators
  vector<ASTNode*> args;//for function arguments

  ASTNode(const Token& t) : token(t) {}
};

#endif
