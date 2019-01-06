#include "pch.h"
#include "Interpreter.h"
#include "Tokenizer.h"
#include "StackItems/StringItem.h"
#include "StackItems/StartArrayItem.h"
#include "Words/PushItemWord.h"
#include "Words/EndArrayWord.h"

Interpreter::Interpreter() : is_compiling(false)
{
    // The first module in the module_stack is the initial local module
    module_stack.push(shared_ptr<Module>(new Module("")));
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

shared_ptr<Module> Interpreter::CurModule()
{
    return module_stack.top();
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

    case TokenType::START_MODULE:
        handle_START_MODULE(token);
        break;

    case TokenType::END_MODULE:
        handle_END_MODULE(token);
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

void Interpreter::handle_START_MODULE(Token tok)
{
    // If module has been registered, push it onto the module stack
    if (auto mod = find_module(tok.GetText()))
    {
        module_stack_push(mod);
    }
    // If the module has no name, push an anonymous module
    else if (tok.GetText() == "")
    {
        module_stack_push(shared_ptr<Module>(new Module("")));
    }
    // Register a new module under the specified name and push it onto the module stack
    else
    {
        mod = shared_ptr<Module>(new Module(tok.GetText()));
        register_module(mod);
        module_stack_push(mod);
    }
}

void Interpreter::handle_END_MODULE(Token tok)
{
    module_stack.pop();
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

shared_ptr<Module> Interpreter::find_module(string name)
{
    if (registered_modules.find(name) == registered_modules.end()) return nullptr;
    else return registered_modules[name];
}

void Interpreter::register_module(shared_ptr<Module> mod)
{
    Module* m = mod.get();
    registered_modules[m->GetName()] = mod;
    // TODO: Run module forthic
}

void Interpreter::module_stack_push(shared_ptr<Module> mod)
{
    module_stack.push(mod);
}