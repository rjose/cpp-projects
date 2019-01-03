#pragma once

#include <string>
#include "Token.h"

#define FORTHICLIB_API  __declspec(dllexport)

using namespace std;

class FORTHICLIB_API Tokenizer
{
public:
	Tokenizer(string& s);
	~Tokenizer();
	Token NextToken();

protected:
	bool is_whitespace(char c);
	Token transition_from_START();

	unsigned int position;
	string input;
	string whitespace;
	string token_string;
};

