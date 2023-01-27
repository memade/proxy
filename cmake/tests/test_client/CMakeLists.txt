project(test_client)

set(SOURCES_DIR ${SOLUTION_DIR}/tests/${PROJECT_NAME}/)

set(SOURCES
${SOURCES_DIR}main.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})

set_target_properties(${PROJECT_NAME} PROPERTIES LINK_FLAGS "/SUBSYSTEM:CONSOLE")

# 指定专用库头文件目录
target_include_directories(${PROJECT_NAME} 
PRIVATE 
${SOLUTION_ROOT_DIR}/3rdparty/spdlog/include/
${SOLUTION_ROOT_DIR}/include/openssl/3.0.5/
)

# 依赖库目录
target_link_directories(${PROJECT_NAME} 
PRIVATE 
${SOLUTION_ROOT_DIR}/librarys/$(Platform)/
${SOLUTION_ROOT_DIR}/librarys/openssl/3.0.5/$(Platform)/
)

#[[
# MSVC 预编译头设置
if (MSVC)
set(MSVCCMAKE_PCH ${SOLUTION_DIR}/cmakes/)
set(STDAFX_PCH_H ${SOURCES_DIR}stdafx.h)
set(STDAFX_PCH_C ${SOURCES_DIR}stdafx.cpp)
LIST(APPEND CMAKE_MODULE_PATH ${MSVCCMAKE_PCH})
INCLUDE(msvcpch)
USE_MSVC_PCH(${PROJECT_NAME} stdafx.h ${STDAFX_PCH_C})
endif()
]]





