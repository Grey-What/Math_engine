#ifndef TOKENIZER_H
#define TOKENIZER_H
//Tokenizer class declaration
//interface file
#include <string>
#include <vector>
#include "token.h"
using namespace std;

const string SINGLE_CHAR_TOKENS = "+-*/^()";
const string FUNCTION_TOKENS[8] = {"sin", "cos", "tan", "log", "ln", "sqrt", ...
                                 "abs", "exp"};
class Tokenizer
{
  private:
    string input;
    size_t pos; // current position in input

    char peek(); // view current character
    char get(); // consume current character and move forward
    void skipWhiteSpace();
    int readNumber( string& buffer);
    int readLetter( string& buffer);
    int checkSymbol();

  public:
    Tokenizer(const string& str); //constructor
    vector<Token> tokenize(); //tokenizes input string

};

#endif