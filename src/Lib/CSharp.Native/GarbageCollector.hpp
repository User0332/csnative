#include <map>

#pragma once

namespace System
{
	class Object;
}

namespace CSharp::Native
{
	class GC
	{
		static std::map<System::Object*, size_t> obj_map;

		public:
			static void Register(System::Object* ptr);

			static void UnRegister(System::Object* ptr);

			static void PrintEntries();
	};
}