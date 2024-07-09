@echo off
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
gcc -shared -fpic ..\build\src\lib\PDataStructure.c ..\build\lib\PDataTypeConversion.so ..\build\lib\PString.so -o ..\build\lib\PDataStructure.so
echo [%time%]:编译PDataStructure完成 >> build.log
gcc -shared -fpic ..\build\src\lib\PWindows.c ..\build\lib\PString.so -o ..\build\lib\PWindows.so
echo [%time%]:编译PWindows完成 >> build.log
echo [%time%]:so库编译完成 >> build.log
rd /s /q ..\build\src
xcopy "..\build\bin" ".\bin" /E /I /Y
xcopy "..\build\lib" ".\lib" /E /I /Y
echo [%time%]:完成编译 >> build.log
echo [%time%]:完成编译,loading...
echo [%time%]:Running >> build.log        
..\build\bin\mc.exe               
pause