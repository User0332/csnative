#include "../NumTypes.hpp"

namespace System
{
	UInt16::UInt16()
	{
		val = 0;
	}

	UInt16::UInt16(unsigned short native)
	{
		val = native;
	}

	unsigned short UInt16::ToNative()
	{
		return val;
	}

	UInt16 UInt16::operator+()
	{
		return UInt16(+val);
	}

	UInt16 UInt16::operator-()
	{
		return UInt16(-val);
	}

	UInt16 UInt16::operator*(UInt16 other)
	{
		return UInt16(val*other.val);
	}

	UInt16 UInt16::operator/(UInt16 other)
	{
		return UInt16(val/other.val);
	}

	UInt16 UInt16::operator+(UInt16 other)
	{
		return UInt16(val+other.val);
	}

	UInt16 UInt16::operator-(UInt16 other)
	{
		return UInt16(val-other.val);
	}

	UInt16 UInt16::operator>>(UInt16 other)
	{
		return UInt16(val>>other.val);
	}

	UInt16 UInt16::operator<<(UInt16 other)
	{
		return UInt16(val<<other.val);
	}

	Boolean UInt16::operator>(UInt16 other)
	{
		return Boolean(val>other.val);
	}

	Boolean UInt16::operator<(UInt16 other)
	{
		return Boolean(val<other.val);
	}

	Boolean UInt16::operator==(UInt16 other)
	{
		return Boolean(val==other.val);
	}

	Boolean UInt16::operator>=(UInt16 other)
	{
		return Boolean(val>=other.val);
	}

	Boolean UInt16::operator<=(UInt16 other)
	{
		return Boolean(val<=other.val);
	}

	String* UInt16::ToString()
	{
		return new String(std::to_string(val));
	}
}