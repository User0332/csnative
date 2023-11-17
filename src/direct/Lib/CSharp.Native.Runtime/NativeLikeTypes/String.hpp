#include "Object.hpp"
#include <string>

#pragma once

namespace System
{
	class Int16;
	
	class DLLATTR Char : public Object
	{
		wchar_t inner;

		public:
			Char(wchar_t native);
			Char(Int16 c);
			~Char();

			String* ToString() const; // note the String* return val since this is a reference type
			wchar_t ToNative() const;
			Type* GetType();

			operator Char*() const; // all structs must define a boxing conversion operator
	};
	
	class DLLATTR String : public Object
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
			String* operator+(const String* other) const;
			String* operator+(const Char& other) const;
			Boolean operator==(const String* other) const;

			String* ToString() const; // note the String* return val since this is a reference type
			std::wstring ToCpp() const;
			Type* GetType();
	};
}