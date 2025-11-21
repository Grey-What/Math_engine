#ifndef TOKENIZER_H
#define TOKENIZER_H
//Tokenizer class declaration
//interface file
#include <string>
#include <vector>
#include "token.h"
using namespace std;

extern const string SINGLE_CHAR_TOKENS = "+-*/^()";
extern const string FUNCTION_TOKENS[8] = {"sin", "cos", "tan", "log", "ln", "sqrt",
                                 "abs", "exp"};
class Tokenizer
{
  private:
    string input;
    size_t pos; // current position in input

    char peek(); // view current character
    char get(); // consume current character and move forward
    void skipWhiteSpace(); //Skip white space
    int readNumber( string& buffer); // Reads a number from input
    int readLetter( string& buffer); // reads letters from input
    int checkSymbol(); //check the type of symbol in input
  public:
    Tokenizer(const string& str); //constructor
    vector<Token> tokenize(); //tokenizes input string

};

#endif