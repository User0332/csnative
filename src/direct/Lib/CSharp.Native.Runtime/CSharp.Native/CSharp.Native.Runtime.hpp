#ifdef _CSNATIVE_IMPORT
#define _CSNATIVE_IMPORT
#endif

namespace CSharp::Native
{
	template <class T, class ...Args> T CreateObject(Args... args)
	{
		return new T(args...);
	}
}