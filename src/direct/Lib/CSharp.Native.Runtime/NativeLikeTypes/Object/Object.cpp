#include "../Object.hpp"
#include "../String.hpp"
#include "../../CSharp.Native/LoadedAssemblies.hpp"

namespace System
{
	/* Object */
	Boolean Object::Equals(Object* a, Object* b)
	{
		bool res = false; // TODO: CHANGE LATER

		return Boolean(res);
	}

	Boolean Object::ReferenceEquals(Object* a, Object* b)
	{
		bool res = a == b;

		return Boolean(res);
	}

	Object::Object()
	{
		
	}

	String* Object::ToString()
	{
		return new String(L"System.Object");
	}

	Object::~Object()
	{

	}

	Type* Object::GetType()
	{
		return CSharp::Native::ReflectionServices::LoadedAssemblyNameMap[new String("CSharp.Native.Runtime")]->GetType(new String("System.Object"));
	}
}