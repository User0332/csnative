#include "../System.hpp"
#include "../CSharp.Native/GarbageCollector.hpp"
#include <iostream>

using namespace CSharp::Native;

namespace System
{
	void Console::Write(Object* obj)
	{
		GC::Register(obj);
		Write(obj->ToString());
		GC::UnRegister(obj);
	}

	void Console::Write(String* string)
	{
		GC::Register(string);
		std::wcout << string->ToCpp();
		GC::UnRegister(string);
	}

	void Console::WriteLine()
	{
		std::cout << std::endl;
	}
	
	void Console::WriteLine(Object* obj)
	{
		GC::Register(obj);
		WriteLine(obj->ToString());
		GC::UnRegister(obj);
	}

	void Console::WriteLine(String* string)
	{
		GC::Register(string);
		Write(string);
		WriteLine();
		GC::UnRegister(string);
	}
}