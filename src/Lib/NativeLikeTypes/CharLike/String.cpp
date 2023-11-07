#include "../String.hpp"
#include "../../CSharp.Native/GarbageCollector.hpp"
#include <codecvt>
#include <locale>
#include <array>

using namespace CSharp::Native;

namespace System
{
	String::String(std::wstring string)
	{
		inner = inner;
	}

	String::String(std::string string)
	{
		inner = std::wstring_convert<std::codecvt_utf8<wchar_t>>().from_bytes(string);
	}

	String::String(Char string[])
	{
		size_t arr_size = *(&string + 1) - string;
		
		wchar_t arr[arr_size];

		for (int i; i < arr_size; i++) { arr[i] = string[i].ToNative(); }

		inner = std::wstring(arr);
	}

	String::String(wchar_t string[])
	{
		inner = std::wstring(string);
	}

	String::String(wchar_t string[], size_t length)
	{
		inner = std::wstring(string, length);
	}

	String::String(char string[], size_t length)
	{
		inner = std::wstring_convert<std::codecvt_utf8<wchar_t>>().from_bytes(std::string(string, length));
	}

	String::String(char string[])
	{
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
		GC::Register(other);
		String* ret = new String(inner+other->inner);
		GC::UnRegister(other);

		return ret;
	}

	String* String::operator+(Char other)
	{
		return new String(inner+other.ToNative());
	}

	String::~String()
	{

	}
}