#ifdef _CSNATIVE_IMPORT
#define _CSNATIVE_IMPORT
#endif

#include <map>
#include "../System.hpp"

#pragma once



namespace CSharp::Native::ReflectionServices
{
	__declspec(dllexport) extern std::map<System::String*, System::Reflection::Assembly*> LoadedAssemblyNameMap;
}