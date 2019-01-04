#include "pch.h"
#include "GlobalItemGetters.h"

string FORTHICLIB_API ForthicGetString(StackItem *item)
{
	if (auto i = dynamic_cast<IGetString*>(item))
	{
		return i->GetString();
	}
	else
	{
		throw "Item does not implement IGetString";
	}
}

vector<StackItem*> FORTHICLIB_API ForthicGetArray(StackItem *item)
{
	if (auto i = dynamic_cast<IGetArray*>(item))
	{
		return i->GetArray();
	}
	else
	{
		throw "Item does not implement IGetArray";
	}
}
