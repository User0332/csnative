#include "../String.hpp"
#include <codecvt>
#include <locale>

namespace System
{
	String::String(std::wstring string)
	{
		GC::Register(this);
		inner = inner;
	}

	String::String(std::string string)
	{
		GC::Register(this);
		inner = std::wstring_convert<std::codecvt_utf8<wchar_t>>().from_bytes(string);
	}

	String::String(Char string[])
	{
		GC::Register(this);
		const int arr_size = sizeof(string)/sizeof(Char);
		
		wchar_t arr[arr_size];

		for (int i; i < arr_size; i++) { arr[i] = string[i].ToNative(); }

		inner = std::wstring(arr);
	}

	String::String(wchar_t string[])
	{
		GC::Register(this);
		inner = std::wstring(string);
	}

	String::String(wchar_t string[], size_t length)
	{
		GC::Register(this);
		inner = std::wstring(string, length);
	}

	String::String(char string[], size_t length)
	{
		GC::Register(this);
		inner = std::wstring_convert<std::codecvt_utf8<wchar_t>>().from_bytes(std::string(string, length));
	}

	String::String(char string[])
	{
		GC::Register(this);
		inner = std::wstring_convert<std::codecvt_utf8<wchar_t>>().from_bytes(string);
	}

	std::wstring String::ToCpp()
	{
		return inner;
	}

	String* String::ToString()
	{
		std::wstring copy = inner;

		return new String(copy);
	}

	String* String::operator+(String* other)
	{
		return new String(inner+other->inner);
	}

	String* String::operator+(Char other)
	{
		return new String(inner+other.ToNative());
	}

	String::~String()
	{
		GC::UnRegister(this);
	}
}