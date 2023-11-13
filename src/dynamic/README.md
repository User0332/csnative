#  CSNative Dynamic

This version of `CSNative` aims to compile C# to native code using a more reflection-based approach like the CLR does, with full reflection support, dynamic type loading, and other features. Hopefully, more optimizations will be added in the future to prevent every class from being dynamically loaded.

For example, it would convert the following C# code:
```cs
using System;
using CSharp.Native;

public class Program
{
	static int Main()
	{
		Console.WriteLine("Hello, World!");
		return 0;
	}
}
```

to something like this:
```cpp
#include "System.hpp"
#include "CSharp.Native/GarbageCollector.hpp"

using namespace System;
using namespace CSharp::Native;

class Program
{
	public:
		static Int32 Main()
		{
			Type CSType_NS_System_Console = LoadedAssemblies["CSharp.Native.System"]->LoadType("System.Console");
			Type CSType_NS_System_String = LoadedAssemblies["CSharp.Native.System"]->LoadType("System.String");

			CSType_NS_System_Console
				.GetMethod(
					"WriteLine", 
					MethodSpec.STATIC
				)
				.Call(
					CSType_NS_System_String
						.New("Hello, World!")
				);

			return Int32(0);
		}
};

extern "C" __declspec( dllexport ) InitializeCSNativeData()
{
	InitializeAssembly(
		"TestProgram",
		new Type[10] {
			Type.GenerateMeta<Program>()
		}, 10
	)
}

int main()
{
	int res = Program::Main().ToNative();

	GC::UNSAFE_CollectAll();

	return res;
}
```