#include "../../System.hpp"
#include "IEnumerable.hpp"
#include <vector>

namespace System::Collections::Generic
{
	template <class T> class List : public IEnumerable<T>
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

			void Add(T elem)
			{
				inner.emplace_back(elem);
			}
			
			// List.Capacity is actually a prop (same for Count)
			Int32 Capacity() // getter
			{
				return Int32(inner.capacity());
			}

			void Capacity(Int32 value) // setter
			{
				inner.capacity(value.ToNative());
			}

			Int32 Count()
			{
				return Int32(inner.size());
			}

			T& operator[](Int32 idx) // may need proxy to try index properly
			{
				return inner[idx.ToNative()];
			}

	};
}

namespace System
{
	template <class T> class ArrayEnumerator
	{

	};

	template <class T> class Array : public Object, public System::Collections::Generic::IEnumerable<T>
	{
		T* inner;

		public:
			int Length; /* get; */

			Array() : Array(new T[0], 0)
			{

			}

			Array(T elems[], size_t size)
			{
				inner = elems;
				Length = size;
			}

			T& operator[](Int32 index)
			{
				return inner[index.ToNative()];
			}

			System::Collections::Generic::IEnumerator<T>* GetEnumerator()
			{
				class ArrayEnumerator : public System::Collections::Generic::IEnumerator<T>
				{
					Array<T>* items;
					Int32 idx = Int32(0);

					public:
						ArrayEnumerator(Array<T>* items)
						{
							this->items = items;
						}

						// current is a prop
						T Current()
						{
							return items->operator[](idx);
						}

						void Dispose()
						{
							return;
						}

						Boolean MoveNext()
						{
							idx+=Int32(1);

							if (idx < items->Length) return Boolean(true);
							
							idx-=Int32(1);

							return Boolean(false);
						}

						void Reset()
						{
							idx = Int32(-1);
						}
				};

				return new ArrayEnumerator(this);
			}
	};
}

