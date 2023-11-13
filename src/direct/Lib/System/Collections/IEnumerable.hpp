#include "IEnumerator.hpp"

namespace System::Collections::Generic
{
	template <class T> class IEnumerable : public Object
	{
		public:
			virtual IEnumerator<T>* GetEnumerator()
			{
				throw /* new NotSupportedException() */;
			}
	};
}