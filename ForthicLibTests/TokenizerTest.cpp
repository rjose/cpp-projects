#include "pch.h"
#include "CppUnitTest.h"
#include "../ForthicLib/Tokenizer.h"
#include <string>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace ForthicLibTests
{
    TEST_CLASS(TokenizerTest)
    {
    public:
        TEST_METHOD(TestConstruction)
        {
			string input = "";
			Tokenizer tokenizer(input);
			Assert::IsNotNull(&tokenizer);
        }

		TEST_METHOD(TestWhitespace)
		{
			string input = "      ()   \t\r\n   ";
			Tokenizer tokenizer(input);
			Token tok = tokenizer.NextToken();
			Assert::IsTrue(TokenType::EOS == tok.GetType());
		}

		TEST_METHOD(TestComment)
		{
			string input = "  # This is a comment";
			Tokenizer tokenizer(input);
			Token tok = tokenizer.NextToken();
			Assert::IsTrue(TokenType::COMMENT == tok.GetType());

			tok = tokenizer.NextToken();
			Assert::IsTrue(TokenType::EOS == tok.GetType());
		}

		TEST_METHOD(TestStartEndDefinition)
		{
			string input = ": DEF1 ;";
			Tokenizer tokenizer(input);

			Token tok = tokenizer.NextToken();
			Assert::IsTrue(TokenType::START_DEFINITION == tok.GetType());
			Assert::AreEqual(string("DEF1"), tok.GetText());

			tok = tokenizer.NextToken();
			Assert::IsTrue(TokenType::END_DEFINITION == tok.GetType());
		}

		TEST_METHOD(TestStartEndArray)
		{
			string input = "[ ]";
			Tokenizer tokenizer(input);

			Token tok = tokenizer.NextToken();
			Assert::IsTrue(TokenType::START_ARRAY == tok.GetType());

			tok = tokenizer.NextToken();
			Assert::IsTrue(TokenType::END_ARRAY == tok.GetType());
		}
	};
}