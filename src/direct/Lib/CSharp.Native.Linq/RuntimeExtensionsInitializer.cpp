#include "RuntimeExtensionsInitializer.hpp"

namespace CSharp::Native::RuntimeExtensions
{
	using namespace System;
	using namespace System::Reflection;

	class SystemRuntimeExtensionsAssembly : public Assembly
	{
		public:
			SystemRuntimeExtensionsAssembly(String* not_full_name, Array<Type*>* types) : Reflection::Assembly(not_full_name, types)
			{
				
			};

			Type* GetType()
			{
				return CSharp::Native::ReflectionServices::LoadedAssemblyNameMap[new String("CSharp.Native.RuntimeExtensions")]->GetType(new String("CSharp.Native.RuntimeExtensions.SystemRuntimeExtensionsAssembly"));
			}
	};

	class SystemRuntimeExtensionsType : public Type
	{
		public:
			SystemRuntimeExtensionsType(
				System::Reflection::Assembly* assembly,
				String* name,
				Array<System::Reflection::FieldInfo*>* fields
			) : Type(assembly, name, fields)
			{
				
			};

			Type* GetType()
			{
				return CSharp::Native::ReflectionServices::LoadedAssemblyNameMap[new String("CSharp.Native.RuntimeExtensions")]->GetType(new String("CSharp.Native.RuntimeExtensions.SystemRuntimeExtensionsType"));
			}
	};
}

System::Reflection::Assembly* InitializeMetadata_ns3_CSharp_Native_RuntimeExtensions()
{
	using namespace System::Reflection;
	using namespace CSharp::Native::RuntimeExtensions;

	return new SystemRuntimeExtensionsAssembly(nullptr, nullptr);
}