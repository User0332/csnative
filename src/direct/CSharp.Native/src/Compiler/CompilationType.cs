namespace CSharp.Native.Compiler;

public readonly struct CompilationType
{
	public enum Type : byte
	{
		Struct,
		RefStruct,
		Class,
		RecordClass
	}

	public readonly string Name;
	public readonly CPPCodeSegment Code;
	public readonly CompilationUnit ParentUnit;
	public readonly bool IsReadonly;
	public readonly Type TypeOfDatatype;

	public readonly bool IsStruct => TypeOfDatatype == Type.Struct;
	public readonly bool IsClass => TypeOfDatatype == Type.Class;
	public readonly bool IsRefStruct => TypeOfDatatype == Type.RefStruct;
	public readonly bool IsRecord => TypeOfDatatype == Type.RecordClass;
	public readonly bool IsReadonlyStruct => IsStruct && IsReadonly;
	public readonly bool IsReadonlyRefStruct => IsRefStruct && IsReadonly;
	

	public CompilationType(string name, CPPCodeSegment code, bool isReadonly, Type type, CompilationUnit parent)
	{
		Name = name;
		Code = code;
		IsReadonly = isReadonly;
		TypeOfDatatype = type;
		ParentUnit = parent;
	}
}
