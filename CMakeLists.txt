cmake_minimum_required(VERSION 3.22)

option(USE_CMAKE_HELPERS "Set this to ON if the version should be retrieved using cmake helpers (https://github.com/truenicfel/cmakeHelpers)." OFF)

if(NOT USE_CMAKE_HELPERS)
    option(USE_PARENT_PROJECT_VERSION "Set this to on if version information should be taken from parent project (does not work for branch and hash)." OFF)

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
        VERSION 1.1.0
        LANGUAGES CXX)

set(NAMESPACE "${PROJECT_NAME}::")

set(CMAKE_CXX_STANDARD 20)

if(USE_CMAKE_HELPERS)

    if(NOT DEFINED CMAKE_HELPERS_GIT_REPOSITORY_PATH)
        set(CMAKE_HELPERS_GIT_REPOSITORY_PATH "" CACHE STRING  "The path to the git repository that should be used to retrieve version information from.")
        message(FATAL_ERROR "CMAKE_HELPERS_GIT_REPOSITORY_PATH must be defined.")
    endif()

    include(FetchContent)
    FetchContent_Declare(cmake_helpers
            GIT_REPOSITORY https://github.com/truenicfel/cmakeHelpers
            GIT_TAG 8cb39f37c6b1d1048e1460c3500f681b59530434 # v1.2.0
            )
    FetchContent_MakeAvailable(cmake_helpers)

    isGitRepository(${CMAKE_HELPERS_GIT_REPOSITORY_PATH})
    if(NOT GIT_REPOSITORY_FOUND)
        message(FATAL_ERROR "CMAKE_HELPERS_GIT_REPOSITORY_PATH must be a path to a git repository. ${CMAKE_HELPERS_GIT_REPOSITORY_PATH} is not.")
    endif()

    getVersionFromGitTag(${CMAKE_HELPERS_GIT_REPOSITORY_PATH})
    getGitHash(${CMAKE_HELPERS_GIT_REPOSITORY_PATH})
    getGitBranch(${CMAKE_HELPERS_GIT_REPOSITORY_PATH})

    if(NOT GIT_TAG_VERSION_FOUND)
        message(WARNING "Could not find a git tag to retrieve version information from in repository ${PATH_TO_GIT_REPO}.")
    endif()
    set(PROJECT_INFO_VERSION_MAJOR "${VERSION_MAJOR}")
    set(PROJECT_INFO_VERSION_MINOR "${VERSION_MINOR}")
    set(PROJECT_INFO_VERSION_PATCH "${VERSION_PATCH}")
    set(PROJECT_INFO_VERSION_TWEAK "${VERSION_TWEAK}")
    set(PROJECT_INFO_VERSION "${VERSION_COMBINED}")

    if(NOT GIT_BRANCH_FOUND)
        message(WARNING "Could not find a git branch in repository ${PATH_TO_GIT_REPO}.")
    endif()
    set(PROJECT_INFO_GIT_BRANCH "${GIT_BRANCH}")

    if(NOT COMMIT_HASH_FOUND)
        message(WARNING "Could not find a git commit hash in repository ${PATH_TO_GIT_REPO}.")
    endif()
    set(PROJECT_INFO_GIT_HASH "${COMMIT_HASH}")


endif()

if(PROJECT_IS_TOP_LEVEL)
    add_subdirectory(runner)
endif()

add_subdirectory(projectInfo)
