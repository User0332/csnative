#include "../Object.hpp"
#include "../String.hpp"

namespace System
{
	/* Object */
	Boolean Object::Equals(Object* a, Object* b)
	{
		return Boolean(false);
	}

	Boolean Object::ReferenceEquals(Object* a, Object* b)
	{
		return Boolean(a == b);
	}

	Object::Object() { }

	String* Object::ToString()
	{
		return new String(L"System.Object");
	}
}