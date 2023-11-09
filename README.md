# CSNative

A small WIP attempt to compile C# to native code. Instead of implementing a framework around .NET types, this project aims to directly translate C# types into C++ classes/C++ equivalent code.

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
#include "System.hpp"

using namespace System;

class Program
{
	public:
		static Int32 Main()
		{
			Console::WriteLine(new String("Hello, World!"));

			return Int32(0);
		}
};

int main()
{
	return Program::Main().ToNative();
}
```

Additionally, the project will add more native types that correspond to existing ones such as `int`, but without methods attached, similar to Java primitives.

For example:

```cs
public class Program
{
	static int Main()
	{
		intrinsic int x = 5i; // has no methods or properties, will be represented by a raw `int` value in C++
		int asObject = new(x);
		intrinsic int asIntrinsicIntAgain = asObject.ToNative();

		Console.WriteLine(asObject);
		Console.WriteLine(asIntrinsicInt); // may work after overloads for Console::WriteLine are added to support instrinsic types
	}
}
```

## Memory Management And Garbage Collection

Currently, `GarbageCollector.hpp` (`CSharp::Native::GC`) is deprecated and `CSharp::Native::HeapManagedObject<TObject>` should be used instead. Each function should only create heap-allocated objects with a `HeapManagedObject<TObject>` wrapper around the object, but should only pass arguments to functions as the raw object pointer (and functions should only accept arguments that are descended from `System::Object`). The wrapper class is a smart pointer, and should therefore be allocated on the stack. However, if a function intends to return a heap-allocated object (in the form of a pointer), it should not wrap the object in `HeapManagedObject<TObject>`.