#include "fs.hpp"

#include <stdexcept>
#include <experimental/filesystem>
#include <fstream>

namespace fs {
std::string readFile(const std::string &path) noexcept(false) {
    if (not exists(path)) {
        throw std::runtime_error("File does not exsists");
    }

    std::ifstream t(path.c_str());
    std::string str;

    t.seekg(0, std::ios::end);
    str.reserve(t.tellg());
    t.seekg(0, std::ios::beg);

    str.assign((std::istreambuf_iterator<char>(t)), std::istreambuf_iterator<char>());
    return str;
}
bool exists(const std::string &path) noexcept {
    return std::experimental::filesystem::exists(path);
}
}
