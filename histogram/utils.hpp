#ifndef UTILS_HPP
#define UTILS_HPP

#include <string>
#include <vector>

namespace utils {
/**
 * @brief Function that splits a string by a given separator into a vector of string
 *
 * @param buffer - A buffer to split
 * @param separator - A separator. 
 *  Default separator value is a space. 
 *
 * @return A vector of strings 
 */
std::vector<std::string>& split(const std::string& buffer,
                               const std::string& separator = " ");
}

#endif /* UTILS_HPP */
