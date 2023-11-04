#include "NativeLikeTypes/Object.hpp"
#include "NativeLikeTypes/NumTypes.hpp"
#include "NativeLikeTypes/Boolean.hpp"
#include "NativeLikeTypes/String.hpp"

#pragma once

namespace System
{
	

	class Char : public Object
	{
		wchar_t inner;

		public:
			Char(wchar_t native);
			Char(short native);
			Char(Int16 c);

			String* ToString(); // note the String* return val since this is a reference type
			wchar_t ToNative();
	};

	class Console // static class, so doesn't inherit from Object
	{
		// TODO:
			// [public] System::IO::TextWriter Out;
		public:
			static void Write(Object* obj);
			static void Write(String* string);

			static void WriteLine();
			static void WriteLine(Object* obj);
			static void WriteLine(String* string);
	};
}