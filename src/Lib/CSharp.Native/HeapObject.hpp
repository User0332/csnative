#include <iostream>

namespace CSharp::Native
{
	template <typename TObject> class HeapManagedObject
	{
		public:
			TObject* obj;
			
			// template defs must be added directly in the header
			HeapManagedObject(TObject* obj)
			{
				this->obj = obj;
			}

			~HeapManagedObject()
			{
				// std::cout << "Deleting " << obj << '(' << ')' << std::endl;
				delete obj;
			}
	};
}