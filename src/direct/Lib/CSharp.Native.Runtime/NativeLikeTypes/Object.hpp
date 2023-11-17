#ifdef _CSNATIVE_IMPORT

#define DLLATTR __declspec(dllimport)

#else

#define DLLATTR __declspec(dllexport)

#endif

#pragma once

namespace System
{

	class String;
	class Type;
	class Boolean;
	
	class DLLATTR Object
	{
		public:
			static Boolean Equals(Object* a, Object* b);
			static Boolean ReferenceEquals(Object* a, Object* b);

			Object();
			virtual ~Object();
			virtual String* ToString();
			virtual Type* GetType();
	};

	class DLLATTR Boolean : public Object
	{
		bool val;
		
		public:
			explicit operator bool();

			bool ToNative();

			Boolean();
			Boolean(bool native);
			~Boolean();

			String* ToString();
			Type* GetType();

			operator Boolean*(); // all structs must define a boxing conversion operator
	};
}