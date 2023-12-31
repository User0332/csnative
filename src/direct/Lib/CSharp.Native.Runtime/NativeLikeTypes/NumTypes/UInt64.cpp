#include "../NumTypes.hpp"
#include "../../CSharp.Native/LoadedAssemblies.hpp"
#include "../../CSharp.Native/GarbageCollector.hpp"

namespace System
{
	UInt64::UInt64()
	{
		val = 0;
	}

	UInt64::UInt64(unsigned long long native)
	{
		val = native;
	}

	unsigned long long UInt64::ToNative()
	{
		return val;
	}

	UInt64 UInt64::operator+()
	{
		return UInt64(+val);
	}

	UInt64 UInt64::operator-()
	{
		return UInt64(-val);
	}

	UInt64 UInt64::operator*(UInt64 other)
	{
		return UInt64(val*other.val);
	}

	UInt64 UInt64::operator/(UInt64 other)
	{
		return UInt64(val/other.val);
	}

	UInt64 UInt64::operator+(UInt64 other)
	{
		return UInt64(val+other.val);
	}

	UInt64 UInt64::operator-(UInt64 other)
	{
		return UInt64(val-other.val);
	}

	UInt64 UInt64::operator>>(UInt64 other)
	{
		return UInt64(val>>other.val);
	}

	UInt64 UInt64::operator<<(UInt64 other)
	{
		return UInt64(val<<other.val);
	}

	Boolean UInt64::operator>(UInt64 other)
	{
		return Boolean(val>other.val);
	}

	Boolean UInt64::operator<(UInt64 other)
	{
		return Boolean(val<other.val);
	}

	Boolean UInt64::operator==(UInt64 other)
	{
		return Boolean(val==other.val);
	}

	Boolean UInt64::operator>=(UInt64 other)
	{
		return Boolean(val>=other.val);
	}

	Boolean UInt64::operator<=(UInt64 other)
	{
		return Boolean(val<=other.val);
	}

	String* UInt64::ToString()
	{
		return new String(std::to_string(val));
	}

	UInt64::operator UInt64 *()
	{
		UInt64* heap = new UInt64(val);

		return heap;
	}

	UInt64::~UInt64()
	{

	}

	Type* UInt64::GetType()
	{
		return CSharp::Native::ReflectionServices::LoadedAssemblyNameMap[new String("CSharp.Native.Runtime")]->GetType(new String("System.UInt64"));
	}
}