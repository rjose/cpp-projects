#include "pch.h"
#include "CppUnitTest.h"
#include "../ForthicLib/Words/PushItemWord.h"
#include "../ForthicLib/StackItems/StringItem.h"
#include "../ForthicLib/Modules/Module.h"
#include <string>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace ForthicLibTests
{
    TEST_CLASS(ModuleTest)
    {
    public:
        TEST_METHOD(TestConstruction)
        {
            Module empty_module("");
            Assert::IsNotNull(&empty_module);
        }

        TEST_METHOD(TestAddWord)
        {
            /*
            Module module_A("A");
            module_A.AddWord(new PushItemWord("GREETING", new StringItem("Howdy!")));
            Word* word = module_A.FindWord("GREETING");
            Assert::IsNotNull(word);
            */
        }
    };
}
