#include "../String.hpp"
#include "../NumTypes.hpp"

namespace System
{
	Char::Char(wchar_t native)
	{
		inner = native;
	}
	
	Char::Char(Int16 c)
	{
		inner = (wchar_t) c.ToNative();
	}

	String* Char::ToString() const
	{
		return new String(std::wstring(1, inner));
	}

	wchar_t Char::ToNative() const
	{
		return inner;
	}

	Char::operator Char *() const
	{
		return new Char(inner);
	}

	Char::~Char()
	{

	}
}