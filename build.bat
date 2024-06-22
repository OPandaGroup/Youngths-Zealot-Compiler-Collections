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
echo 删除编译日志
gcc -shared -fpic ../build/code/lib/function.c -o ../build/lib/function.dll
echo [%time%]:function.c >> build.log
gcc -shared -fpic ../build/code/lib/structure.c ../build/lib/function.dll -o ../build/lib/structure.dll
echo [%time%]:structure.h.c >> build.log
gcc -shared -fpic ../build/code/lib/print.c -o ../build/lib/print.dll
echo [%time%]:print.c >> build.log
gcc -shared -fpic ../build/code/lib/mc_lib64.c ../build/code/lib/structure.c ../build/code/lib/function.c ../build/code/lib/print.c -o ../build/lib/mc_lib64.dll
echo [%time%]:mc_lib64.c >> build.log
gcc ..\build\code\main.c ../build/lib/mc_lib64.dll -o ..\build\bin\mc.exe
echo [%time%]:main.c >> build.log
gcc ..\build\code\pretreatment.c ../build/lib/structure.dll ../build/lib/function.dll ../build/lib/print.dll -o ..\build\bin\pretreatment.exe
echo [%time%]:pretreatment.c >> build.log
gcc ..\build\code\macro.c ../build/lib/function.dll ../build/lib/print.dll -o ..\build\bin\macro.exe
echo [%time%]:macro.c >> build.log
gcc ..\build\code\versions.c -o ..\build\bin\version.exe
echo [%time%]:versions.c >> build.log
gcc ..\build\code\help.c -o ..\build\bin\help.exe
echo [%time%]:help.c >> build.log
rd /s /q ..\build\code
xcopy "..\build\bin" ".\bin" /E /I /Y
xcopy "..\build\lib" ".\lib" /E /I /Y
echo [%time%]:完成编译 >> build.log
echo [%time%]:完成编译                       
