#pragma once

namespace System
{
	class Boolean;
	class String;
	
	class Object
	{
		public:
			static Boolean Equals(Object* a, Object* b);
			static Boolean ReferenceEquals(Object* a, Object* b);

			Object();
			virtual String* ToString();
	};
}