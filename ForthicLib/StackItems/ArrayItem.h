#pragma once
#include <string>
#include <vector>

#include "../Defines.h"
#include "../Modules/GlobalItemGetters.h"
#include "StackItem.h"

using namespace std;


class FORTHICLIB_API ArrayItem : public StackItem, public IGetArray
{
public:
	ArrayItem(vector<StackItem*> items);
	virtual ~ArrayItem();
	vector<StackItem*> GetArray();

protected:
	vector<StackItem*> items;
};