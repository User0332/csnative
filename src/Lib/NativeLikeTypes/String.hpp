#include "Object.hpp"
#include <string>

#pragma once

namespace System
{
	class Char;
	
	class String : public Object
	{
		std::wstring inner;

		public:
			String(std::wstring string);
			String(Char string[]);
			String(wchar_t string[]);
			String(std::string string);
			String(char string[]);

			// TODO: operator overloads
			String* operator+(String* other);
			String* operator+(Char other);

			String* ToString(); // note the String* return val since this is a reference type
			std::wstring ToCpp();
	};
}