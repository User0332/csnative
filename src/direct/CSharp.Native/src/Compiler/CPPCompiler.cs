using Microsoft.CodeAnalysis;
using Microsoft.CodeAnalysis.CSharp;

namespace CSharp.Native.Compiler;


class CPPCompiler
{
	public readonly string Source;
	public readonly SyntaxTree SyntaxTree;
	public readonly CompilationUnit CompilationUnit;

	public CPPCompiler(string code, SyntaxTree syntaxTree, string assemblyName)
	{
		Source = code;
		SyntaxTree = syntaxTree;
		CompilationUnit = new(assemblyName);
	}

	public CompilationUnit Compile()
	{
		var root = SyntaxTree.GetCompilationUnitRoot();

		CSNativeSyntaxWalker walker = new();

		walker.Init(CompilationUnit);
		walker.Visit(root);

		return CompilationUnit;
	}
}