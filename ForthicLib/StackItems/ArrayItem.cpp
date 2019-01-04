#include "pch.h"
#include "ArrayItem.h"


ArrayItem::ArrayItem(vector<StackItem*>_items) : items(_items)
{
}


ArrayItem::~ArrayItem()
{
}

vector<StackItem*> ArrayItem::GetArray()
{
	return items;
}