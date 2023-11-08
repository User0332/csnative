#include "../System.hpp"
#include "../CSharp.Native/HeapObject.hpp"
#include <iostream>

using namespace CSharp::Native;

namespace System
{
	void Console::Write(Object* obj)
	{
		Write(obj->ToString());
	}

	void Console::Write(String* string)
	{
		std::wcout << string->ToCpp();
	}

	void Console::WriteLine()
	{
		std::cout << std::endl;
	}
	
	void Console::WriteLine(Object* obj)
	{
		WriteLine(obj->ToString());
	}

	void Console::WriteLine(String* string)
	{
		Write(string);
		WriteLine();
	}
}