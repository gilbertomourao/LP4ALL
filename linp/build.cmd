@echo off

rem -----------------------------------------------------------------------------------

rem verificando se o gcc esta instalado

set mingw_path=NotHere

for /f "tokens=*" %%a in ('where gcc') do (
	set mingw_path=%%a\..\..
)

if not exist %mingw_path% (
	echo "Instale o gcc no seu computador antes de continuar."
	goto:eof
) 

rem -----------------------------------------------------------------------------------

set include_path=%mingw_path%\x86_64-w64-mingw32\include\linp\
set lib_path=%mingw_path%\lib
set dll_path=%mingw_path%\bin

rem -----------------------------------------------------------------------------------

REM cd src
REM cria os arquivos objeto
echo Criando os arquivos objeto...
gcc -Dlinp_EXPORTS -std=c17 -Wall -pedantic-errors -c src/*.c
move *.o src

rem -----------------------------------------------------------------------------------

REM cd ..
REM compila a biblioteca
echo Compilando a biblioteca...
gcc -shared -o linp.dll src/*.o -Wl,--out-implib,liblinp.lib
echo Apagando os arquivos objeto...
del /S /Q *.o

rem -----------------------------------------------------------------------------------

REM move os arquivos .dll e .lib para a pasta lib
echo Movendo os arquivos dll e lib...
mkdir lib
move linp.dll lib
move liblinp.lib lib
copy lib\linp.dll %dll_path%
copy lib\liblinp.lib %lib_path%
xcopy include %include_path% /Y

rem -----------------------------------------------------------------------------------

rem end