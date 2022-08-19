#include <iostream>

#include "projectInfo/ProjectInfo.h"

int main() {
    std::cout
        << "--------------------------------------------------"
        << std::endl
        << "- Project Info provides versioning info in cmake as a c++ source file."
        << std::endl
        << "- Project Info Version: " << projectInfo::VERSION
        << std::endl
        << "--------------------------------------------------"
        << std::endl;
    return 0;
}
