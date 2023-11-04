# CSNative

A small, futile, and WIP attempt to compile C# to native code. Instead of implementing a framework around .NET types, this project aims to directly translate C# types into C++ classes/C++ equivalent code.

For example, the project aims to convert this C# code:
```cs
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
#include "CSharp.Native/LiteralConvert.hpp"
#include "System.hpp"

using namespace System;

class Program
{
	static Int32 Main()
	{
		Console::WriteLine(LiteralConvert::ToString("Hello, World!"));
		return new LiteralConvert::ToInt32(0);
	}
}
```