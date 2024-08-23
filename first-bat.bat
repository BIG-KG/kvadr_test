cd C:\Users\bekge\OneDrive\Документы\GitHub\kvadr_test

set /p run.main=enter "1" if you want compile main.c 
if "%run.main%" == "1" (g++ main.c -c)
cls

set /p run.equ_new=enter "1" if you want compile equ_new.c 
if "%run.equ_new%" == "1" (g++ equ_new.c -c)
cls

set /p run.entering=enter "1" if you want compile entering.c 
if "%run.entering%" == "1" (g++ entering.c -c)
cls

g++ main.o equ_new.o entering.o -o qwer1.exe
cls

qwer1


pause