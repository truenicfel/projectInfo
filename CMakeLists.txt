cmake_minimum_required(VERSION 3.23)

if(NOT PROJECT_IS_TOP_LEVEL)
    option(USE_PARENT_PROJECT_VERSION "Set this to ON if the version of the project that called add_subdirectory should be used." OFF)

    if(USE_PARENT_PROJECT_VERSION)
        set(PROJECT_INFO_VERSION_MAJOR ${PROJECT_VERSION_MAJOR})
        set(PROJECT_INFO_VERSION_MINOR ${PROJECT_VERSION_MINOR})
        set(PROJECT_INFO_VERSION_PATCH ${PROJECT_VERSION_PATCH})
        set(PROJECT_INFO_VERSION_TWEAK ${PROJECT_VERSION_TWEAK})
        set(PROJECT_INFO_VERSION ${PROJECT_VERSION})
    endif()


    set(PROJECT_INFO_GIT_HASH "n/a" CACHE STRING  "Full length git hash.")
    set(PROJECT_INFO_GIT_BRANCH "n/a" CACHE STRING  "Git branch name.")
endif()

project(projectInfo
        VERSION 1.0.0
        LANGUAGES CXX)

set(NAMESPACE "${PROJECT_NAME}::")

set(CMAKE_CXX_STANDARD 20)

if(PROJECT_IS_TOP_LEVEL)
    set(PROJECT_INFO_VERSION ${PROJECT_VERSION})
    add_subdirectory(runner)
endif()

add_subdirectory(projectInfo)
