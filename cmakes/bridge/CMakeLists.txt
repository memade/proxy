project(bridge)

set(SOURCES_DIR ${CURRENT_SOLUTION_ROOT_DIR}/src/${PROJECT_NAME}/)

set(SOURCES
${SOURCES_DIR}main.cpp
${SOURCES_DIR}stdafx.cpp
${SOURCES_DIR}stdafx.h
)

add_executable(${PROJECT_NAME} ${SOURCES})

set_target_properties(${PROJECT_NAME} PROPERTIES LINK_FLAGS "/SUBSYSTEM:CONSOLE")

if(MSVC AND ENABLE_MSVC_CRT_MT)
set_property(TARGET ${PROJECT_NAME} PROPERTY
  MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
endif()

target_include_directories(${PROJECT_NAME} 
PRIVATE
${SPDLOG_INCLUDE_DIR}
)

target_link_directories(${PROJECT_NAME} 
PRIVATE 
${LOCAL_LIBRARYS_SHARED_PATH}/$(Platform)/
${LOCAL_LIBRARYS_3RDPARTY_PATH}/$(Platform)/
)

# MSVC 预编译头设置
if (MSVC)
set(STDAFX_PCH_H ${SOURCES_DIR}stdafx.h)
set(STDAFX_PCH_C ${SOURCES_DIR}stdafx.cpp)
USE_MSVC_PCH(${PROJECT_NAME} stdafx.h ${STDAFX_PCH_C})
endif()



