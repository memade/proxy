cmake_minimum_required(VERSION 3.25.1)
project (proxy)
set(CMAKE_CXX_STANDARD 23)
# 添加预定义宏
add_definitions(-DUNICODE -D_UNICODE)

#[[
# MSVC 设置运行时库
if (MSVC)
add_compile_options("$<$<CONFIG:Release>:/GL>")
add_link_options("$<$<CONFIG:Release>:/LTCG>")
 set(CompilerFlags
     CMAKE_CXX_FLAGS
     CMAKE_CXX_FLAGS_DEBUG
     CMAKE_CXX_FLAGS_RELEASE
     CMAKE_C_FLAGS
     CMAKE_C_FLAGS_DEBUG
     CMAKE_C_FLAGS_RELEASE
     )
 foreach(CompilerFlag ${CompilerFlags})
    string(REPLACE "/MD" "/MT" ${CompilerFlag} "${${CompilerFlag}}")
 endforeach()
 endif(MSVC)
]]

if (MSVC)
set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
endif(MSVC)

# 设置头文件目录
set(SOLUTION_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(SOLUTION_ROOT_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../../)
include_directories(${SOLUTION_ROOT_DIR}/3rdparty/)
include_directories(${SOLUTION_DIR}/include/)
include_directories(${SOLUTION_ROOT_DIR}/include/)
include_directories(${SOLUTION_DIR}/src/)
# 设置输出目录
if (CMAKE_CL_64)
set(PUBLISH_BIN_DEBUG       ${SOLUTION_DIR}/bin/x64/Debug)
set(PUBLISH_BIN_RELEASE     ${SOLUTION_DIR}/bin/x64/Release)
set(PUBLISH_LIB_DEBUG       ${SOLUTION_DIR}/lib/x64/Debug)
set(PUBLISH_LIB_RELEASE     ${SOLUTION_DIR}/lib/x64/Release)
else()
set(PUBLISH_BIN_DEBUG       ${SOLUTION_DIR}/bin/x86/Debug)
set(PUBLISH_BIN_RELEASE     ${SOLUTION_DIR}/bin/x86/Release)
set(PUBLISH_LIB_DEBUG       ${SOLUTION_DIR}/lib/x86/Debug)
set(PUBLISH_LIB_RELEASE     ${SOLUTION_DIR}/lib/x86/Release)
endif()

macro(compile_output_dirs_config arg1)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${SOLUTION_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG ${PUBLISH_BIN_DEBUG}/${arg1})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE ${PUBLISH_BIN_RELEASE}/${arg1})

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${SOLUTION_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${PUBLISH_BIN_DEBUG}/${arg1})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${PUBLISH_BIN_RELEASE}/${arg1})

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${SOLUTION_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG ${PUBLISH_LIB_DEBUG}/${arg1})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE ${PUBLISH_LIB_RELEASE}/${arg1})
endmacro()

compile_output_dirs_config("")

set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set_property(GLOBAL PROPERTY PREDEFINED_TARGETS_FOLDER "CMakeTargets")

add_subdirectory(${SOLUTION_DIR}/cmakes/tests/test_server)
set_target_properties(test_server PROPERTIES FOLDER "tests")

add_subdirectory(${SOLUTION_DIR}/cmakes/tests/test_client)
set_target_properties(test_client PROPERTIES FOLDER "tests")

# VS设置当前启动项
if(MSVC)
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT "test_server")
endif(MSVC)
