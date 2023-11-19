cmake_minimum_required(VERSION 3.16)
project(TF2-ONSTEROIDS)

set(CMAKE_CXX_STANDARD 14)

set(CXX_FLAGS "-Wall -Weffc++ -Wextra -Wconversion -Wsign-conversion -lpthread -m32")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${CXX_FLAGS}")

set(SRC src/main.cpp src/mem/mem.cpp src/features/bhop.cpp)
set(LIBRARY cheat)

add_library(${LIBRARY} SHARED ${SRC})