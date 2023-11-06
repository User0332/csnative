#include "../Lib/System.hpp"
#include <iostream>

using namespace System;

int main()
{
	Int32 x = Int32(45);
	Int32 y = Int32(6);
	Boolean truthy = x > y;

	String* str1 = new String(L"Hello, World!", 13);
	String* str2 = new String(L"Value of y\0+x is: ", 18);
	String* str3 = new String(L"Value of boolean is: ", 21);

	Console::WriteLine(str1);
	Console::Write(str2);
	Console::WriteLine(x+y);
	Console::Write(str3);
	Console::WriteLine(truthy);
	Console::WriteLine(new Object());

	return 0;
}