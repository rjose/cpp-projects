#pragma once

#include <string>
#include <stack>
#include <vector>
#include <map>

#include "../Defines.h"
#include "Words/Word.h"

class Interpreter;

using namespace std;

class PopWord : public Word
{
public:
    PopWord(string name);
    virtual void Execute(Interpreter *interp);
};
