#include "gtest/gtest.h"
#include "tokenizer.h"
#include "token.h"
#include <string>
#include <vector>
#include <iostream>
using namespace std;

//Minimal test: check that single number is tokenized correctly
TEST(TokenizerTest, SingleNumber) {
  string expr = "42";
  Tokenizer tokenizer(expr);
  vector<Token> tokens = tokenizer.tokenize();

  //Expected tokens: NUMBER and END
  ASSERT_EQ(tokens.size(), 2);
  EXPECT_EQ(tokens[0].type, TokenType::NUMBER);
  EXPECT_EQ(tokens[1].type, TokenType::END);
  EXPECT_EQ(tokens[0].text, "42");
}

//Minimal test: check a single variable
TEST(TokenizerTest, SingleVariable) {
  string expr = "x";
  Tokenizer tokenizer(expr);
  vector<Token> tokens = tokenizer.tokenize();

  ASSERT_EQ(tokens.size(), 2);
  EXPECT_EQ(tokens[0].type, TokenType::VARIABLE);
  EXPECT_EQ(tokens[0].text, "x");
  EXPECT_EQ(tokens[1].type, TokenType::END);
}


//Minimal test: check tokenizer tokenizes each token type correctly
TEST(TokenizerTest, MultiVariable) {
  string expr = "3*x + sin(y)";
  Tokenizer tokenizer(expr);
  auto tokens = tokenizer.tokenize();
  vector<TokenType> expectedTokenType = {
            TokenType::NUMBER, TokenType::OP_MUL, TokenType::VARIABLE,
            TokenType::OP_PLUS, TokenType::FUNCTION, TokenType::LPAREN,
            TokenType::VARIABLE, TokenType::RPAREN, TokenType::END
          };
  vector<string> expectedTokenText = {"3", "*", "x", "+", "sin", "(", "y", ")", ""};

  ASSERT_EQ(tokens.size(), 9);

  for (int i = 0; i < tokens.size(); i++)
  {
    ASSERT_EQ(tokens[i].type, expectedTokenType.at(i));
    ASSERT_EQ(tokens[i].text, expectedTokenText.at(i));
  }
}


//Excessive whitespace test
TEST(TokenizerTest, WhiteSpace) {
  string expr = "   12    +    7  ";
  Tokenizer tokenizer(expr);
  auto tokens = tokenizer.tokenize();
  vector<TokenType> expectedTokenType ={TokenType::NUMBER, TokenType::OP_PLUS, TokenType::NUMBER, TokenType::END};
  vector<string> expectedTokenText = {"12", "+", "7", ""};

  ASSERT_EQ(tokens.size(), 4);

  for (int i = 0; i < tokens.size(); i++)
  {
    EXPECT_EQ(tokens[i].type, expectedTokenType.at(i));
    EXPECT_EQ(tokens[i].text, expectedTokenText.at(i));
  }
}

//Multi-character Variable
TEST(TokenizerTest, MultiCharVariable) {
  string expr = "velocity + height";
  Tokenizer tokenizer(expr);
  auto tokens = tokenizer.tokenize();
  vector<TokenType> expectedTokenType ={TokenType::VARIABLE, TokenType::OP_PLUS, TokenType::VARIABLE, TokenType::END};
  vector<string> expectedTokenText = {"velocity", "+", "height", ""};

  ASSERT_EQ(tokens.size(), 4);

  for (int i = 0; i < tokens.size(); i++)
  {
    EXPECT_EQ(tokens[i].type, expectedTokenType.at(i));
    EXPECT_EQ(tokens[i].text, expectedTokenText.at(i));
  }
}

//FUNCTION without parentheses
TEST(TokenizerTest, FunctionNoParentheses) {
  string expr = "sinx";
  Tokenizer tokenizer(expr);
  auto tokens = tokenizer.tokenize();
  vector<TokenType> expectedTokenType ={
    TokenType::FUNCTION,
    TokenType::VARIABLE,
    TokenType::END
  };
  vector<string> expectedTokenText = {"sin", "x", ""};

  ASSERT_EQ(tokens.size(), expectedTokenType.size());

  for (int i = 0; i < tokens.size(); i++)
  {
    EXPECT_EQ(tokens[i].type, expectedTokenType.at(i));
    EXPECT_EQ(tokens[i].text, expectedTokenText.at(i));
  }
}

//Floating point
TEST(TokenizerTest, FloatingPointNumber) {
  string expr = "3.1415";
  Tokenizer tokenizer(expr);
  auto tokens = tokenizer.tokenize();

  vector<TokenType> expectedTokenType = {
    TokenType::NUMBER, TokenType::END
  };
  vector<string> expectedTokenText = {"3.1415", ""};

  ASSERT_EQ(tokens.size(), expectedTokenType.size());

  for (int i = 0; i < tokens.size(); i++)
  {
    EXPECT_EQ(tokens[i].type, expectedTokenType.at(i));
    EXPECT_EQ(tokens[i].text, expectedTokenText.at(i));
  }
}

//negative numbers
TEST(TokenizerTest, NegativeNumber) {
  string expr = "-5 + 3";
  Tokenizer tokenizer(expr);
  auto tokens = tokenizer.tokenize();

  vector<TokenType> expectedTokenType = {
    TokenType::OP_MINUS, TokenType::NUMBER,
    TokenType::OP_PLUS, TokenType::NUMBER,
    TokenType::END
  };
  vector<string> expectedTokenText = {"-", "5", "+", "3", ""};

  ASSERT_EQ(tokens.size(), expectedTokenType.size());

  for (int i = 0; i < tokens.size(); i++)
  {
    EXPECT_EQ(tokens[i].type, expectedTokenType.at(i));
    EXPECT_EQ(tokens[i].text, expectedTokenText.at(i));
  }
}

