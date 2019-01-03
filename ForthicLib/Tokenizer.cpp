#include "pch.h"
#include "Tokenizer.h"

Tokenizer::Tokenizer(string& s) : input(s) 
{
	whitespace = " \r\t\n()";
	token_string = "";
	position = 0;
}

Tokenizer::~Tokenizer()
{
}

bool Tokenizer::is_whitespace(char c)
{
	for (unsigned int i = 0; i < whitespace.length(); i++) {
		if (c == whitespace[i]) return true;
	}
	return false;
}

Token Tokenizer::NextToken()
{
	token_string = "";
	return transition_from_START();
}

Token Tokenizer::transition_from_START()
{
	while (position < input.length())
	{
		char c = input[position++];
		if (is_whitespace(c)) continue;
		else if (c == '#') return transition_from_COMMENT();
		else { /* TODO: Handle more cases */ }
	}
	return Token(TokenType::EOS);
}

Token Tokenizer::transition_from_COMMENT()
{
	while (position < input.length())
	{
		char c = input[position++];
		if (c == '\n') break;
		token_string += c;
	}
	return Token(TokenType::COMMENT, token_string);
}
