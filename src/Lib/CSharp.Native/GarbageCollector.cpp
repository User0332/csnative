#include "GarbageCollector.hpp"
#include "../System.hpp"
#include <iostream>

#pragma once

namespace CSharp::Native
{
	std::map<System::Object*, size_t> GC::obj_map = std::map<System::Object*, size_t>();
	
	void GC::Register(System::Object* ptr)
	{
		if (obj_map.count(ptr) == 0) // doesn't exist
		{
			obj_map[ptr] = 0;

			// std::wcout << "GC DEBUG: Registering " << ptr << std::endl;

			return;
		}

		// std::wcout << "GC DEBUG: Re-Registering " << ptr << std::endl;

		obj_map[ptr]+=1;
	}

	void GC::UnRegister(System::Object* ptr)
	{
		if (obj_map.count(ptr) == 0) return; // doesn't exist

		if (obj_map[ptr] == 0)
		{
			obj_map.erase(ptr);
			// std::wcout << "GC DEBUG: Deleting " << ptr  << std::endl;

			delete ptr;

			return;
		}

		// std::wcout << "GC DEBUG: De-Registering " << ptr  << std::endl;
		
		obj_map[ptr]-=1;
	}

	void GC::PrintEntries()
	{
		for (auto& entry : obj_map)
		{
			std::wcout << entry.first << '(' << entry.first->ToString()->ToCpp() << ')' << ": " << entry.second << std::endl;
		}
	}
}