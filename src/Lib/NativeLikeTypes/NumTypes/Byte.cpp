#include "../NumTypes.hpp"
#include "../../CSharp.Native/LoadedAssemblies.hpp"

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
		return new Byte(val);
	}

	Byte::~Byte()
	{

	}

	Type* Byte::GetType()
	{
		return CSharp::Native::ReflectionServices::LoadedAssemblyNameMap[new String("CSharp.Native.System")]->GetType(new String("System.Byte"));
	}
}