//Parentheses nesting
TEST(TokenizerTest, NestedParentheses) {
  string expr = "((x+1)*(y-2))";
  Tokenizer tokenizer(expr);
  auto tokens = tokenizer.tokenize();

  vector<TokenType> expectedTokenType = {
    TokenType::LPAREN, TokenType::LPAREN,
    TokenType::VARIABLE, TokenType::OP_PLUS, TokenType::NUMBER,
    TokenType::RPAREN,
    TokenType::OP_MUL,
    TokenType::LPAREN,
    TokenType::VARIABLE, TokenType::OP_MINUS, TokenType::NUMBER,
    TokenType::RPAREN,
    TokenType::RPAREN,
    TokenType::END
  };

  vector<string> expectedTokenText = {
    "(", "(", "x", "+", "1", ")", "*", "(", "y", "-", "2", ")", ")", ""
  };

  ASSERT_EQ(tokens.size(), expectedTokenType.size());

  for (int i = 0; i < tokens.size(); i++)
  {
    EXPECT_EQ(tokens[i].type, expectedTokenType.at(i));
    EXPECT_EQ(tokens[i].text, expectedTokenText.at(i));
  }
}

//Multiple operators
TEST(TokenizerTest, MultiOperatorExpression) {
  string expr = "a*b/c+d-e";
  Tokenizer tokenizer(expr);
  auto tokens = tokenizer.tokenize();

  vector<TokenType> expectedTokenType = {
    TokenType::VARIABLE, TokenType::OP_MUL, TokenType::VARIABLE,
    TokenType::OP_DIV, TokenType::VARIABLE,
    TokenType::OP_PLUS, TokenType::VARIABLE,
    TokenType::OP_MINUS, TokenType::VARIABLE,
    TokenType::END
  };

  vector<string> expectedTokenText = {
    "a", "*", "b", "/", "c", "+", "d", "-", "e", ""
  };

  ASSERT_EQ(tokens.size(), expectedTokenType.size());

  for (int i = 0; i < tokens.size(); i++)
  {
    EXPECT_EQ(tokens[i].type, expectedTokenType.at(i));
    EXPECT_EQ(tokens[i].text, expectedTokenText.at(i));
  }
}

//Multi-letter functions
TEST(TokenizerTest, MultiCharFunction) {
  string expr = "arcsin(x)";
  Tokenizer tokenizer(expr);
  auto tokens = tokenizer.tokenize();

  vector<TokenType> expectedTokenType = {
    TokenType::FUNCTION, TokenType::LPAREN,
    TokenType::VARIABLE, TokenType::RPAREN,
    TokenType::END
  };

  vector<string> expectedTokenText = {"arcsin", "(", "x", ")", ""};

  ASSERT_EQ(tokens.size(), expectedTokenType.size());

  for (int i = 0; i < tokens.size(); i++)
  {
    EXPECT_EQ(tokens[i].type, expectedTokenType.at(i));
    EXPECT_EQ(tokens[i].text, expectedTokenText.at(i));
  }
}

//Function applied to function
TEST(TokenizerTest, FunctionInsideFunction) {
  string expr = "sin(cos(x))";
  Tokenizer tokenizer(expr);
  auto tokens = tokenizer.tokenize();

  vector<TokenType> expectedTokenType = {
    TokenType::FUNCTION, TokenType::LPAREN,
    TokenType::FUNCTION, TokenType::LPAREN,
    TokenType::VARIABLE,
    TokenType::RPAREN,
    TokenType::RPAREN,
    TokenType::END
  };

  vector<string> expectedTokenText = {
    "sin", "(", "cos", "(", "x", ")", ")", ""
  };

  ASSERT_EQ(tokens.size(), expectedTokenType.size());

  for (int i = 0; i < tokens.size(); i++)
  {
    EXPECT_EQ(tokens[i].type, expectedTokenType.at(i));
    EXPECT_EQ(tokens[i].text, expectedTokenText.at(i));
  }
}

//Invalid characters
TEST(TokenizerTest, InvalidCharacter) {
  string expr = "5 & 3";
  Tokenizer tokenizer(expr);

  EXPECT_THROW(tokenizer.tokenize(), runtime_error);
}

//Empty string
TEST(TokenizerTest, EmptyString) {
  string expr = "";
  Tokenizer tokenizer(expr);
  auto tokens = tokenizer.tokenize();

  ASSERT_EQ(tokens.size(), 1);
  EXPECT_EQ(tokens[0].type, TokenType::END);
  EXPECT_EQ(tokens[0].text, "");
}

//Variables with digits
TEST(TokenizerTest, VariableWithDigits) {
  string expr = "x2 + y10";
  Tokenizer tokenizer(expr);
  auto tokens = tokenizer.tokenize();

  vector<TokenType> expectedTokenType = {
    TokenType::VARIABLE, TokenType::OP_PLUS, TokenType::VARIABLE, TokenType::END
  };

  vector<string> expectedTokenText = {"x2", "+", "y10", ""};

  ASSERT_EQ(tokens.size(), expectedTokenType.size());

  for (int i = 0; i < tokens.size(); i++)
  {
    EXPECT_EQ(tokens[i].type, expectedTokenType.at(i));
    EXPECT_EQ(tokens[i].text, expectedTokenText.at(i));
  }
}
