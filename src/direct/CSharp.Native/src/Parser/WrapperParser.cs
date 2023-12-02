using Microsoft.CodeAnalysis;
using Microsoft.CodeAnalysis.CSharp;
using Microsoft.CodeAnalysis.Text;

namespace CSharp.Native.Parser;

static class WrappedParser
{
	public static
	(SyntaxTree tree, List<string> info, 
	List<string> warnings, List<string> errors)
	ParseCode(string code)
	{
		SyntaxTree res = CSharpSyntaxTree.ParseText(code);

		var diagnostics = res.GetDiagnostics();

		List<string> infos = new();
		List<string> warnings = new();
		List<string> errors = new();

		foreach (var diagnostic in diagnostics)
		{
			FileLinePositionSpan lineSpan;
			TextSpan sourceSpan;
			int start, end;

			switch (diagnostic.Severity)
			{
				case DiagnosticSeverity.Info:
					lineSpan = diagnostic.Location.GetLineSpan();
					sourceSpan = diagnostic.Location.SourceSpan;

					(start, end) = (sourceSpan.Start, sourceSpan.End);

					infos.Add($"{diagnostic.GetMessage()} (line {lineSpan.StartLinePosition.Line})\n\t{code[start..end]}");
					break;
				case DiagnosticSeverity.Warning:
					lineSpan = diagnostic.Location.GetLineSpan();
					sourceSpan = diagnostic.Location.SourceSpan;

					(start, end) = (sourceSpan.Start, sourceSpan.End);

					warnings.Add($"{diagnostic.GetMessage()} (line {lineSpan.StartLinePosition.Line})\n\t{code[start..end]}");
					break;
				case DiagnosticSeverity.Error:
					lineSpan = diagnostic.Location.GetLineSpan();
					sourceSpan = diagnostic.Location.SourceSpan;

					(start, end) = (sourceSpan.Start, sourceSpan.End);

					errors.Add($"{diagnostic.GetMessage()} (line {lineSpan.StartLinePosition.Line})\n\t{code[start..end]}");
					break;
			}
		}

		return (res, infos, warnings, errors);
	}
}