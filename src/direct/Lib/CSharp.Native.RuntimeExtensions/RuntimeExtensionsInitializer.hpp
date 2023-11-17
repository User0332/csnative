#ifndef _CSNATIVE_IMPORT

#define _CSNATIVE_IMPORT

#include "../CSharp.Native.Runtime/System.hpp"
#include "../CSharp.Native.Runtime/CSharp.Native/LoadedAssemblies.hpp"

#undef _CSNATIVE_IMPORT
#undef DLLATTR

#define DLLATTR __declspec(dllexport)

#else 

#include "../CSharp.Native.Runtime/System.hpp"

#endif


System::Reflection::Assembly* DLLATTR InitializeMetadata_ns3_CSharp_Native_RuntimeExtensions();