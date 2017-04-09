#include "utils.hpp"
#include <stdexcept>

#include <boost/algorithm/string/classification.hpp>
#include <boost/algorithm/string/split.hpp>

namespace utils {
std::vector<std::string>& split(const std::string &buffer, const std::string &separator /* = " " */) {
    if (buffer.empty())
        throw std::runtime_error("Buffer cannot be empty");

    std::vector<std::string> words;
    boost::split(words, buffer, boost::is_any_of(separator.empty() ? " " : separator), boost::token_compress_on);

    return words;
}
}
