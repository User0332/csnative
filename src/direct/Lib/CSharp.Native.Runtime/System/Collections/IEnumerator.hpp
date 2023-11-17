#include "../../System.hpp"

namespace System::Collections::Generic
{
	template <class T> class IEnumerator : public Object
	{
		public:
			// current is a prop
			virtual T Current()
			{
				throw /* new NotSupportedException() */;
			}

			virtual void Dispose()
			{
				throw /* new NotSupportedException() */;
			}

			virtual Boolean MoveNext()
			{
				throw /* new NotSupportedException() */;
			}

			virtual void Reset()
			{
				throw /* new NotSupportedException() */;
			}
	};
}