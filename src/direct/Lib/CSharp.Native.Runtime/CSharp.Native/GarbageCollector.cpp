#include "GarbageCollector.hpp"
#include "../System.hpp"
#include "../System/Collections/Generic.hpp"
#include <iostream>

#pragma once

namespace CSharp::Native
{
	std::set<System::Object*> GC::alloc_objs = std::set<System::Object*>();
	
	void GC::Register(System::Object* ptr)
	{
		alloc_objs.emplace(ptr);
	}

	void GC::UnRegister(System::Object* ptr)
	{
		alloc_objs.erase(ptr);
	}

	void GC::PrintEntries()
	{

	}

	std::set<System::Object*> GC::ExamineRoot(System::Object* root)
	{
		std::set<System::Object*> seen;
		seen.emplace(root);

		auto enumerator = root->GetType()->GetFields()->GetEnumerator();

		try
		{
			while (enumerator->MoveNext())
			{
				System::Object* val = enumerator->Current()->GetValue(root);

				auto accessible = ExamineRoot(val);
				seen.insert(accessible.begin(), accessible.end());
			}
		}
		catch(...) {}

		enumerator->Dispose();

		return seen;
	}

	void GC::Collect(System::Array<System::Object*>* roots)
	{
		auto enumerator = roots->GetEnumerator();

		std::set<System::Object*> seen;

		try
		{
			while (enumerator->MoveNext())
			{
				auto accessible = ExamineRoot(enumerator->Current());
				seen.insert(accessible.begin(), accessible.end());
			}
		}
		catch(...) {}

		enumerator->Dispose();

		for (auto ptr : alloc_objs)
		{
			if (seen.count(ptr)) continue;

			std::wcout << "Deleting " << ptr << std::endl;

			alloc_objs.erase(ptr);
			delete ptr; // object is not accessible by the application, delete it
		}
	}

	void GC::UNSAFE_CollectAll()
	{
		for (auto ptr : alloc_objs)
		{
			delete ptr;
		}

		alloc_objs.clear();
	}
}