#define _CSNATIVE_IMPORT
#include "../Lib/CSharp.Native.Runtime/NativeLikeTypes/NumTypes.hpp"

class __declspec(dllimport) Program
{
	public:
		static System::Int32 Main();
};

int main()
{
	return Program::Main().ToNative();
}