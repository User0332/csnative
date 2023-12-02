using Microsoft.CodeAnalysis;
using Microsoft.CodeAnalysis.CSharp;
using Microsoft.CodeAnalysis.CSharp.Syntax;

namespace CSharp.Native.Compiler;

class CSNativeSyntaxWalker : CSharpSyntaxWalker
{
	CompilationUnit unit;

	public void Init(CompilationUnit compilationUnit)
	{
		unit = compilationUnit;
	}

	public override void VisitClassDeclaration(ClassDeclarationSyntax node)
	{
		string name = node.Identifier.ValueText;
		string[] bases = new string[] { "Object" };
		
		base.VisitClassDeclaration(node);
	}
}