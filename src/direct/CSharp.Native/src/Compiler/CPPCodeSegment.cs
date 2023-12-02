namespace CSharp.Native.Compiler;

public readonly struct CPPCodeSegment
{
	public readonly string Declaration;
	public readonly string Definition;

	public CPPCodeSegment(string decl, string def)
	{
		Declaration = decl;
		Definition = def;
	}
}