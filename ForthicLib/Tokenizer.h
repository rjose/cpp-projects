#pragma once

#ifdef FORTHICLIB_EXPORTS
#define FORTHICLIB_API  __declspec(dllexport)
#else
#define FORTHICLIB_API __declspec(dllimport)
#endif

class FORTHICLIB_API Tokenizer
{
public:
	Tokenizer();
	~Tokenizer();
};

