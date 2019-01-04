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
			StackItem* item = interp.StackPop();
			Assert::AreEqual(string("Howdy"), ForthicGetString(item));
			delete item;
		}

		TEST_METHOD(TestPushEmptyArray)
		{
			Interpreter interp;
			interp.Run("[ ]");
			StackItem* array_item = interp.StackPop();
			vector<StackItem*> items = ForthicGetArray(array_item);
			Assert::AreEqual(0, (int)items.size());
			delete array_item;
		}

		TEST_METHOD(TestPushArray)
		{
			Interpreter interp;
			interp.Run("[ 'One' 'Two' ]");
			StackItem* array_item = interp.StackPop();
			vector<StackItem*> items = ForthicGetArray(array_item);
			Assert::AreEqual(2, (int)items.size());
			Assert::AreEqual(string("One"), ForthicGetString(items[0]));
			Assert::AreEqual(string("Two"), ForthicGetString(items[1]));
			
			delete items[0];
			delete items[1];
			delete array_item;
		}
	};
}