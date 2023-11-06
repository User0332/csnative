#include "GarbageCollector.hpp"
#include <iostream>

#pragma once

namespace CSharp::Native
{
	std::map<System::Object*, size_t> GC::obj_map = std::map<System::Object*, size_t>();
	
	void GC::Register(System::Object* ptr)
	{
		if (obj_map.find(ptr) == obj_map.end()) // doesn't exist
		{
			obj_map.emplace(ptr, 0);
			return;
		}

		obj_map[ptr]+=1;
	}

	void GC::UnRegister(System::Object* ptr)
	{
		if (obj_map.find(ptr) == obj_map.end()) return; // doesn't exist

		if (obj_map[ptr] == 0)
		{
			obj_map.erase(ptr);
			std::wcout << "GC DEBUG: Deleting " << ptr << std::endl;

			delete ptr;
		}
		
		obj_map[ptr]-=1;
	}
}