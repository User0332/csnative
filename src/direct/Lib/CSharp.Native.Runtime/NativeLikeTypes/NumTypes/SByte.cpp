#include "../NumTypes.hpp"
#include "../../CSharp.Native/LoadedAssemblies.hpp"
#include "../../CSharp.Native/GarbageCollector.hpp"

namespace System
{
	SByte::SByte()
	{
		val = 0;
	}

	SByte::SByte(char native)
	{
		val = native;
	}

	char SByte::ToNative()
	{
		return val;
	}

	SByte SByte::operator+()
	{
		return SByte(+val);
	}

	SByte SByte::operator-()
	{
		return SByte(-val);
	}

	SByte SByte::operator*(SByte other)
	{
		return SByte(val*other.val);
	}

	SByte SByte::operator/(SByte other)
	{
		return SByte(val/other.val);
	}

	SByte SByte::operator+(SByte other)
	{
		return SByte(val+other.val);
	}

	SByte SByte::operator-(SByte other)
	{
		return SByte(val-other.val);
	}

	SByte SByte::operator>>(SByte other)
	{
		return SByte(val>>other.val);
	}

	SByte SByte::operator<<(SByte other)
	{
		return SByte(val<<other.val);
	}

	Boolean SByte::operator>(SByte other)
	{
		return Boolean(val>other.val);
	}

	Boolean SByte::operator<(SByte other)
	{
		return Boolean(val<other.val);
	}

	Boolean SByte::operator==(SByte other)
	{
		return Boolean(val==other.val);
	}

	Boolean SByte::operator>=(SByte other)
	{
		return Boolean(val>=other.val);
	}

	Boolean SByte::operator<=(SByte other)
	{
		return Boolean(val<=other.val);
	}

	String* SByte::ToString()
	{
		return new String(std::to_string(val));
	}

	SByte::operator SByte *()
	{
		SByte* heap = new SByte(val);

		return heap;
	}

	SByte::~SByte()
	{

	}

	Type* SByte::GetType()
	{
		return CSharp::Native::ReflectionServices::LoadedAssemblyNameMap[new String("CSharp.Native.Runtime")]->GetType(new String("System.SByte"));
	}
}