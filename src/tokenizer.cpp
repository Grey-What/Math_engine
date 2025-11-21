// Tokenizer Implementation
#include "C:\Users\greyw\VSC_CodeCreations\Math_engine\include\tokenizer.h"
#include "C:\Users\greyw\VSC_CodeCreations\Math_engine\include\token.h"
#include <cctype>
#include <string>
#include <vector>
using namespace std;

Tokenizer::Tokenizer(const string& str) : input(str), pos(0) {}

char Tokenizer::peek() {
  if (pos < input.size()) return input[pos];
  return '\0';
}

char Tokenizer::get() {
  if (pos < input.size()) return input[pos++];
  return '\0';
}

void Tokenizer::skipWhiteSpace() {
  while (isspace(peek())) get();
}

TokenType Tokenizer::readNumber(string& buffer) {
  buffer.clear();
  buffer.push_back(get());
  while (isdigit(peek()) || peek() == '.')
  {
    buffer.push_back(get());
  }
  return TokenType::NUMBER;
}

TokenType Tokenizer::readLetter(string& buffer) {
  bool isFunction = false;
  buffer.clear();
  while (isalpha(peek()))
  {
    buffer.push_back(get());
  }
  //check if function
  for (int i = 0; i < FUNCTION_TOKEN_SIZE; i++)
  {
    if (buffer == FUNCTION_TOKENS[i])
    {
      return TokenType::FUNCTION;
    }
  }
  return TokenType::VARIABLE;
}

TokenType checkSymbol() {
  char c = get();
  buffer.clear();
  buffer.push_back(c);

  switch (c)
  {
    case '+':
      return TokenType::OP_PLUS;
      break;
    case '-':
      return TokenType::OP_MINUS;
      break;
    case '*':
      return TokenType::OP_MUL;
      break;
    case '/':
      return TokenType::OP_DIV;
      break;
    case '^':
      return TokenType::OP_POW;
      break;
    case '(':
      return TokenType::LPAREN;
      break;
    case ')':
      return TokenType::RPAREN;
      break;
    default:
      return TokenType::UNKNOWN;
      break;
  }
}

vector<Token> Tokenizer::tokenize() {
  vector<Token> tokens;
  char currentChar;
  string buffer = "";
  TokenType type = TokenType::UNKNOWN;

  while (pos < input.size())
  {
    skipWhiteSpace();
    currentChar = peek();
    if (isdigit(peek()) || peek() == '.')
    {
      type = readNumber(buffer);
      tokens.push_back(Token(type, buffer));
    }
    if (isalpha(peek()))
    {
      type = readLetter(buffer);
      tokens.push_back(Token(type, buffer));

    }
    if (SYMBOL_TOKENS.find(peek()) != string::npos)
    {
      type = checkSymbol();
      tokens.push_back(Token(type, buffer));
    }
  }
  tokens.push_back(Token(TokenType::END, buffer));
}
