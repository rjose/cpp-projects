#pragma once

#include <string>
#include <stack>

#include "../Defines.h"
#include "../ForthicLib/Words/Word.h"

using namespace std;

class FORTHICLIB_API Module
{
public:
	Module(string name);
	~Module();

//    void AddWord(Word* word);
//    Word* FindWord(string name);

protected:
	string name;
};

