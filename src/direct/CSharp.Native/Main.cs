namespace CSharp.Native;

public class Test
{
}

public class Program
{
	static int Main()
	{

		Console.WriteLine(typeof(string).GetProperty("Length").GetType());
		Console.WriteLine("Te\0st!");
		
		return 0;
	}
}
