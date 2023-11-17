$corlibfiles = [System.Collections.Generic.List[string]]::new()

foreach ($item in Get-ChildItem ../Lib/CSharp.Native.Runtime -File -Recurse)
{
	if ($item.FullName.EndsWith(".cpp")) { $corlibfiles.Add($item.FullName) }
}

$extlibfiles = [System.Collections.Generic.List[string]]::new()

foreach ($item in Get-ChildItem ../Lib/CSharp.Native.RuntimeExtensions -File -Recurse)
{
	if ($item.FullName.EndsWith(".cpp")) { $extlibfiles.Add($item.FullName) }
}

if ($args[1] -eq "dll")
{
	g++ $corlibfiles -c # -fpermissive

	g++ -o CSharp.Native.Runtime.dll *.o -shared

	Remove-Item *.o

	g++ $extlibfiles -c # -fpermissive

	g++ -o CSharp.Native.RuntimeExtensions.dll *.o CSharp.Native.Runtime.dll -shared

	Remove-Item *.o

	g++ "$($args[0]).cpp" -c # -fpermissive

	g++ -o "$($args[0]).dll" "$($args[0]).o" CSharp.Native.Runtime.dll CSharp.Native.RuntimeExtensions.dll -shared # -fpermissive

	g++ -o "$($args[0]).exe" "$($args[0]).Exe.cpp" "$($args[0]).dll" CSharp.Native.Runtime.dll

	Remove-Item *.o
}
else
{
	g++ -o "standalone/$($args[0]).exe" "$($args[0]).cpp" $libfiles # -fpermissive
}
