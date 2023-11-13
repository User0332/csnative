# CSNative Direct

CSNative Direct aims to convert C# code directly to a C++ equivalent.

For example, the project aims to convert this C# code:
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
			Console::WriteLine(new String("Hello, World!"));

			return Int32(0);
		}
};

int main()
{
	int res = Program::Main().ToNative();

	GC::UNSAFE_CollectAll();

	return res;
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