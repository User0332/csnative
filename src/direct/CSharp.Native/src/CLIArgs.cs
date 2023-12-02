using CommandLine;

namespace CSharp.Native;

class CLIArgs
{
	[Value(0, MetaName = "file", HelpText = "The file to compile.", Required = true)]
	public string FileName { get; set; } = "";

	[Option('o', "out", HelpText = "Output filename.", Required = false, Default = null)]
	public string? OutFile { get; set; }

	public static CLIArgs ParseArgs(string[] args)
	{
		CLIArgs parsedArgs = CommandLine.Parser.Default.ParseArguments<CLIArgs>(args).Value;
	
		parsedArgs.OutFile ??= 
			parsedArgs.FileName[..parsedArgs.FileName.LastIndexOf('.')]+".cpp";


		if (!File.Exists(parsedArgs.FileName))
		{
			Console.Error.WriteLine($"CSNative Compiler Error: input file '{parsedArgs.FileName}' does not exist!");
			Environment.Exit(1);
		}

		return parsedArgs;
	}
}