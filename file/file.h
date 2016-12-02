#ifndef FILE_H
#define FILE_H

#include <string>
#include <fcntl.h>

namespace filesystem {
typedef int OpenFlags;
typedef int HandleType;
/**
 * @brief A RAII implementation of a file access
 *  If a file does not exists or is not readible the constructor will thrown 
 *  an exception
 */
struct File {
    /**
     * @brief Creates na File object and automatically opens a file
     * @param filename File to be open
     * @param flags What is the mode to open the file
     */
    File(const std::string &filename, OpenFlags flags);

    /**
     * @brief Dctor will close opened file.
     */
    ~File() noexcept;

    /**
     * @brief Copy constructor
     * @throws std::runtime_error when underlying copy operation has failed
     * @param rhs Other object
     */
    File(const File &rhs);

    /**
     * @brief Assignment operator that assigns new value to the object
     *  Whenever underlying assignment operation fails this object is in 
     *  valid state as it was before. 
     * @param rhs Other object
     * @throws std::runtime_error when assignment fails
     * @return Instance of the same object
     */
    File &operator=(const File &rhs);

    //! Check object validity. Almost never this can return false
    bool isValid() const noexcept;

    /**
     * @brief Checks if a given path exists
     * @param filename
     * @return 
     */
    static bool exists(const std::string &filename);

    void write(const std::string &buffer);
    std::string read();

    static void setLogging(bool bEnable);

private:
    HandleType _handle;
    const std::string _filename;

    static bool g_logging;
};
}

#endif /* FILE_H */
