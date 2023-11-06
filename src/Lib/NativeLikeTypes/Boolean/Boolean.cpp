#include "../Object.hpp"
#include "../String.hpp"

namespace System
{
	Boolean::operator bool()
	{
		return val;
	}

	bool Boolean::ToNative()
	{
		return val;
	}

	Boolean::Boolean()
	{
		val = false;
	}

	Boolean::Boolean(bool other)
	{
		val = other;
	}

	String* Boolean::ToString()
	{
		if (val) return new String(L"True");
		
		return new String(L"False");
	}

	Boolean::operator Boolean *()
	{
		Boolean* boxed = new Boolean(val);
		GC::Register(boxed);

		return boxed;
	}

	Boolean::~Boolean()
	{
		GC::UnRegister(this);
	}
}