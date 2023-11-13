#include "LoadedAssemblies.hpp"
#include "../System.hpp"

namespace CSharp::Native::ReflectionServices
{
	std::map<System::String*, System::Reflection::Assembly*> LoadedAssemblyNameMap = 
		std::map<System::String*, System::Reflection::Assembly*>();
}