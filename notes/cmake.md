cmake_minimun_required(VERSION 3.14)
cmake 第一行用永远是这个


现在想一个问题：CMake 管理一个项目，它至少得知道这个项目叫什么名字和用什么语言，对吧？
答案：
project(snake LANGUAGES CXX)
拆开：
- project(...) — 声明项目信息
- 第一个参数 snake — 项目名，随便取
- LANGUAGES CXX — 告诉 CMake 这是 C++ 项目（CXX = C++，C = C 语言）

第三行
现在你要告诉 CMake：用哪些 .cpp 文件，生成一个叫 snake 的 .exe。
命令是：
add_executable(snake main.cpp)
拆开：
- add_executable — 我要生成一个可执行文件（.exe）
- 第一个参数 snake — .exe 文件名叫 snake.exe
- main.cpp — 参与编译的第一个源文件

file(GLOB SRC_FILES src/*.cpp)

包含头文件的时候只要写 include 文件夹就可以了, 万一有两个相同名字的 .h 文件但是在include 文件夹内部不同的子文件夹里面就不合适了

选项	意思
PRIVATE	这个 include 路径只给我自己编译用，依赖我的目标不需要
PUBLIC	我自己编译要用，依赖我的人也要用
INTERFACE	我自己不需要，但依赖我的人需要

cmake -B build -S . 拆开：
参数	含义
-S .	源码在哪（Source）— 当前目录，里面有 CMakeLists.txt
-B build	产物放哪（Build）— 放到 build 子目录，不污染源码


cmake --build build 这个是 cmake 的编译指令

编译完产生的 文件在 .build 里面的 projectname.exe

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}")
这个指令可以指定 输出 .exe 文件地址
