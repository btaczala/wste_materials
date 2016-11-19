#include "fs.hpp"

#include <stdexcept>
#include <experimental/filesystem>
#include <fstream>

namespace fs {
std::string readFile(const std::string& path) noexcept(false) {
    if (not exists(path)) {
        throw std::runtime_error("File does not exsists");
    }

    std::ifstream fileToRead;
    fileToRead.open(path.c_str());
    return "";
}
bool exists(const std::string& path) noexcept {
    return std::experimental::filesystem::exists(path);
}
}
