#include "Object.hpp"
#include "Boolean.hpp"
#include "String.hpp"
#include <string>

#pragma once

namespace System
{
	class Int64 : public Object
	{
		long long val;

		public:

			// Note that methods do not return or accept pointers since Int64 is a struct/value stored type in C# (same for bool)

			/* Binary */
			Int64 operator+(Int64 other);
			Int64 operator-(Int64 other);
			Int64 operator*(Int64 other);
			Int64 operator/(Int64 other);
			Int64 operator>>(Int64 other);
			Int64 operator<<(Int64 other);


			/* Unary */
			Int64 operator+();
			Int64 operator-();

			/* Logical */
			Boolean operator>(Int64 other);
			Boolean operator<(Int64 other);
			Boolean operator==(Int64 other);
			Boolean operator>=(Int64 other);
			Boolean operator<=(Int64 other);

			long long ToNative();

			Int64();
			Int64(long long native);

			String* ToString();
	};

	class Int32 : public Object
	{
		int val;

		public:

			// Note that methods do not return or accept pointers since Int32 is a struct/value stored type in C# (same for bool)

			/* Binary */
			Int32 operator+(Int32 other);
			Int32 operator-(Int32 other);
			Int32 operator*(Int32 other);
			Int32 operator/(Int32 other);
			Int32 operator>>(Int32 other);
			Int32 operator<<(Int32 other);


			/* Unary */
			Int32 operator+();
			Int32 operator-();

			/* Logical */
			Boolean operator>(Int32 other);
			Boolean operator<(Int32 other);
			Boolean operator==(Int32 other);
			Boolean operator>=(Int32 other);
			Boolean operator<=(Int32 other);

			int ToNative();

			Int32();
			Int32(int native);

			String* ToString();
	};

	class Int16 : public Object
	{
		short val;

		public:
						/* Binary */
			Int16 operator+(Int16 other);
			Int16 operator-(Int16 other);
			Int16 operator*(Int16 other);
			Int16 operator/(Int16 other);
			Int16 operator>>(Int16 other);
			Int16 operator<<(Int16 other);


			/* Unary */
			Int16 operator+();
			Int16 operator-();

			/* Logical */
			Boolean operator>(Int16 other);
			Boolean operator<(Int16 other);
			Boolean operator==(Int16 other);
			Boolean operator>=(Int16 other);
			Boolean operator<=(Int16 other);

			short ToNative();

			Int16();
			Int16(short native);

			String* ToString();
	};

	class SByte : public Object
	{
		char val;

		public:
						/* Binary */
			SByte operator+(SByte other);
			SByte operator-(SByte other);
			SByte operator*(SByte other);
			SByte operator/(SByte other);
			SByte operator>>(SByte other);
			SByte operator<<(SByte other);


			/* Unary */
			SByte operator+();
			SByte operator-();

			/* Logical */
			Boolean operator>(SByte other);
			Boolean operator<(SByte other);
			Boolean operator==(SByte other);
			Boolean operator>=(SByte other);
			Boolean operator<=(SByte other);

			char ToNative();

			SByte();
			SByte(char native);

			String* ToString();
	};

	class UInt64 : public Object
	{
		unsigned long long val;

		public:

			// Note that methods do not return or accept pointers since UInt64 is a struct/value stored type in C# (same for bool)

			/* Binary */
			UInt64 operator+(UInt64 other);
			UInt64 operator-(UInt64 other);
			UInt64 operator*(UInt64 other);
			UInt64 operator/(UInt64 other);
			UInt64 operator>>(UInt64 other);
			UInt64 operator<<(UInt64 other);


			/* Unary */
			UInt64 operator+();
			UInt64 operator-();

			/* Logical */
			Boolean operator>(UInt64 other);
			Boolean operator<(UInt64 other);
			Boolean operator==(UInt64 other);
			Boolean operator>=(UInt64 other);
			Boolean operator<=(UInt64 other);

			unsigned long long ToNative();

			UInt64();
			UInt64(unsigned long long native);

			String* ToString();
	};

	class UInt32 : public Object
	{
		unsigned int val;

		public:

			// Note that methods do not return or accept pointers since UInt32 is a struct/value stored type in C# (same for bool)

			/* Binary */
			UInt32 operator+(UInt32 other);
			UInt32 operator-(UInt32 other);
			UInt32 operator*(UInt32 other);
			UInt32 operator/(UInt32 other);
			UInt32 operator>>(UInt32 other);
			UInt32 operator<<(UInt32 other);


			/* Unary */
			UInt32 operator+();
			UInt32 operator-();

			/* Logical */
			Boolean operator>(UInt32 other);
			Boolean operator<(UInt32 other);
			Boolean operator==(UInt32 other);
			Boolean operator>=(UInt32 other);
			Boolean operator<=(UInt32 other);

			unsigned int ToNative();

			UInt32();
			UInt32(unsigned int native);

			String* ToString();
	};

	class UInt16 : public Object
	{
		unsigned short val;

		public:
						/* Binary */
			UInt16 operator+(UInt16 other);
			UInt16 operator-(UInt16 other);
			UInt16 operator*(UInt16 other);
			UInt16 operator/(UInt16 other);
			UInt16 operator>>(UInt16 other);
			UInt16 operator<<(UInt16 other);


			/* Unary */
			UInt16 operator+();
			UInt16 operator-();

			/* Logical */
			Boolean operator>(UInt16 other);
			Boolean operator<(UInt16 other);
			Boolean operator==(UInt16 other);
			Boolean operator>=(UInt16 other);
			Boolean operator<=(UInt16 other);

			unsigned short ToNative();

			UInt16();
			UInt16(unsigned short native);

			String* ToString();
	};

	class Byte : public Object
	{
		unsigned char val;

		public:
						/* Binary */
			Byte operator+(Byte other);
			Byte operator-(Byte other);
			Byte operator*(Byte other);
			Byte operator/(Byte other);
			Byte operator>>(Byte other);
			Byte operator<<(Byte other);


			/* Unary */
			Byte operator+();
			Byte operator-();

			/* Logical */
			Boolean operator>(Byte other);
			Boolean operator<(Byte other);
			Boolean operator==(Byte other);
			Boolean operator>=(Byte other);
			Boolean operator<=(Byte other);

			unsigned char ToNative();

			Byte();
			Byte(unsigned char native);

			String* ToString();
	};
}