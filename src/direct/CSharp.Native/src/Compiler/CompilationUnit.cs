using System.Text;

namespace CSharp.Native.Compiler;


public readonly struct CompilationUnit
{
	public readonly List<CompilationType> Types = new();
	public readonly string AssemblyName;
	public readonly List<string> Namespaces = new();

	public readonly string MetadataInitializerFuncName {
		get {
			string[] split = AssemblyName.Split('.');
			
			return $"InitializeMetadata_ns{split.Length}_{string.Join('_', split)}";
		}
	} 
	
	public CompilationUnit(string assemblyName)
	{
		AssemblyName = assemblyName;
	}

	public readonly CPPCodeSegment Build()
	{
		StringBuilder decl = new();
		StringBuilder def = new();


		foreach (CompilationType type in Types)
		{
			decl.AppendLine(type.Code.Declaration);
			def.AppendLine(type.Code.Definition);
		}

		return new CPPCodeSegment(decl.ToString(), def.ToString());
	}
}