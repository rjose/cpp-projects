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

	};
}