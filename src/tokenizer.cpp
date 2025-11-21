// Tokenizer Implementation
#include "tokenizer.h"
#include "token.h"
#include <cctype>
#include <string>
#include <vector>
using namespace std;

const string SYMBOL_TOKENS = "+-*/^()";
const int FUNCTION_TOKEN_SIZE = 8;
const string FUNCTION_TOKENS[FUNCTION_TOKEN_SIZE] = {"sin", "cos", "tan", "log", "ln", "sqrt",
                                 "abs", "exp"};

Tokenizer::Tokenizer(const string& str) : input(str), pos(0) {}

//view members
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

//read memembers
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


TokenType Tokenizer::checkSymbol(string& buffer)
{
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

//tokenizer
vector<Token> Tokenizer::tokenize() {
  vector<Token> tokens;
  char currentChar;
  string buffer = "";
  TokenType type = TokenType::UNKNOWN;

  while (pos < input.size())
  {
    skipWhiteSpace();
    currentChar = peek();
    if (isdigit(currentChar) || currentChar == '.')
    {
      type = readNumber(buffer);
      tokens.push_back(Token(type, buffer));
    } else if (isalpha(currentChar)) {
      type = readLetter(buffer);
      tokens.push_back(Token(type, buffer));

    } else if (SYMBOL_TOKENS.find(currentChar) != string::npos) {
      type = checkSymbol(buffer);
      tokens.push_back(Token(type, buffer));
    } else {
      buffer.clear();
      buffer.push_back(get());
      tokens.push_back(Token(TokenType::UNKNOWN, buffer));
    }
  }
  tokens.push_back(Token(TokenType::END, ""));
  return tokens;
}
