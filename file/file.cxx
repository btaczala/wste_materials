#include "file.h"

#include <stdexcept>
#include <unistd.h>

namespace filesystem {

File::File(const std::string &filename, OpenFlags flags) : _handle(open(filename.c_str(), flags)) {
    if (_handle < 0) {
        const std::string error{"Unable to open " + filename + "error code= " + std::to_string(_handle)};
        throw std::runtime_error(error);
    }
}

File::~File() noexcept {
    close(_handle);
}

File::File(const File &rhs) {
    int ret = dup2(_handle, rhs._handle);
    if (ret < 0) {
        throw std::runtime_error("Unable to copy a file");
    }
}

File &File::operator=(const File &rhs) {
    ::close(_handle);
    int ret = dup2(_handle, rhs._handle);
    if (ret < 0) {
        throw std::runtime_error("Unable to copy a file");
    }
    return *this;
}

std::string File::read() {
    std::string ret;
    return ret;
}

void File::write(const std::string &buffer) {
    ::write(_handle, buffer.c_str(), buffer.size());
}
}
