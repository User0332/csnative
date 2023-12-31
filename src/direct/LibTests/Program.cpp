#define _CSNATIVE_IMPORT

#include "../Lib/CSharp.Native.Runtime/System.hpp"
#include "../Lib/CSharp.Native.Runtime/System/Collections/Generic.hpp"
#include <iostream>
#include <chrono>

using namespace System;
using namespace std::chrono;


class __declspec(dllexport) Program
{
	public:
		static Int32 Main();
};

Int32 Program::Main()
{
	asm(".global csnative_entrypoint");
	asm("csnative_entrypoint:");

	auto start = steady_clock::now();
	System::Reflection::Assembly* CSHARP_NATIVE_SYSTEM_ASSEMBLY_META = InitializeMetadata_ns3_CSharp_Native_Runtime();
	auto end = steady_clock::now();

	auto duration = end-start;

	// GC::Collect(
	// 	new Array<Object*>(
	// 		new Object*[0], 0
	// 	)
	// );

	std::wcout << "Initialization of Assembly Metadata [" << CSHARP_NATIVE_SYSTEM_ASSEMBLY_META->Name()->ToCpp() << "] took " << duration_cast<nanoseconds>(duration).count() << "ns" << std::endl;

	Int32 x = Int32(45);
	Int32 y = Int32(32);;
	Boolean truthy = x > y;

	String* str1 = new String(L"Hello, World!", 13);
	String* str2 = new String(L"Value of y\0+x is: ", 18);
	String* str3 = new String(L"Value of boolean is: ", 21);

	// GC::Collect(
	// 	new Array<Object*>(
	// 		new Object*[4]
	// 		{
	// 			str1, str2, str3, CSHARP_NATIVE_SYSTEM_ASSEMBLY_META
	// 		}, 4
	// 	)
	// );

	

	Console::WriteLine(
		CSHARP_NATIVE_SYSTEM_ASSEMBLY_META->Name()
	);

	Console::WriteLine(str1);
	Console::Write(str2);
	Console::WriteLine(x+y);
	Console::Write(str3);
	Console::WriteLine(truthy);
	Console::WriteLine(new Object());
	Console::WriteLine(str1->GetType()->Name);
	// Console::WriteLine(combined);

	// GC::UNSAFE_CollectAll();

	return Int32(0);
}

extern "C" int RuntimeDLLRunner()
{
	return Program::Main().ToNative();
}