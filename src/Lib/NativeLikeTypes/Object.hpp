#pragma once

namespace System
{
	class String;
	class Boolean;
	
	class Object
	{
		public:
			static Boolean Equals(Object* a, Object* b);
			static Boolean ReferenceEquals(Object* a, Object* b);

			Object();
			virtual String* ToString();
	};

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