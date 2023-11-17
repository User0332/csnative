#include "../String.hpp"
#include "../NumTypes.hpp"
#include "../../CSharp.Native/LoadedAssemblies.hpp"
#include "../../CSharp.Native/GarbageCollector.hpp"

namespace System
{
	Char::Char(wchar_t native)
	{
		inner = native;
	}
	
	Char::Char(Int16 c)
	{
		inner = (wchar_t) c.ToNative();
	}

	String* Char::ToString() const
	{
		return new String(std::wstring(1, inner));
	}

	wchar_t Char::ToNative() const
	{
		return inner;
	}

	Char::operator Char *() const
	{
		Char* heap = new Char(inner);

		return heap;
	}

	Char::~Char()
	{

	}

	Type* Char::GetType()
	{
		return CSharp::Native::ReflectionServices::LoadedAssemblyNameMap[new String("CSharp.Native.Runtime")]->GetType(new String("System.Char"));
	}
}