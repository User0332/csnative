$libfiles = [System.Collections.Generic.List[string]]::new()

foreach ($item in Get-ChildItem ../Lib -File -Recurse)
{
	$libfiles.Add($item.FullName)
}


g++ -o "$($args[0]).exe" "$($args[0]).cpp" $libfiles -fpermissive