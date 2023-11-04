#include "Object.hpp"

#pragma once

namespace System
{
	class Boolean : public Object
	{
		bool val;
		
		public:
			explicit operator bool();

			bool ToNative();

			Boolean();
			Boolean(bool native);

			String* ToString();
	};
}