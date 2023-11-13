#include "../NumTypes.hpp"
#include "../../CSharp.Native/LoadedAssemblies.hpp"
#include "../../CSharp.Native/GarbageCollector.hpp"

namespace System
{
	Int16::Int16()
	{
		val = 0;
	}

	Int16::Int16(short native)
	{
		val = native;
	}

	short Int16::ToNative()
	{
		return val;
	}

	Int16 Int16::operator+()
	{
		return Int16(+val);
	}

	Int16 Int16::operator-()
	{
		return Int16(-val);
	}

	Int16 Int16::operator*(Int16 other)
	{
		return Int16(val*other.val);
	}

	Int16 Int16::operator/(Int16 other)
	{
		return Int16(val/other.val);
	}

	Int16 Int16::operator+(Int16 other)
	{
		return Int16(val+other.val);
	}

	Int16 Int16::operator-(Int16 other)
	{
		return Int16(val-other.val);
	}

	Int16 Int16::operator>>(Int16 other)
	{
		return Int16(val>>other.val);
	}

	Int16 Int16::operator<<(Int16 other)
	{
		return Int16(val<<other.val);
	}

	Boolean Int16::operator>(Int16 other)
	{
		return Boolean(val>other.val);
	}

	Boolean Int16::operator<(Int16 other)
	{
		return Boolean(val<other.val);
	}

	Boolean Int16::operator==(Int16 other)
	{
		return Boolean(val==other.val);
	}

	Boolean Int16::operator>=(Int16 other)
	{
		return Boolean(val>=other.val);
	}

	Boolean Int16::operator<=(Int16 other)
	{
		return Boolean(val<=other.val);
	}

	String* Int16::ToString()
	{
		return new String(std::to_string(val));
	}

	Int16::operator Int16 *()
	{
		Int16* heap = new Int16(val);

		CSharp::Native::GC::Register(heap);
		return heap;
	}

	Int16::~Int16()
	{

	}

	Type* Int16::GetType()
	{
		return CSharp::Native::ReflectionServices::LoadedAssemblyNameMap[new String("CSharp.Native.System")]->GetType(new String("System.Int16"));
	}
}