#include "../../Lib/System.hpp"
#include <iostream>
using namespace System;

class Program
{
	public:
		static Int32 Main()
		{
			Int32 x = Int32(5)+Int32(6);
			Int32 y = x<<Int32(3);
			Int32 z = y-Int32(3);

			// debug
			std::cout << z.ToNative();

			return Int32(0);
		}
};

int main()
{
	return Program::Main().ToNative();
}