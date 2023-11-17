namespace System::Collections
{
	template <class T, class ...Args> T CreateObject(Args... args)
	{
		return new T(args...);
	}
}