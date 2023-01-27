cmake_minimum_required(VERSION 3.25.1)

project(proxy)

set(CMAKE_CXX_STANDARD 23)
# 添加预定义宏
add_definitions(-DUNICODE -D_UNICODE)

# 设置默认编译类型
set(CMAKE_CONFIGURATION_TYPES "Debug;Release;" CACHE STRING "info" FORCE)

set(SOLUTION_ROOT_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../../)

set(CURRENT_SOLUTION_ROOT_DIR ${CMAKE_CURRENT_SOURCE_DIR})
#cmake modules path
set(LOCAL_CMAKE_MODULES_PATH ${SOLUTION_ROOT_DIR}/cmake/modules/)

LIST(APPEND CMAKE_MODULE_PATH ${LOCAL_CMAKE_MODULES_PATH})
include(msvc_methods)
include(global_methods)
include(OutputPathConfig)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set_property(GLOBAL PROPERTY PREDEFINED_TARGETS_FOLDER "CMakeTargets")

#message(STATUS ${LOCAL_CMAKE_MODULES_PATH})

OutputPathConfig("bin" "bin" "lib")
add_subdirectory(${CURRENT_SOLUTION_ROOT_DIR}/cmake/core)
#set_target_properties(bridge PROPERTIES FOLDER "shared")
OutputPathConfig("")
