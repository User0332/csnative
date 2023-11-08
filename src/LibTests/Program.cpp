#include "../Lib/System.hpp"
#include "../Lib/CSharp.Native/HeapObject.hpp"
#include <iostream>

using namespace System;
using namespace CSharp::Native;

int main()
{
	Int32 x = Int32(45);
	Int32 y = Int32(6);
	Boolean truthy = x > y;

	HeapManagedObject<String> str1 = HeapManagedObject<String>(new String(L"Hello, World!", 13));
	HeapManagedObject<String> str2 = HeapManagedObject<String>(new String(L"Value of y\0+x is: ", 18));
	HeapManagedObject<String> str3 = HeapManagedObject<String>(new String(L"Value of boolean is: ", 21));

	Console::WriteLine(str1);
	Console::Write(str2);
	Console::WriteLine(HeapManagedObject<Int32>(x+y));
	Console::Write(str3);
	Console::WriteLine(HeapManagedObject<Boolean>(truthy));
	Console::WriteLine(HeapManagedObject<Object>(new Object()));

	return 0;
}