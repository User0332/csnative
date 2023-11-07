#include "../Object.hpp"
#include "../String.hpp"
#include "../../CSharp.Native/GarbageCollector.hpp"

using namespace CSharp::Native;

namespace System
{
	/* Object */
	Boolean Object::Equals(Object* a, Object* b)
	{
		GC::Register(a);
		GC::Register(b);

		bool res = false; // TODO: CHANGE LATER

		GC::UnRegister(a);
		GC::UnRegister(b);

		return Boolean(res);
	}

	Boolean Object::ReferenceEquals(Object* a, Object* b)
	{
		GC::Register(a);
		GC::Register(b);

		bool res = a == b;

		GC::UnRegister(a);
		GC::UnRegister(b);

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
}