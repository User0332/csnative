#include "../../System.hpp"
#include <vector>

namespace System::Collections::Generic
{
	template <class T> class List
	{
		std::vector<T> inner;

		public:
			List()
			{
				inner = std::vector<T>();
			}

			List(Int32 capacity)
			{
				inner = std::vector<T>(capacity.ToNative());
			}

			Add(T elem)
			{
				inner.emplace_back(elem);
			}

			// List.Capacity is actually a prop
			Int32 Capacity() // getter
			{
				return Int32(inner.capacity());
			}

			void Capacity(Int32 value) // setter
			{
				inner.capacity(value.ToNative());
			}

			T& operator[](Int32 idx) // may need proxy to try index properly
			{
				return inner[idx.ToNative()];
			}

	};
}