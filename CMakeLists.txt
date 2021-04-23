cmake_minimum_required(VERSION 3.19)
project(s21_pa04_mikecuzzo_grantayers)

set(CMAKE_CXX_STANDARD 17)

set(Sources src/main.cpp src/Prims.cpp src/Prims.h src/Kruskals.cpp src/Kruskals.h src/GraphEngine.cpp src/GraphEngine.h src/UnionFind.cpp src/UnionFind.h)

add_executable(${PROJECT_NAME} ${Sources})

FIND_PACKAGE(Boost)

IF (Boost_FOUND)
    message("FOUND")
endif()

if(NOT Boost_FOUND)
    message(FATAL_ERROR "Boost Not found")
endif()

INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIR})

find_package(PythonLibs REQUIRED)
include_directories(${PYTHON_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME}  ${PYTHON_LIBRARIES})