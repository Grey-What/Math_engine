// Tokenizer Implementation
#include "C:\Users\greyw\VSC_CodeCreations\Math_engine\include\tokenizer.h"
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

vector<Token> Tokenizer::tokenize() {
  vector<Token> tokens;
  char currentChar;
  string buffer = "";
  int type = 11;

  while (pos < input.size())
  {
    skipWhiteSpace();
    currentChar = peek();
    if (isdigit(peek()) || peek() == '.')
    {
      readNumber(buffer);
      tokens.push_back(Token(TokenType::NUMBER, buffer));
    }
    if (isalpha(peek()))
    {
      type = readLetters(buffer);
      tokens.push_back(Token(static_cast<TokenType>(type), buffer));

    }
    if (SINGLE_CHAR_TOKENS.find(peek()) != string::npos)
    {
      type = checkSymbols();
      tokens.push_back(Token(static_cast<TokenType>(type), buffer));
    }
  }
  tokens.push_back(Token(TokenType::END, buffer));
}
