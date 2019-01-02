#include "pch.h"
#include "CppUnitTest.h"
#include "../ForthicLib/Tokenizer.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ForthicLibTests
{
    TEST_CLASS(TokenizerTest)
    {
    public:
        TEST_METHOD(TestConstruction)
        {
			Tokenizer tokenizer;
			Assert::AreEqual(1, 1);
        }
    };
}