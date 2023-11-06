#include "../CSharp.Native/GarbageCollector.hpp"

#pragma once

using namespace CSharp::Native;

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
			virtual ~Object();
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
			~Boolean();

			String* ToString();

			operator Boolean*(); // all structs must define a boxing conversion operator
	};
}