#include "../String.hpp"
#include "../NumTypes.hpp"

namespace System
{
	Char::Char(wchar_t native)
	{
		inner = native;
	}

	Char::Char(short native)
	{
		inner = (wchar_t) native;
	}

	Char::Char(Int16 c)
	{
		inner = (wchar_t) c.ToNative();
	}

	String* Char::ToString()
	{
		return new String(std::wstring(1, inner));
	}

	wchar_t Char::ToNative()
	{
		return inner;
	}
}