# Project Info

This is a header only library when included via `add_subdirectory` in cmake. It can be used by calling `target_link_libraries([YOUR_TARGET] PUBLIC|PRIVATE projectInfo::projectInfo)`.

## Variables

When including `projectInfo/ProjectInfo.h` you will receive the following variables:

- VERSION[_MAJOR|MINOR|PATCH|TWEAK]: components of the version and the full version string
- GIT_HASH: full git hash
- GIT_BRANCH: git branch name

## Future Features

- Set a license file which passes the license text into a C++ variable
- Combine common variables into a single printable header for your project