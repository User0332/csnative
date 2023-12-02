#include "System.hpp"
#include "System/Collections/Generic.hpp"
#include "CSharp.Native/LoadedAssemblies.hpp"

namespace System::Reflection
{
	AssemblyName::AssemblyName(String* not_full_name)
	{
		
		name = not_full_name;
	}

	String* AssemblyName::Name()
	{
		return name;
	}

	Type* AssemblyName::GetType()
	{
		return CSharp::Native::ReflectionServices::LoadedAssemblyNameMap[new String("CSharp.Native.Runtime")]->GetType(new String("System.Reflection.AssemblyName"));
	}

	Assembly::Assembly(String* not_full_name, Array::Intrinsic<Type*>* types)
	{
		
		name = new AssemblyName(not_full_name);
		this->types = types;
	}

	String* Assembly::Name()
	{
		return name->Name();
	}

	AssemblyName* Assembly::GetName()
	{
		return name;
	}

	Array::Intrinsic<Type*>* Assembly::GetTypes()
	{
		return types;
	}

	Type* Assembly::GetType()
	{
		return CSharp::Native::ReflectionServices::LoadedAssemblyNameMap[new String("CSharp.Native.Runtime")]->GetType(new String("System.Reflection.Assembly"));
	}

	Type* Assembly::GetType(String* name)
	{
		System::Collections::Generic::IEnumerator<Type*>* enumerator = this->GetTypes()->GetEnumerator();

		try
		{
			while (enumerator->MoveNext())
			{
				Type* curr = enumerator->Current();

				if (curr->Name->operator==(name))
				{
					return curr;
				}
			}
		}
		catch(...) {}; // TODO: make this catch System.Exception


		enumerator->Dispose();

		return nullptr;
	}

	FieldInfo::FieldInfo(
		String* name, Object* Object::* addr,
		Type* type /*, Boolean is_prop */)
	{
		
		Name = name;
		// this->is_prop = is_prop
		this->addr = addr;
		this->type = type;
	}

	Object* FieldInfo::GetValue(Object* obj)
	{
		if (obj->GetType() != type) throw; /* new <specific-exc-type> */
		
		return obj->*addr;
	}

	Type* FieldInfo::GetType()
	{
		return CSharp::Native::ReflectionServices::LoadedAssemblyNameMap[new String("CSharp.Native.Runtime")]->GetType(new String("System.Reflection.FieldInfo"));
	}

	PropertyInfo::PropertyInfo(String* name, Object* Object::* addr, Type* type, Boolean is_func, Boolean is_readonly)
	{
		Name = name;
		this->addr = addr;
		this->type = type;
		this->is_func = is_func;
		IsReadOnly = is_readonly;
	}

	Object* PropertyInfo::GetValue(Object* obj)
	{
		if (obj->GetType() != type) throw; /* new <specific-exc-type> */
		
		if (!is_func) return obj->*addr;

		return ((Object* (*)()) (obj->*addr))();
	}

	Type* PropertyInfo::GetType()
	{
		return CSharp::Native::ReflectionServices::LoadedAssemblyNameMap[new String("CSharp.Native.Runtime")]->GetType(new String("System.Reflection.PropertyInfo"));		
	}
}

namespace System
{
	class SystemRuntimeAssembly : public Reflection::Assembly
	{
		public:
			SystemRuntimeAssembly(String* not_full_name, Array::Intrinsic<Type*>* types) : Reflection::Assembly(not_full_name, types)
			{
				
			};

			Type* GetType()
			{
				return CSharp::Native::ReflectionServices::LoadedAssemblyNameMap[new String("CSharp.Native.Runtime")]->GetType(new String("System.SystemRuntimeAssembly"));
			}
	};

	class SystemRuntimeType : public Type
	{
		public:
			SystemRuntimeType(
				System::Reflection::Assembly* assembly,
				String* name,
				Array::Intrinsic<System::Reflection::FieldInfo*>* fields
			) : Type(assembly, name, fields)
			{
				
			};

			Type* GetType()
			{
				return CSharp::Native::ReflectionServices::LoadedAssemblyNameMap[new String("CSharp.Native.Runtime")]->GetType(new String("System.SystemRuntimeType"));
			}
	};

	Type::Type(
		System::Reflection::Assembly* assembly,
		String* name,
		Array::Intrinsic<System::Reflection::FieldInfo*>* fields)
	{
		
		Assembly = assembly;
		Name = name;
		this->fields = fields;
	}

	Array::Intrinsic<System::Reflection::FieldInfo*>* Type::GetFields()
	{
		return fields;
	}
}

