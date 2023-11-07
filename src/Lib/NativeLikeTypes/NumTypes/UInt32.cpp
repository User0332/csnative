#include "../NumTypes.hpp"

namespace System
{
	UInt32::UInt32()
	{
		val = 0;
	}

	UInt32::UInt32(unsigned int native)
	{
		val = native;
	}

	unsigned int UInt32::ToNative()
	{
		return val;
	}

	UInt32 UInt32::operator+()
	{
		return UInt32(+val);
	}

	UInt32 UInt32::operator-()
	{
		return UInt32(-val);
	}

	UInt32 UInt32::operator*(UInt32 other)
	{
		return UInt32(val*other.val);
	}

	UInt32 UInt32::operator/(UInt32 other)
	{
		return UInt32(val/other.val);
	}

	UInt32 UInt32::operator+(UInt32 other)
	{
		return UInt32(val+other.val);
	}

	UInt32 UInt32::operator-(UInt32 other)
	{
		return UInt32(val-other.val);
	}

	UInt32 UInt32::operator>>(UInt32 other)
	{
		return UInt32(val>>other.val);
	}

	UInt32 UInt32::operator<<(UInt32 other)
	{
		return UInt32(val<<other.val);
	}

	Boolean UInt32::operator>(UInt32 other)
	{
		return Boolean(val>other.val);
	}

	Boolean UInt32::operator<(UInt32 other)
	{
		return Boolean(val<other.val);
	}

	Boolean UInt32::operator==(UInt32 other)
	{
		return Boolean(val==other.val);
	}

	Boolean UInt32::operator>=(UInt32 other)
	{
		return Boolean(val>=other.val);
	}

	Boolean UInt32::operator<=(UInt32 other)
	{
		return Boolean(val<=other.val);
	}

	String* UInt32::ToString()
	{
		return new String(std::to_string(val));
	}

	UInt32::operator UInt32 *()
	{
		return new UInt32(val);
	}

	UInt32::~UInt32()
	{

	}
}