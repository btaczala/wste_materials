#ifndef FILE_H
#define FILE_H

#include <string>
#include <fcntl.h>

namespace filesystem {
typedef int OpenFlags;
typedef int HandleType;
struct File {
    File(const std::string &filename, OpenFlags flags);
    ~File() noexcept;

    File(const File &rhs);
    File &operator=(const File &rhs);

    bool isValid() const noexcept;

    static bool exists(const std::string &filename);

    void write(const std::string &buffer);
    std::string read();

private:
    HandleType _handle;
};
}

#endif /* FILE_H */
