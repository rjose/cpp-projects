#include "pch.h"
#include "CppUnitTest.h"
#include "../ForthicLib/Interpreter.h"
#include "../ForthicLib/StackItems/StackItem.h"
#include "../ForthicLib/StackItems/StringItem.h"
#include "../ForthicLib/StackItems/ArrayItem.h"
#include <string>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace ForthicLibTests
{
    TEST_CLASS(InterpreterTest)
    {
    public:
        TEST_METHOD(TestConstruction)
        {
            Interpreter interp;
            Assert::IsNotNull(&interp);
        }

        TEST_METHOD(TestPushString)
        {
            Interpreter interp;
            interp.Run("'Howdy'");
            shared_ptr<StackItem> item = interp.StackPop();
            Assert::AreEqual(string("Howdy"), ForthicGetString(item.get()));
        }

        TEST_METHOD(TestPushEmptyArray)
        {
            Interpreter interp;
            interp.Run("[ ]");
            shared_ptr<StackItem> array_item = interp.StackPop();
            vector<shared_ptr<StackItem>> items = ForthicGetArray(array_item.get());
            Assert::AreEqual(0, (int)items.size());
        }

        TEST_METHOD(TestPushArray)
        {
            Interpreter interp;
            interp.Run("[ 'One' 'Two' ]");
            shared_ptr<StackItem> array_item = interp.StackPop();
            vector<shared_ptr<StackItem>> items = ForthicGetArray(array_item.get());
            Assert::AreEqual(2, (int)items.size());
            Assert::AreEqual(string("One"), ForthicGetString(items[0].get()));
            Assert::AreEqual(string("Two"), ForthicGetString(items[1].get()));
        }
    };
}