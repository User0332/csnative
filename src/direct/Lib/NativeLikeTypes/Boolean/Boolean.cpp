#include "../Object.hpp"
#include "../String.hpp"
#include "../../CSharp.Native/LoadedAssemblies.hpp"
#include "../../CSharp.Native/GarbageCollector.hpp"

namespace System
{
	Boolean::operator bool()
	{
		return val;
	}

	bool Boolean::ToNative()
	{
		return val;
	}

	Boolean::Boolean()
	{
		val = false;
	}

	Boolean::Boolean(bool other)
	{
		val = other;
	}

	String* Boolean::ToString()
	{
		if (val) return new String(L"True");
		
		return new String(L"False");
	}

	Boolean::operator Boolean *()
	{
		Boolean* heap = new Boolean(val);

		CSharp::Native::GC::Register(heap);
		return heap;
	}

	Boolean::~Boolean()
	{
		
	}

	Type* Boolean::GetType()
	{
		return CSharp::Native::ReflectionServices::LoadedAssemblyNameMap[new String("CSharp.Native.System")]->GetType(new String("System.Boolean"));
	}
}