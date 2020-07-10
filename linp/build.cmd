@echo off

REM cd src
REM cria os arquivos objeto
echo Criando os arquivos objeto...
gcc -Dlinp_EXPORTS -std=c17 -Wall -pedantic-errors -c src/*.c
move *.o src
REM cd ..
REM compila a biblioteca
echo Compilando a biblioteca...
gcc -shared -o linp.dll src/*.o -Wl,--out-implib,liblinp.lib
echo Apagando os arquivos objeto...
del /S /Q *.o
REM move os arquivos .dll e .lib para a pasta lib
echo Movendo os arquivos dll e lib...
move linp.dll lib
move liblinp.lib lib