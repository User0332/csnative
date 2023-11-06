#include "../NumTypes.hpp"

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
		SByte* boxed = new SByte(val);
		GC::Register(boxed);

		return boxed;
	}

	SByte::~SByte()
	{
		GC::UnRegister(this);
	}
}