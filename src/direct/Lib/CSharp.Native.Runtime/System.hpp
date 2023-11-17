#include "NativeLikeTypes/Object.hpp"
#include "NativeLikeTypes/NumTypes.hpp"
#include "NativeLikeTypes/String.hpp"

#pragma once

namespace System
{
	template <class T> class Array;
	
	template <class T, class ...Args> T CreateStackObject(Args... args)
	{
		return T(args...);
	}

	template <class T, class ...Args> T* CreateHeapObject(Args... args)
	{
		return new T(args...);
	}
}

namespace System::Reflection
{
	template <class T, class ...Args> T CreateObject(Args... args)
	{
		return new T(args...);
	}

	class DLLATTR AssemblyName : public Object
	{
		String* name;

		public:
			AssemblyName(String* not_full_name);
			Type* GetType();

			String* Name();

	};

	class DLLATTR Assembly : public Object
	{
		AssemblyName* name;
		Array<Type*>* types;

		protected:
			Assembly(String* not_full_name, Array<Type*>* types);

		public:
			AssemblyName* GetName();
			Array<Type*>* GetTypes();
			Type* GetType();
			Type* GetType(String* name);

			String* Name();
	};

	class DLLATTR FieldInfo : public Object
	{
		// Boolean is_prop;
		Object* Object::* addr;
		Type* type;

		public:
			String* Name;
			
			FieldInfo(String* name, Object* Object::* addr, Type* type /*, Boolean is_prop */);
			Object* GetValue(Object* obj);
			Type* GetType();
	};

	class DLLATTR PropertyInfo : public Object
	{
		Boolean is_func;
		Object* Object::* addr;
		Type* type;

		public:
			String* Name;
			Boolean IsReadOnly;

			PropertyInfo(String* name, Object* Object::* addr, Type* type, Boolean is_func, Boolean is_readonly);
			Object* GetValue(Object* obj);
			Type* GetType();
	};
}


namespace System
{
	class DLLATTR Type : public Object
	{
		Array<System::Reflection::FieldInfo*>* fields;

		protected:
			Type(
				System::Reflection::Assembly* assembly,
				String* name,
				Array<System::Reflection::FieldInfo*>* fields
			);

		public:
			Array<System::Reflection::FieldInfo*>* GetFields();

			System::Reflection::Assembly* Assembly; /* get; */
			String* Name; /* get; */
	};

	class DLLATTR Console // static class, so doesn't inherit from Object
	{
		// TODO:
			// [public] System::IO::TextWriter Out;
		public:
			static void Write(Object* obj);
			static void Write(String* string);

			static void WriteLine();
			static void WriteLine(Object* obj);
			static void WriteLine(String* string);
	};
}

DLLATTR System::Reflection::Assembly* InitializeMetadata_ns3_CSharp_Native_Runtime();