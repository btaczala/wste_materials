#include "utils.hpp"
#include <stdexcept>

namespace utils {
std::vector<std::string> split(const std::string& buffer,
                               const std::string& separator /* = "" */) {
    if (buffer.empty()) throw std::runtime_error("Buffer cannot be empty");

    std::vector<std::string> ret;
    std::string tmp;
    for (const auto& a : buffer) {
        if (std::string{a} != separator) {
            tmp += a;
        } else {
            ret.push_back(tmp);
            tmp = "";
        }
    }

    return ret;
}
}
