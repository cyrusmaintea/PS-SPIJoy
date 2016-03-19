set PATH=C:\psx\psyq\bin
set PSYQ_PATH=C:\psx\psyq\bin

set prog=main
set bootfn=SPIPad
set DIRS=.\src\
set DIRB=.\bin\

ccpsx -Xo$80010000 -O3 %DIRS%%prog%.c %DIRS%SPI.c %DIRS%SIO.c -o%DIRB%%bootfn%.cpe,%DIRB%%prog%.sym,%DIRB%%prog%.map
cpe2x %DIRB%%bootfn%.cpe
pause