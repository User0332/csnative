#ifdef _CSNATIVE_IMPORT
#define _CSNATIVE_IMPORT
#endif

#include "../System.hpp"
#include <set>

#pragma once

namespace System
{
	class Object;
}

namespace CSharp::Native
{
	class __declspec(dllexport) GC
	{
		static std::set<System::Object*> alloc_objs;

		static std::set<System::Object*> ExamineRoot(System::Object* root);

		public:
			static void Register(System::Object* ptr);

			static void UnRegister(System::Object* ptr);

			static void PrintEntries();
			
			static void Collect(System::Array<System::Object*>* roots);
			
			static void UNSAFE_CollectAll();
	};
}