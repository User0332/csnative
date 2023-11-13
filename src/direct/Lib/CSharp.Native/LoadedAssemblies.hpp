#include <map>
#include "../System.hpp"

#pragma once



namespace CSharp::Native::ReflectionServices
{
	extern std::map<System::String*, System::Reflection::Assembly*> LoadedAssemblyNameMap;
}