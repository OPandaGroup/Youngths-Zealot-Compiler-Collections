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
gcc -shared -fpic ../build/src/lib/function.c -o ../build/lib/function.dll
echo [%time%]:function.c >> build.log
gcc -shared -fpic ../build/src/lib/structure.c ../build/lib/function.dll -o ../build/lib/structure.dll
echo [%time%]:structure.h.c >> build.log
gcc -shared -fpic ../build/src/lib/print.c -o ../build/lib/print.dll
echo [%time%]:print.c >> build.log
gcc -shared -fpic ../build/src/lib/mc_lib64.c ../build/src/lib/structure.c ../build/src/lib/function.c ../build/src/lib/print.c -o ../build/lib/mc_lib64.dll
echo [%time%]:mc_lib64.c >> build.log
gcc ..\build\src\main.c ../build/lib/mc_lib64.dll -o ..\build\bin\mc.exe -lpthread
echo [%time%]:main.c >> build.log
gcc ..\build\src\pretreatment.c ../build/lib/structure.dll ../build/lib/function.dll ../build/lib/print.dll -o ..\build\bin\pretreatment.exe
echo [%time%]:pretreatment.c >> build.log
gcc ..\build\src\versions.c -o ..\build\bin\version.exe
echo [%time%]:versions.c >> build.log
gcc ..\build\src\help.c -o ..\build\bin\help.exe
echo [%time%]:help.c >> build.log
rd /s /q ..\build\src
xcopy "..\build\bin" ".\bin" /E /I /Y
xcopy "..\build\lib" ".\lib" /E /I /Y
echo [%time%]:完成编译 >> build.log
echo [%time%]:完成编译,loading...
echo [%time%]:Running >> build.log        
..\build\bin\mc.exe               
pause