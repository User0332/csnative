$libfiles = [System.Collections.Generic.List[string]]::new()

foreach ($item in Get-ChildItem ../Lib -File -Recurse)
{
	if ($item.FullName.EndsWith(".cpp")) { $libfiles.Add($item.FullName) }
}


g++ -o "$($args[0]).exe" "$($args[0]).cpp" $libfiles # -fpermissive