#include "../Lib/System.hpp"
#include <iostream>

using namespace System;

int main()
{
	Int32 x = Int32(45);
	Int32 y = Int32(6);
	Boolean truthy = x > y;

	String* str1 = new String("Hello, World!");
	String* str2 = new String("Value of y+x is: ");
	String* str3 = new String("Value of boolean is: ");

	Console::WriteLine(str1);
	Console::Write(str2);
	Console::WriteLine(&(x+y));
	Console::Write(str3);
	Console::WriteLine(&truthy);
	Console::WriteLine(new Object());

	return 0;
}