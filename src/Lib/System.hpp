#include "NativeLikeTypes/Object.hpp"
#include "NativeLikeTypes/NumTypes.hpp"
#include "NativeLikeTypes/String.hpp"
#include <memory>

using std::unique_ptr;

#pragma once

namespace System
{
	class Console // static class, so doesn't inherit from Object
	{
		// TODO:
			// [public] System::IO::TextWriter Out;
		public:
			static void Write(unique_ptr<Object> obj);
			static void Write(unique_ptr<String> string);

			static void WriteLine();
			static void WriteLine(unique_ptr<Object> obj);
			static void WriteLine(unique_ptr<String> string);
	};
}