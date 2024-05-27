@echo off
chcp 65001
echo Building...
echo [%time%]:启动编译流程 > build.log
del ..\build /Q /S
echo [%time%]:删除老文件 >> build.log
xcopy ".\*.*" "..\build" /E /I /Y
echo [%time%]:复制完整代码 >> build.log
echo [%time%]:开始编译 >> build.log
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
	echo [%time%]:运行时错误 >> build.log
    echo input error
	goto run
)