DLLATTR System::Reflection::Assembly* InitializeMetadata_ns3_CSharp_Native_Runtime()
{
	using namespace System;

	String* assembly_name = new String("CSharp.Native.Runtime");

	SystemRuntimeAssembly* assembly = new SystemRuntimeAssembly(
		assembly_name,
		(Array::Intrinsic<Type*>*)
		new Array::Intrinsic<SystemRuntimeType*>(
			new SystemRuntimeType*[19] {
				new SystemRuntimeType(
					(Reflection::Assembly*) nullptr,
					new String("System.Boolean"), 
					new Array::Intrinsic<Reflection::FieldInfo*>()
				),
				new SystemRuntimeType(
					(Reflection::Assembly*) nullptr,
					new String("System.Char"), 
					new Array::Intrinsic<Reflection::FieldInfo*>()
				),
				new SystemRuntimeType(
					(Reflection::Assembly*) nullptr,
					new String("System.Byte"), 
					new Array::Intrinsic<Reflection::FieldInfo*>()
				),
				new SystemRuntimeType(
					(Reflection::Assembly*) nullptr,
					new String("System.SByte"), 
					new Array::Intrinsic<Reflection::FieldInfo*>()
				),
				new SystemRuntimeType(
					(Reflection::Assembly*) nullptr,
					new String("System.UInt16"), 
					new Array::Intrinsic<Reflection::FieldInfo*>()
				),
				new SystemRuntimeType(
					(Reflection::Assembly*) nullptr,
					new String("System.Int16"), 
					new Array::Intrinsic<Reflection::FieldInfo*>()
				),
				new SystemRuntimeType(
					(Reflection::Assembly*) nullptr,
					new String("System.UInt32"), 
					new Array::Intrinsic<Reflection::FieldInfo*>()
				),
				new SystemRuntimeType(
					(Reflection::Assembly*) nullptr,
					new String("System.Int32"), 
					new Array::Intrinsic<Reflection::FieldInfo*>()
				),
				new SystemRuntimeType(
					(Reflection::Assembly*) nullptr,
					new String("System.UInt64"), 
					new Array::Intrinsic<Reflection::FieldInfo*>()
				),
				new SystemRuntimeType(
					(Reflection::Assembly*) nullptr,
					new String("System.Int64"), 
					new Array::Intrinsic<Reflection::FieldInfo*>()
				),
				new SystemRuntimeType(
					(Reflection::Assembly*) nullptr,
					new String("System.String"), 
					new Array::Intrinsic<Reflection::FieldInfo*>()
				),
				new SystemRuntimeType(
					(Reflection::Assembly*) nullptr,
					new String("System.Array"), 
					new Array::Intrinsic<Reflection::FieldInfo*>()
				),
				new SystemRuntimeType(
					(Reflection::Assembly*) nullptr,
					new String("System.Console"), 
					new Array::Intrinsic<Reflection::FieldInfo*>()
				),
				new SystemRuntimeType(
					(Reflection::Assembly*) nullptr,
					new String("System.Type"), 
					new Array::Intrinsic<Reflection::FieldInfo*>()
				),
				new SystemRuntimeType(
					(Reflection::Assembly*) nullptr,
					new String("System.SystemRuntimeAssembly"), 
					new Array::Intrinsic<Reflection::FieldInfo*>()
				),
				new SystemRuntimeType(
					(Reflection::Assembly*) nullptr,
					new String("System.SystemRuntimeType"), 
					new Array::Intrinsic<Reflection::FieldInfo*>()
				),
				new SystemRuntimeType(
					(Reflection::Assembly*) nullptr,
					new String("System.Reflection.Assembly"), 
					new Array::Intrinsic<Reflection::FieldInfo*>()
				),
				new SystemRuntimeType(
					(Reflection::Assembly*) nullptr,
					new String("System.Reflection.AssemblyName"), 
					new Array::Intrinsic<Reflection::FieldInfo*>()
				),
				new SystemRuntimeType(
					(Reflection::Assembly*) nullptr,
					new String("System.Reflection.FieldInfo"), 
					new Array::Intrinsic<Reflection::FieldInfo*>()
				),
			}, 19
		)
	);

	System::Collections::Generic::IEnumerator<Type*>* enumerator = assembly->GetTypes()->GetEnumerator();

	try
	{
		while (enumerator->MoveNext())
		{
			enumerator->Current()->Assembly = assembly;
		}
	}
	catch(...) {}; // TODO: make this catch System.Exception


	enumerator->Dispose();

	CSharp::Native::ReflectionServices::LoadedAssemblyNameMap[assembly_name] = assembly;

	return assembly;
}