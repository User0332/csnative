#include "../NumTypes.hpp"
#include "../../CSharp.Native/LoadedAssemblies.hpp"
#include "../../CSharp.Native/GarbageCollector.hpp"

namespace System
{
	Byte::Byte()
	{
		val = 0;
	}

	Byte::Byte(unsigned char native)
	{
		val = native;
	}

	unsigned char Byte::ToNative()
	{
		return val;
	}

	Byte Byte::operator+()
	{
		return Byte(+val);
	}

	Byte Byte::operator-()
	{
		return Byte(-val);
	}

	Byte Byte::operator*(Byte other)
	{
		return Byte(val*other.val);
	}

	Byte Byte::operator/(Byte other)
	{
		return Byte(val/other.val);
	}

	Byte Byte::operator+(Byte other)
	{
		return Byte(val+other.val);
	}

	Byte Byte::operator-(Byte other)
	{
		return Byte(val-other.val);
	}

	Byte Byte::operator>>(Byte other)
	{
		return Byte(val>>other.val);
	}

	Byte Byte::operator<<(Byte other)
	{
		return Byte(val<<other.val);
	}

	Boolean Byte::operator>(Byte other)
	{
		return Boolean(val>other.val);
	}

	Boolean Byte::operator<(Byte other)
	{
		return Boolean(val<other.val);
	}

	Boolean Byte::operator==(Byte other)
	{
		return Boolean(val==other.val);
	}

	Boolean Byte::operator>=(Byte other)
	{
		return Boolean(val>=other.val);
	}

	Boolean Byte::operator<=(Byte other)
	{
		return Boolean(val<=other.val);
	}

	String* Byte::ToString()
	{
		return new String(std::to_string(val));
	}

	Byte::operator Byte *()
	{
		Byte* heap = new Byte(val);

		return heap;
	}

	Byte::~Byte()
	{

	}

	Type* Byte::GetType()
	{
		return CSharp::Native::ReflectionServices::LoadedAssemblyNameMap[new String("CSharp.Native.Runtime")]->GetType(new String("System.Byte"));
	}
}