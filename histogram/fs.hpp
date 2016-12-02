#ifndef FS_HPP
#define FS_HPP

#include <string>

namespace fs {
/**
 * @brief Reads a file into a buffer
 * @param path to a existing file
 * @return A content of a file stored into a std::string buffer
 *         The return buffer will be empty only if sile size is 0
 *
 * @throws A std::runtime_error when a file does not exists
 * @throws A std::runtime_error when a path does not represents a file
 * @throws A std::runtime_error when file is not readible
 */
std::string readFile(const std::string& fileToRead) noexcept(false);

/**
 * @brief Checks if a entry exists under path
 *        This function does not check if an entry is readible
 * @param path Path to be checked
 * @return true if file exists false otherwise
 * @throws This function does not throw
 */
bool exists(const std::string& path) noexcept;
}

#endif /* FS_HPP */
