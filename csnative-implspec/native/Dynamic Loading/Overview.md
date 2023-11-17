# Dynamic Assembly Loading

Ideally, dynamic assembly loading should be avoided, and necessary projects should be `#include`d into the output `.cpp` (or whatever language the compiler targets as output) files to expose the necessary classes. However, compilers may opt to load `.dll` files into the compiled program at runtime to only load classes when needed at runtime. In order to do this, the compiler may require an assembly to have one or more `.meta` metadata files associated with it. If the user dynamically loads an assembly, all class members and visible members of the loaded assembly should be visible to the developer via Reflection. The implementation for this that the original CSNative direct implementation uses behaves as follows:

C#:
```cs

/* inside Main() */

MyLibrary.B b = new(); // class 'MyLibrary.B' exists outside of this assembly

```

C++
```cpp

/* inside main() */

System::Reflection::Assembly* _MyLibrary_DLL = System::Reflection::Assembly::LoadWithMeta("MyLibrary.dll", "MyLibrary.dll.meta");

CSharp::Native::ReflectionServices::InitializeClassDeclFromAssembly<B>(_MyLibrary_DLL);

B* b = new B(); // this assembly already has access to the declaration of 'B', but not the definition, which is added at runtime by invoking the assembly dependency
```