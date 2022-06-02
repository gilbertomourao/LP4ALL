@echo off

for /f "tokens=2 delims=:." %%x in ('chcp') do set cp=%%x
chcp 1252>nul

rem set build_dir=%CD%

rem finding python
for /f "tokens=*" %%a in ('python -c "import sys, os; print(os.path.dirname(sys.executable))"') do (
	set python_path="%%a\Lib\site-packages"
)

rem running build

echo.

echo ---------------------------------------------------------------------
echo Compiling the source
echo ---------------------------------------------------------------------
echo.

if exist build (
	echo Removing old build...
	rmdir /q /s build
)
python setup.py build --compiler=mingw32

echo.
echo ---------------------------------------------------------------------
echo Creating PYLINP
echo ---------------------------------------------------------------------
echo.

rem creating the folder pylinp
echo Checking if pylinp already exists...
rem cd %python_path%
if exist "%python_path%\pylinp" (
	echo Deleting the file...
	rmdir /q /s "%python_path%\pylinp"
)
echo Creating pylinp...
mkdir "%python_path%\pylinp"

echo.
echo ---------------------------------------------------------------------
echo Moving files
echo ---------------------------------------------------------------------
echo.

rem copying data
echo Moving files to the Python directory...
rem cd %build_dir%\build\lib.win32-3.8
echo Moving the compiled module...
copy build\lib.win-amd64-3.8\pylinp* "%python_path%\pylinp"
rem cd ../..
echo Moving __init__.py...
copy __init__.py "%python_path%\pylinp"

rem copying the resulting folder to pack
xcopy "%python_path%\pylinp" "pack\pylinp" /Y

echo.
echo ---------------------------------------------------------------------
echo Done.

chcp %cp%>nul

pause