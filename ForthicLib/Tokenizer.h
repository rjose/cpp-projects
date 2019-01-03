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

	// Transition functions
	Token transition_from_START();
	Token transition_from_COMMENT();
	Token transition_from_START_DEFINITION();
	Token transition_from_GATHER_DEFINITION_NAME();

	unsigned int position;
	string input;
	string whitespace;
	string token_string;
};

