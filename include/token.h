// Contains token defintions for tokenizer
//TOkenType enum and Token struct
#ifndef TOKEN_H
#define TOKEN_H
#include <string>
using namespace std;

enum class TokenType {
  NUMBER, //0
  VARIABLE, //1
  OP_PLUS, //2
  OP_MINUS, //3
  OP_MUL, //4
  OP_DIV, //5
  OP_POW, //6
  LPAREN, //7
  RPAREN, //8
  FUNCTION, //9
  END, //10
  UNKNOWN //11
};

struct Token
{
  /* data */
  TokenType type;
  string text;

  Token(TokenType t, const string& s) : type(t), text(s) {}
};


#endif
