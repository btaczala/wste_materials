#include "file.h"

#include <stdexcept>
#include <iostream>
#include <unistd.h>

#define LOG(a)                                                                                                         \
    if (filesystem::File::g_logging)                                                                                   \
        std::cout << __FUNCTION__ << "@" << __LINE__ << a << std::endl;
#define ERR(a)                                                                                                         \
    if (filesystem::File::g_logging)                                                                                   \
        std::cerr << __FUNCTION__ << "@" << __LINE__ << a << std::endl;

namespace {
const std::uint32_t kReadSize = 128;
}
namespace filesystem {

bool File::g_logging = false;

File::File(const std::string &filename, OpenFlags flags) : _handle(open(filename.c_str(), flags)), _filename(filename) {
    if (_handle < 0) {
        const std::string error{"Unable to open file " + filename + " error code= " + std::to_string(_handle)};
        ERR(error);
        throw std::runtime_error(error);
    }
}

File::~File() noexcept {
    auto resultCode = close(_handle);

    if (resultCode < 0) {
        ERR("Unable to close file handle = " << _handle << " for file = " << _filename);
    }
}

File::File(const File &rhs) {
    int ret = dup2(_handle, rhs._handle);
    if (ret < 0) {
        throw std::runtime_error("Unable to copy a file");
    }
}

File &File::operator=(const File &rhs) {
    // This is a typical swap implementation
    // that prevents from being in invalid state after
    // assignment operation fails (when dup2 fails)

    int oldHandle = _handle;
    int ret = dup2(_handle, rhs._handle);
    if (ret < 0) {
        _handle = oldHandle;
        throw std::runtime_error("Unable to copy a file");
    }
    ::close(oldHandle);
    return *this;
}

bool File::exists(const std::string &filename) {
    bool bRet{false};
    try {
        File f{filename, O_RDONLY};
        bRet = true;
    } catch (const std::exception &ex) {
    }

    return bRet;
}

std::string File::read() {
    std::string ret;

    char buff[kReadSize];

    while (true) {
        auto bytesRead = ::read(_handle, buff, kReadSize);

        if (bytesRead < 0) {
            throw std::runtime_error("Unable to read file " + _filename);
        }

        if (bytesRead == kReadSize) {
            ret += buff;
        } else {
            ret.append(buff, bytesRead);
            break;
        }
    }
    return ret;
}

void File::write(const std::string &buffer) {
    ::write(_handle, buffer.c_str(), buffer.size());
}

/**/ void File::setLogging(bool bEnable) {
    g_logging = bEnable;
}

} // namespace
