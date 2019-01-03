#pragma once

#include <string>
using namespace std;

#define FORTHICLIB_API  __declspec(dllexport)

enum class TokenType { NONE, EOS };

class FORTHICLIB_API Token
{
public:
	Token(enum class TokenType t, string& s);
	Token(enum class TokenType t);
	~Token();

	enum class TokenType GetType();

protected:
	enum class TokenType type;
	string text;
};

