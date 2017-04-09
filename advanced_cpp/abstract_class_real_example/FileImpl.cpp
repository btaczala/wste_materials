#include "FileImpl.hpp"

FileImpl::FileImpl(const std::string& file) : FileInterface(file)
{}

void FileImpl::open()
{
}

bool FileImpl::isOpen() const noexcept
{
    return false;
}
