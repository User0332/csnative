#include "GarbageCollector.hpp"
#include "../System.hpp"
#include "../System/Collections/Generic.hpp"
#include <iostream>
#include <cstdarg>
#include <set>

#pragma once

namespace CSharp::Native
{
	std::vector<System::Object*> GC::alloc_objs = std::vector<System::Object*>();
	
	void GC::Register(System::Object* ptr)
	{
		alloc_objs.emplace_back(ptr);
	}

	void GC::UnRegister(System::Object* ptr)
	{
		// alloc_objs.erase()
	}

	void GC::PrintEntries()
	{

	}

	std::set<System::Object*> GC::ExamineRoot(System::Object* root)
	{

	}

	void GC::Collect(System::Array<System::Object*>* roots)
	{
		System::Collections::Generic::IEnumerator<System::Object*>* enumerator = roots->GetEnumerator();

		std::vector<std::set<System::Object*>> seen_sets;

		try
		{
			while (enumerator->MoveNext())
			{
				seen_sets.emplace_back(ExamineRoot(enumerator->Current()));
			}
		}
		catch(...) {}

		enumerator->Dispose();

		for (auto ptr : alloc_objs)
		{
			bool contains = false;

			for (auto set : seen_sets)
			{
				if (set.count(ptr))
				{
					contains = true;
					break;
				}
			}

			if (!contains) delete ptr; // object is not accessible by the application, delete it
		}
	}
}