#pragma once

#include <string>

#define FORTHICLIB_API  __declspec(dllexport)

using namespace std;

class FORTHICLIB_API Tokenizer
{
public:
	Tokenizer(string& s) : input(s) {};
	Tokenizer();
	~Tokenizer();

protected:
	string input;
};

