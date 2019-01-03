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
	};
}