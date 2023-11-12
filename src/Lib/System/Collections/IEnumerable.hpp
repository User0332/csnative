#include "IEnumerator.hpp"

namespace System::Collections::Generic
{
	template <class T> class IEnumerable
	{
		public:
			IEnumerator<T>* GetEnumerator()
			{
				throw /* new NotSupportedException() */;
			}
	};
}