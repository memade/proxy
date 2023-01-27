project(proxy)

set(SOURCES_DIR ${CURRENT_SOLUTION_ROOT_DIR}/src/core/)

set(SOURCES
${SOURCES_DIR}main.cpp
${SOURCES_DIR}stdafx.cpp
${SOURCES_DIR}stdafx.h
${SOURCES_DIR}global.cpp
${SOURCES_DIR}global.h
${SOURCES_DIR}core.cpp
${SOURCES_DIR}core.h
${SOURCES_DIR}server.cpp
${SOURCES_DIR}server.h
${SOURCES_DIR}http.cpp
${SOURCES_DIR}http.h
)

add_executable(${PROJECT_NAME} ${SOURCES})

MSVC_SET_LINK_FLAG_CONSOLE(${PROJECT_NAME})

MSVC_RUNTIME_LIBRARY_SET_MT(${PROJECT_NAME})

MSVC_USE_PCH(${PROJECT_NAME} ${SOURCES_DIR}stdafx.h ${SOURCES_DIR}stdafx.cpp)

target_include_directories(${PROJECT_NAME} 
PRIVATE
${SOURCES_DIR}
${CURRENT_SOLUTION_ROOT_DIR}/include
${SOLUTION_ROOT_DIR}/3rdparty
${SOLUTION_ROOT_DIR}/3rdparty/spdlog/include
${SOLUTION_ROOT_DIR}/projects/libcurlpp/include
${SOLUTION_ROOT_DIR}/projects/libuvpp/include
)

target_link_directories(${PROJECT_NAME} 
PRIVATE 
${SOLUTION_ROOT_DIR}/librarys/3rdparty/${VS_PLATFORM}
${SOLUTION_ROOT_DIR}/librarys/shared/${VS_PLATFORM}
)






