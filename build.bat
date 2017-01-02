@echo off
call "C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\vcvarsall.bat" x64     
REM /Od /Zi /EHsc


set file_name=matrix
set compilerflags=/Fo.\bin\ /Od /Zi /EHsc 
set linkerflags=/OUT:bin\%file_name%.exe
cl.exe %compilerflags% source/%file_name%.cpp /link %linkerflags%

REM REM set lib_path2=
REM REM ""
REM set file_name=linar_codes
REM set compilerflags=/Fo.\bin\ /Od /Zi /EHsc 
REM set linkerflags=/OUT:bin\%file_name%.exe
REM REM set Intel_include="C:\Program Files (x86)\Intel\OpenCL SDK\6.3\include"
REM REM set Intel_lib="C:\Program Files (x86)\Intel\OpenCL SDK\6.3\lib\x64"
REM cl.exe %compilerflags% source/%file_name%.cpp source/matrix.cpp /link /LIBPATH: %linkerflags%
