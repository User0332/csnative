#include "../../System.hpp"
#include "IEnumerable.hpp"
#include <vector>

namespace System::Collections::Generic
{
	template <class T, class ...Args> T CreateObject(Args... args)
	{
		return new T(args...);
	}

	template <class T> class List : virtual public IEnumerable<T>
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
			Int32 get_Capacity() // getter
			{
				return Int32(inner.capacity());
			}

			void set_Capacity(Int32 value) // setter
			{
				inner.capacity(value.ToNative());
			}

			Int32 get_Count()
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
	class DLLATTR Array
	{
		private:
			template <class T> class ArrayEnumerator : public System::Collections::Generic::IEnumerator<T>
			{
				Array<T>* items;
				Int32 idx = Int32(0);

				public:
					ArrayEnumerator(Array::Intrinsic<T>* items)
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
						delete this;
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
			
		public:
			template <class T> class DLLATTR Intrinsic: virtual public System::Collections::Generic::IEnumerable<T>
			{
				T* inner;
				int length;

				public:

					Intrinsic() : Intrinsic(new T[0], 0)
					{
					
					}

					Intrinsic(T elems[], size_t size)
					{
						inner = elems;
						length = size;
					}

					T& operator[](Int32 index)
					{
						return inner[index.ToNative()];
					}

					System::Collections::Generic::IEnumerator<T>* GetEnumerator()
					{
						return new ArrayEnumerator(this);
					}

					int get_Length()
					{
						return length;
					}

					~Intrinsic()
					{
						delete[] inner;
					}
			};

		};

	template class Array::Intrinsic<Object*>; // later have the csnative compiler add decls like this to gen all required generics
}