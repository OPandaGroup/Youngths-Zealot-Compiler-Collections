@echo off
chcp 65001
echo Building...
echo [%time%]:start > build.log
del ..\build /Q /S
echo [%time%]:clean >> build.log
xcopy ".\*.*" "..\build" /E /I /Y
echo [%time%]:copy >> build.log
echo [%time%]:build >> build.log
del ..\build\build.log
del ..\build\build.bat
gcc ..\build\code\main.c -o ..\build\bin\mc.exe
rd /s /q ..\build\code
echo [%time%]:end >> build.log
:run
set /p source=run(y/n)?
if %source%==y (
	..\build\bin\mc.exe
) else if %source%==n (
	echo [%time%]:exit >> build.log
) else (
	echo [%time%]:error >> build.log
    echo input error
	goto run
)