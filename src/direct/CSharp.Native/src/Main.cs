using System.Collections;
using CSharp.Native.Compiler;
using CSharp.Native.Parser;
using Microsoft.CodeAnalysis;

namespace CSharp.Native;

public class Program
{
	static int Main(string[] args)
	{
		CLIArgs parsedArgs = CLIArgs.ParseArgs(args);

		string code;

		try { code = File.ReadAllText(parsedArgs.FileName); }
		catch (Exception e)
		{
			Console.Error.WriteLine($"CSNative Compiler Error: could not read input file '{parsedArgs.FileName}' -- ${e.Message}");
			return 1;
		}

		SyntaxTree syntaxTree;
		List<string> infos;
		List<string> warnings;
		List<string> errors;

		(syntaxTree, infos, warnings, errors) = WrappedParser.ParseCode(code);
		
		foreach (var msg in infos)
		{
			Console.WriteLine($"INFO: {msg}");
		}

		foreach (var msg in warnings)
		{
			Console.WriteLine($"WARNING: {msg}");
		}

		foreach (var msg in errors)
		{
			Console.WriteLine($"ERROR: {msg}");
		}


		if (errors.Any()) return 1;

		var compiler = new CPPCompiler(code, syntaxTree, "MyTestAssembly");

		CompilationUnit result = compiler.Compile();
		
		CPPCodeSegment generatedCode = result.Build();

		return 0;
	}
}
