:: 脚本文件：build.bat
:: Debug 模式说明，如果要开启Debug模式，请把Debug模式设置为1
@echo off
set Debug=1
chcp 65001
echo Building...(X64)
echo 准备编译...(X64)
timeout /t 10
echo [%time%]:启动编译流程 > build.log
del ..\build /Q /S
echo [%time%]:删除老文件 >> build.log
xcopy ".\*.*" "..\build" /E /I /Y
echo [%time%]:复制完整代码 >> build.log
echo [%time%]:开始编译 >> build.log
del ..\build\build.log
del ..\build\build.bat 
del /q ..\build\lib
del /q ..\build\bin
echo 删除编译日志
gcc -shared -fpic ..\build\src\lib\Pprint.c -o ..\build\lib\Pprint.so
echo [%time%]:编译Pprint完成 >> build.log
gcc -shared -fpic ..\build\src\lib\PString.c -o ..\build\lib\PString.so
echo [%time%]:编译PString完成 >> build.log
gcc -shared -fpic ..\build\src\lib\PFile.c -o ..\build\lib\PFile.so
echo [%time%]:编译PFile完成 >> build.log
gcc -shared -fpic ..\build\src\lib\PDataTypeConversion.c ..\build\lib\PString.so -o ..\build\lib\PDataTypeConversion.so
echo [%time%]:编译PDataTypeConversion完成 >> build.log
if %Debug% == 1 (gcc -shared -fpic ..\build\src\lib\PDebug.c ..\build\lib\PString.so ..\build\lib\PFile.so -D__Panda_Debug__ -o ..\build\lib\PDebug.so) else (gcc -shared -fpic ..\build\src\lib\PDebug.c ..\build\lib\PString.so ..\build\lib\PFile.so -o ..\build\lib\PDebug.so)
echo [%time%]:编译PDebug完成 >> build.log
:: Windows
gcc -shared -fpic ..\build\src\lib\PWindows.c ..\build\lib\PString.so -o ..\build\lib\PWindows.so
echo [%time%]:编译PWindows完成 >> build.log
:: Linux
:: 由于这个bat文件是针对Windows的,所以不用编译Linux的so库
gcc -shared -fpic ..\build\src\lib\PSystem.c -DWin_NT ..\build\lib\PWindows.so -o ..\build\lib\PSystem.so
gcc -shared -fpic ..\build\src\lib\PDataStructure.c ..\build\lib\PDataTypeConversion.so ..\build\lib\PFile.so ..\build\lib\PDebug.so ..\build\lib\PString.so ..\build\lib\Pprint.so ..\build\lib\PSystem.so -o ..\build\lib\PDataStructure.so
echo [%time%]:编译PDataStructure完成 >> build.log
echo [%time%]:编译PSystem完成 >> build.log
echo [%time%]:so库编译完成 >> build.log
gcc -o ..\build\bin\yzcc.exe ..\build\src\main.c ..\build\lib\Pprint.so ..\build\lib\PString.so ..\build\lib\PFile.so ..\build\lib\PDataStructure.so ..\build\lib\PSystem.so ..\build\lib\PDebug.so
rd /s /q ..\build\src
xcopy "..\build\bin" ".\bin" /E /I /Y
xcopy "..\build\lib" ".\lib" /E /I /Y
echo [%time%]:完成编译 >> build.log
echo [%time%]:完成编译,loading...
echo [%time%]:Running >> build.log        
..\build\bin\yzcc.exe               
pause