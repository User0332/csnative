#include <map>

#pragma once

namespace System
{
	extern class String;

	namespace Reflection
	{
		extern class Assembly : public Object
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
	}
}

namespace CSharp::Native::ReflectionServices
{
	extern std::map<System::String*, System::Reflection::Assembly*> LoadedAssemblyNameMap;
}