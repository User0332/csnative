#include "../String.hpp"
#include "../../CSharp.Native/LoadedAssemblies.hpp"
#include <codecvt>
#include <locale>
#include <array>

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

	std::wstring String::ToCpp() const
	{
		return inner;
	}

	String* String::ToString() const
	{
		std::wstring copy = inner;

		return new String(copy);
	}

	String* String::operator+(const String* other) const
	{
		String* ret = new String(inner+other->inner);

		return ret;
	}

	String* String::operator+(const Char& other) const
	{
		return new String(inner+other.ToNative());
	}

	Boolean String::operator==(const String* other) const
	{
		return Boolean(this->inner == other->inner);
	}


	String::~String()
	{

	}

	Type* String::GetType()
	{
		return CSharp::Native::ReflectionServices::LoadedAssemblyNameMap[new String("CSharp.Native.System")]->GetType(new String("System.String"));
	}
}