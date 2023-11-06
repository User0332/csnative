#include "../NumTypes.hpp"

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

	String* Int32::ToString()
	{
		return new String(std::to_string(val));
	}

	Int32::operator Int32 *()
	{
		Int32* boxed = new Int32(val);
		GC::Register(boxed);

		return boxed;
	}

	Int32::~Int32()
	{
		GC::UnRegister(this);
	}
}