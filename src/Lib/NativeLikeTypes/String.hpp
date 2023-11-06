#include "Object.hpp"
#include <string>

#pragma once

namespace System
{
	class Int16;
	
	class Char : public Object
	{
		wchar_t inner;

		public:
			Char(wchar_t native);
			Char(short native);
			Char(Int16 c);
			~Char();

			String* ToString(); // note the String* return val since this is a reference type
			wchar_t ToNative();

			operator Char*(); // all structs must define a boxing conversion operator
	};
	
	class String : public Object
	{
		std::wstring inner;

		public:
			String(std::wstring string);
			String(Char string[]);
			String(wchar_t string[]);
			String(wchar_t string[], size_t length);
			String(std::string string);
			String(char string[]);
			String(char string[], size_t length);
			~String();

			// TODO: operator overloads
			String* operator+(String* other);
			String* operator+(Char other);

			String* ToString(); // note the String* return val since this is a reference type
			std::wstring ToCpp();
	};
}