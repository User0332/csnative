#include "../System.hpp"
#include <iostream>

namespace System
{
	void Console::Write(unique_ptr<Object> obj)
	{
		Write(unique_ptr<String>(obj->ToString()));
	}

	void Console::Write(unique_ptr<String> string)
	{
		std::wcout << string->ToCpp();
	}

	void Console::WriteLine()
	{
		std::cout << std::endl;
	}
	
	void Console::WriteLine(unique_ptr<Object> obj)
	{
		WriteLine(unique_ptr<String>(obj->ToString()));
	}

	void Console::WriteLine(unique_ptr<String> string)
	{
		Write(std::move(string));
		WriteLine();
	}
}