#include "../NativeLikeTypes/Object.hpp"
#include <vector>

#pragma once

namespace System
{
	class Object;
}

namespace CSharp::Native
{
	class GC
	{
		static std::vector<System::Object*> alloc_objs;

		static std::set<System::Object*> ExamineRoot(System::Object* root);

		public:
			static void Register(System::Object* ptr);

			static void UnRegister(System::Object* ptr);

			static void PrintEntries();
			
			static void Collect(System::Array<System::Object*>* roots);
	};
}