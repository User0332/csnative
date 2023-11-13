#include "../NumTypes.hpp"
#include "../../CSharp.Native/LoadedAssemblies.hpp"
#include "../../CSharp.Native/GarbageCollector.hpp"

namespace System
{
	Int32::Int32()
	{
		val = 0;
	}

	Int32::Int32(int native)
	{
		val = native;
	}

	int Int32::ToNative()
	{
		return val;
	}

	Int32 Int32::operator+()
	{
		return Int32(+val);
	}

	Int32 Int32::operator-()
	{
		return Int32(-val);
	}

	Int32 Int32::operator*(Int32 other)
	{
		return Int32(val*other.val);
	}

	Int32 Int32::operator/(Int32 other)
	{
		return Int32(val/other.val);
	}

	Int32 Int32::operator+(Int32 other)
	{
		return Int32(val+other.val);
	}

	Int32 Int32::operator-(Int32 other)
	{
		return Int32(val-other.val);
	}

	Int32 Int32::operator>>(Int32 other)
	{
		return Int32(val>>other.val);
	}

	Int32 Int32::operator<<(Int32 other)
	{
		return Int32(val<<other.val);
	}

	Boolean Int32::operator>(Int32 other)
	{
		return Boolean(val>other.val);
	}

	Boolean Int32::operator<(Int32 other)
	{
		return Boolean(val<other.val);
	}

	Boolean Int32::operator==(Int32 other)
	{
		return Boolean(val==other.val);
	}

	Boolean Int32::operator>=(Int32 other)
	{
		return Boolean(val>=other.val);
	}

	Boolean Int32::operator<=(Int32 other)
	{
		return Boolean(val<=other.val);
	}

	Int32& Int32::operator+=(const Int32& other)
	{
		this->val+=other.val;
		
		return *this;
	}

	Int32& Int32::operator-=(const Int32& other)
	{
		this->val-=other.val;
		
		return *this;
	}

	String* Int32::ToString()
	{
		return new String(std::to_string(val));
	}

	Int32::operator Int32 *()
	{
		Int32* heap = new Int32(val);

		CSharp::Native::GC::Register(heap);
		return heap;
	}

	Int32::~Int32()
	{

	}

	Type* Int32::GetType()
	{
		return CSharp::Native::ReflectionServices::LoadedAssemblyNameMap[new String("CSharp.Native.System")]->GetType(new String("System.Int32"));
	}
}