#include "pch.h"
#include "GlobalModuleWords.h"
#include "Interpreter.h"

PopWord::PopWord(string name) : Word(name)
{
}


void PopWord::Execute(Interpreter *interp)
{
    interp->StackPop();
}
