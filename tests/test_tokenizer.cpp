#include "gtest/gtest.h"
#include "tokenizer.h"
#include "token.h"
#include <string>
#include <vector>
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
