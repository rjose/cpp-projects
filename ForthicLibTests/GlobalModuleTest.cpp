#include "pch.h"
#include "CppUnitTest.h"
#include "../ForthicLib/Interpreter.h"
#include "../ForthicLib/StackItems/StackItem.h"
#include "../ForthicLib/StackItems/StringItem.h"
#include "../ForthicLib/StackItems/ArrayItem.h"
#include "../ForthicLib/Modules/GlobalModule.h"
#include <string>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace ForthicLibTests
{
    TEST_CLASS(GlobalModuleTest)
    {
    public:
        Interpreter* interp;

        TEST_METHOD_INITIALIZE(Setup)
        {
            interp = new Interpreter();
        }

        TEST_METHOD_CLEANUP(Teardown)
        {
            delete interp;
        }

        TEST_METHOD(TestIntLiteral)
        {
            interp->Run("27");
            shared_ptr<StackItem> item = interp->StackPop();
            Assert::AreEqual(27, ForthicGetInt(item.get()));
        }

        TEST_METHOD(TestFloatLiteral)
        {
            interp->Run("27.5");
            shared_ptr<StackItem> item = interp->StackPop();
            Assert::IsTrue(fabs(ForthicGetFloat(item.get()) - 27.5) < 0.01);
        }
    };
}
