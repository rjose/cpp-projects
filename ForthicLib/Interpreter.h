#pragma once

#include <string>
#include <stack>

#include "Defines.h"
#include "StackItems/StackItem.h"
#include "Token.h"
#include "Words/Word.h"

using namespace std;

class FORTHICLIB_API Interpreter
{
public:
	Interpreter();
	~Interpreter();
	void Run(string input);
	StackItem* StackPop();
	void StackPush(StackItem* item);

protected:
	bool is_compiling;
	stack<StackItem*> param_stack;

	void handle_token(Token tok);
	void handle_STRING(Token tok);
	void handle_START_ARRAY(Token token);
	void handle_END_ARRAY(Token token);

	void handle_Word(Word *word);
};

