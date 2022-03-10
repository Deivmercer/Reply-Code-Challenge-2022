Get-ChildItem -Path input_files -Filter *.txt | ForEach-Object {
    Write-Output "Running on $_"
    & ".\x64\Debug\Reply Code Challenge 2022.exe" $_.FullName
}