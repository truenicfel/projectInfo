set(LIBRARY_NAME
        projectInfo)

add_library(${LIBRARY_NAME} INTERFACE)
add_library("${NAMESPACE}${LIBRARY_NAME}" ALIAS ${LIBRARY_NAME})

configure_file(
        "${CMAKE_CURRENT_SOURCE_DIR}/configure/projectInfo/ProjectInfo.h.in"
        "${PROJECT_BINARY_DIR}/include/projectInfo/ProjectInfo.h"
        )

target_include_directories(${LIBRARY_NAME} INTERFACE "${PROJECT_BINARY_DIR}/include")

