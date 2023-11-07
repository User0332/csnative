#include "../Lib/System.hpp"
#include "../Lib/CSharp.Native/GarbageCollector.hpp"
#include <iostream>

using namespace System;
using namespace CSharp::Native;

int main()
{
	Int32 x = Int32(45);
	Int32 y = Int32(6);
	Boolean truthy = x > y;

	String* str1 = new String(L"Hello, World!", 13);
	GC::Register(str1);
	String* str2 = new String(L"Value of y\0+x is: ", 18);
	GC::Register(str2);
	String* str3 = new String(L"Value of boolean is: ", 21);
	GC::Register(str3);

	Console::WriteLine(str1);
	Console::Write(str2);
	Console::WriteLine(x+y);
	Console::Write(str3);
	Console::WriteLine(truthy);
	Console::WriteLine(new Object());

	GC::UnRegister(str1);
	GC::UnRegister(str2);
	GC::UnRegister(str3);

	GC::PrintEntries();

	return 0;
}