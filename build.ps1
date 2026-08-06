# Set all temp directories to D: drive
$env:XMAKE_TMPDIR = "D:\temp"
$env:TMP = "D:\temp"
$env:TEMP = "D:\temp"
$env:TMPDIR = "D:\temp"

# Create temp directory if needed
mkdir D:\temp -ErrorAction SilentlyContinue | Out-Null

# Run xmake
xmake @args
