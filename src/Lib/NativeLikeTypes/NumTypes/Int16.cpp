#include "../NumTypes.hpp"

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
}