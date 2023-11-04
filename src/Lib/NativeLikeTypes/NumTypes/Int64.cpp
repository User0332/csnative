#include "../NumTypes.hpp"

namespace System
{
	Int64::Int64()
	{
		val = 0;
	}

	Int64::Int64(long long native)
	{
		val = native;
	}

	long long Int64::ToNative()
	{
		return val;
	}

	Int64 Int64::operator+()
	{
		return Int64(+val);
	}

	Int64 Int64::operator-()
	{
		return Int64(-val);
	}

	Int64 Int64::operator*(Int64 other)
	{
		return Int64(val*other.val);
	}

	Int64 Int64::operator/(Int64 other)
	{
		return Int64(val/other.val);
	}

	Int64 Int64::operator+(Int64 other)
	{
		return Int64(val+other.val);
	}

	Int64 Int64::operator-(Int64 other)
	{
		return Int64(val-other.val);
	}

	Int64 Int64::operator>>(Int64 other)
	{
		return Int64(val>>other.val);
	}

	Int64 Int64::operator<<(Int64 other)
	{
		return Int64(val<<other.val);
	}

	Boolean Int64::operator>(Int64 other)
	{
		return Boolean(val>other.val);
	}

	Boolean Int64::operator<(Int64 other)
	{
		return Boolean(val<other.val);
	}

	Boolean Int64::operator==(Int64 other)
	{
		return Boolean(val==other.val);
	}

	Boolean Int64::operator>=(Int64 other)
	{
		return Boolean(val>=other.val);
	}

	Boolean Int64::operator<=(Int64 other)
	{
		return Boolean(val<=other.val);
	}

	String* Int64::ToString()
	{
		return new String(std::to_string(val));
	}
}