#include "pch.h"
#include "Interpreter.h"
#include "Tokenizer.h"
#include "StackItems/StringItem.h"
#include "StackItems/StartArrayItem.h"
#include "Words/PushItemWord.h"
#include "Words/EndArrayWord.h"


Interpreter::Interpreter() : is_compiling(false)
{
}


Interpreter::~Interpreter()
{
}

void Interpreter::Run(string input)
{
	Tokenizer tokenizer(input);
	Token tok = tokenizer.NextToken();
	while (tok.GetType() != TokenType::EOS)
	{
		handle_token(tok);
		tok = tokenizer.NextToken();
	}
}

shared_ptr<StackItem> Interpreter::StackPop()
{
	shared_ptr<StackItem> result = param_stack.top();
	param_stack.pop();
	return result;
}

void Interpreter::StackPush(shared_ptr<StackItem> item)
{
	param_stack.push(item);
}


void Interpreter::handle_token(Token token)
{
	switch (token.GetType())
	{
	case TokenType::START_ARRAY:
		handle_START_ARRAY(token);
		break;

	case TokenType::END_ARRAY:
		handle_END_ARRAY(token);
		break;

	case TokenType::STRING:
		handle_STRING(token);
		break;

	default:
		throw "Unknown token type";
	}
}

void Interpreter::handle_STRING(Token tok)
{
	StringItem* item = new StringItem(tok.GetText());
	handle_Word(new PushItemWord("<string>", shared_ptr<StackItem>(item)));
}

void Interpreter::handle_START_ARRAY(Token token)
{
	StartArrayItem* item = new StartArrayItem();
	handle_Word(new PushItemWord("[", shared_ptr<StackItem>(item)));
}

void Interpreter::handle_END_ARRAY(Token token)
{
	handle_Word(new EndArrayWord("]"));
}


void Interpreter::handle_Word(Word *word)
{
	if (is_compiling)
	{
		// TODO: Handle compile
	}
	else
	{
		word->Execute(this);
		delete word;
	}
}