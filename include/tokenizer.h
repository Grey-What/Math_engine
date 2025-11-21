#ifndef TOKENIZER_H
#define TOKENIZER_H
//Tokenizer class declaration
//interface file
#include <string>
#include <vector>
#include "token.h"
using namespace std;

extern const int FUNCTION_TOKEN_SIZE = 8;
extern const string FUNCTION_TOKENS[FUNCTION_TOKEN_SIZE] = {"sin", "cos", "tan", "log", "ln", "sqrt",
                                 "abs", "exp"};
extern const string SYMBOL_TOKENS = "+-*/^()";

class Tokenizer
{
  private:
    string input;
    size_t pos; // current position in input

    char peek(); // view current character
    char get(); // consume current character and move forward
    void skipWhiteSpace(); //Skip white space
    TokenType readNumber( string& buffer); // Reads a number from input
    TokenType readLetter( string& buffer); // reads letters from input
    TokenType checkSymbol(string& buffer); //check the type of symbol in input
  public:
    Tokenizer(const string& str); //constructor
    vector<Token> tokenize(); //tokenizes input string

};

#endif
