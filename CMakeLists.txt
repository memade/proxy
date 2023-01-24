cmake_minimum_required(VERSION 3.25.1)

project (proxy)

set(CMAKE_CXX_STANDARD 23)
# 添加预定义宏
add_definitions(-DUNICODE -D_UNICODE)

# 设置默认编译类型
set(CMAKE_CONFIGURATION_TYPES "Debug;Release;" CACHE STRING "info" FORCE)

set(SOLUTION_ROOT_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../../)

set(CURRENT_SOLUTION_ROOT_DIR ${CMAKE_CURRENT_SOURCE_DIR})
#cmake modules path
set(LOCAL_CMAKE_MODULES_PATH ${SOLUTION_ROOT_DIR}/cmake/modules/)

set(LOCAL_LIBRARYS_SHARED_PATH ${SOLUTION_ROOT_DIR}/librarys/shared/)
set(LOCAL_LIBRARYS_3RDPARTY_PATH ${SOLUTION_ROOT_DIR}/librarys/3rdparty/)
set(SPDLOG_INCLUDE_DIR ${SOLUTION_ROOT_DIR}/3rdparty/spdlog/include/)
message(STATUS ${SPDLOG_INCLUDE_DIR})
#Project generic header definition
include_directories(${SOLUTION_ROOT_DIR}/include)
include_directories(${SOLUTION_ROOT_DIR}/3rdparty)
include_directories(${CURRENT_SOLUTION_ROOT_DIR}/include)

if(MSVC)
option(ENABLE_MSVC_CRT_MT "Enable msvc crt /MT /MTd compile." ON)
if(ENABLE_MSVC_CRT_MT)
add_compile_options("$<$<CONFIG:Release>:/GL>")
add_link_options("$<$<CONFIG:Release>:/LTCG>")
endif(ENABLE_MSVC_CRT_MT)
endif(MSVC)

LIST(APPEND CMAKE_MODULE_PATH ${LOCAL_CMAKE_MODULES_PATH})
include(msvcpch)
include(OutputPathConfig)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set_property(GLOBAL PROPERTY PREDEFINED_TARGETS_FOLDER "CMakeTargets")

#message(STATUS ${LOCAL_CMAKE_MODULES_PATH})


OutputPathConfig("bin" "bin" "lib")
add_subdirectory(${CURRENT_SOLUTION_ROOT_DIR}/cmakes/bridge)
#set_target_properties(bridge PROPERTIES FOLDER "shared")
OutputPathConfig("")


#[[
OutputPathConfig("tools/bin" "tools/bin" "librarys" ON)
add_subdirectory(${SOLUTION_ROOT_DIR}/compile/cmakes/tools/compress)
set_target_properties(compress PROPERTIES FOLDER "tools")
add_subdirectory(${SOLUTION_ROOT_DIR}/compile/cmakes/tools/cryption)
set_target_properties(cryption PROPERTIES FOLDER "tools")
add_subdirectory(${SOLUTION_ROOT_DIR}/compile/cmakes/tools/encode)
set_target_properties(encode PROPERTIES FOLDER "tools")
add_subdirectory(${SOLUTION_ROOT_DIR}/compile/cmakes/tools/packet)
set_target_properties(packet PROPERTIES FOLDER "tools")
add_subdirectory(${SOLUTION_ROOT_DIR}/compile/cmakes/tools/respak)
set_target_properties(respak PROPERTIES FOLDER "tools")
add_subdirectory(${SOLUTION_ROOT_DIR}/compile/cmakes/tools/update)
set_target_properties(update PROPERTIES FOLDER "tools")
add_subdirectory(${SOLUTION_ROOT_DIR}/compile/cmakes/tools/fileedit)
set_target_properties(fileedit PROPERTIES FOLDER "tools")
add_subdirectory(${SOLUTION_ROOT_DIR}/compile/cmakes/tools/cppshellcode)
set_target_properties(cppshellcode PROPERTIES FOLDER "tools")
OutputPathConfig("")
]]