set(EXECUTABLE_NAME "runner")

add_executable(${EXECUTABLE_NAME} source/main.cpp)
add_executable(${NAMESPACE}${EXECUTABLE_NAME} ALIAS ${EXECUTABLE_NAME})

target_link_libraries(${EXECUTABLE_NAME} ${NAMESPACE}projectInfo)