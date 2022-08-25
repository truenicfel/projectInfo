cmake_minimum_required(VERSION 3.22)

if(NOT PROJECT_IS_TOP_LEVEL)
    option(USE_PARENT_PROJECT_VERSION "Set this to ON if the version of the project that called add_subdirectory should be used." ON)

    if(USE_PARENT_PROJECT_VERSION)
        set(PROJECT_INFO_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}" CACHE STRING  "The major version number.")
        set(PROJECT_INFO_VERSION_MINOR "${PROJECT_VERSION_MINOR}" CACHE STRING  "The minor version number.")
        set(PROJECT_INFO_VERSION_PATCH "${PROJECT_VERSION_PATCH}" CACHE STRING  "The patch version number.")
        set(PROJECT_INFO_VERSION_TWEAK "${PROJECT_VERSION_TWEAK}" CACHE STRING  "The tweak version number.")
        set(PROJECT_INFO_VERSION "${PROJECT_VERSION}" CACHE STRING  "The tweak version number.")
    else()
        set(PROJECT_INFO_VERSION_MAJOR "n/a" CACHE STRING  "The major version number.")
        set(PROJECT_INFO_VERSION_MINOR "n/a" CACHE STRING  "The minor version number.")
        set(PROJECT_INFO_VERSION_PATCH "n/a" CACHE STRING  "The patch version number.")
        set(PROJECT_INFO_VERSION_TWEAK "n/a" CACHE STRING  "The tweak version number.")
        set(PROJECT_INFO_VERSION "n/a" CACHE STRING  "The tweak version number.")
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
