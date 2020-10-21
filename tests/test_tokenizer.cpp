#include "catch2/catch.hpp"
#include "fmt/core.h"
#include "tokenizer/tokenizer.h"


#include <sstream>
#include <vector>

// 下面是示例如何书写测试用例
TEST_CASE("Test hello world.") {
  
  std::string input =
          "begin\n"
          "var a = 1;\n"
          //"const b = 1\n"
         // "print(a+b);\n"
          "end\n";
  std::stringstream ss;
  ss.str(input);
  miniplc0::Tokenizer tkz(ss);
  std::vector<miniplc0::Token> output = {};
  output.emplace_back(
      miniplc0::Token(miniplc0::TokenType::BEGIN,std::string("begin"), 0, 0, 0, 5));
  output.emplace_back(
      miniplc0::Token(miniplc0::TokenType::VAR,std::string("var"), 1, 0, 1, 3));
  output.emplace_back(
      miniplc0::Token(miniplc0::TokenType::IDENTIFIER,std::string("a"), 1, 4, 1, 5));
  output.emplace_back(
      miniplc0::Token(miniplc0::TokenType::EQUAL_SIGN,std::string("="), 1, 6, 1, 7));
  output.emplace_back(
      miniplc0::Token(miniplc0::TokenType::UNSIGNED_INTEGER, std::int32_t(1), 1, 8, 1, 9));
  output.emplace_back(
      miniplc0::Token(miniplc0::TokenType::SEMICOLON,std::string(";"), 1, 9, 1, 10));
  output.emplace_back(
      miniplc0::Token(miniplc0::TokenType::END, std::string("end"), 2, 0, 2, 3));
  auto result = tkz.AllTokens();
  for (int i = 0; i < result.first.size(); i++) {
    std::cout //<< result.first[i].GetType() << " "
              << result.first[i].GetValueString() << " "
              << result.first[i].GetStartPos().first << " "
              << result.first[i].GetStartPos().second << " "
              << result.first[i].GetEndPos().first << " "
              << result.first[i].GetEndPos().second
              << std::endl; 
  }
  if (result.second.has_value()) {
          FAIL();
  }
  REQUIRE( (result.first == output) );
  
}
