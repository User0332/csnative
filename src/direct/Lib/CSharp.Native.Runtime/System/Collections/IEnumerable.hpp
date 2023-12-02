#include "IEnumerator.hpp"

namespace System::Collections::Generic
{
	template <class T> class DLLATTR IEnumerable : public Object
	{
		public:
			virtual IEnumerator<T>* GetEnumerator()
			{
				throw /* new NotSupportedException() */;
			}
	};
}