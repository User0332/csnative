#include "GarbageCollector.hpp"
#include <iostream>

namespace CSharp::Native
{
	template <typename TObject> ManagedObject<TObject>::ManagedObject(TObject* obj)
	{
		this->obj = obj;
	}

	template <typename TObject> ManagedObject<TObject>::~ManagedObject()
	{
		std::cout << "Deleting " << obj << '(' << ')' << std::endl;
		delete obj;
	}
}