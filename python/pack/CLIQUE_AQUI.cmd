@echo off

for /f "tokens=2 delims=:." %%x in ('chcp') do set cp=%%x
chcp 1252>nul

rem set build_dir=%CD%

rem finding python
for /f "tokens=*" %%a in ('python -c "import sys, os; print(os.path.dirname(sys.executable))"') do (
	set python_path="%%a\Lib\site-packages"
)

echo ---------------------------------------------------------------------
echo Movendo os arquivos
echo ---------------------------------------------------------------------
echo.

echo d | xcopy "pylinp" "%python_path%\pylinp" /Y

pause