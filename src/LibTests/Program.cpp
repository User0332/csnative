#include "../Lib/System.hpp"
#include "../Lib/System/Collections/Generic.hpp"
#include <memory>
#include <iostream>

using namespace System;
using std::unique_ptr;

int main()
{
	Int32 x = Int32(45);
	Int32 y = Int32(6);
	Boolean truthy = x > y;

	unique_ptr<String> str1 = unique_ptr<String>(new String(L"Hello, World!", 13));
	unique_ptr<String> str2 = unique_ptr<String>(new String(L"Value of y\0+x is: ", 18));
	unique_ptr<String> str3 = unique_ptr<String>(new String(L"Value of boolean is: ", 21));

	// unique_ptr<String> combined = unique_ptr<String>(str1.get()->operator+(str2.get()));

	Console::WriteLine(std::move(str1));
	Console::Write(std::move(str2));
	Console::WriteLine(unique_ptr<Object>(x+y));
	Console::Write(std::move(str3));
	Console::WriteLine(unique_ptr<Object>(truthy));
	Console::WriteLine(unique_ptr<Object>(new Object()));
	// Console::WriteLine(std::move(combined));

	return Int32(0).ToNative();
}