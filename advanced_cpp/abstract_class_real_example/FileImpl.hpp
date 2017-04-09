#ifndef FILEIMPL_HPP_57ESIF0K
#define FILEIMPL_HPP_57ESIF0K

#include "FileInterface.hpp"

struct FileImpl : public FileInterface {
    FileImpl(const std::string& filename);

    void open() override; 

    bool isOpen() const noexcept override;
};

#endif /* end of include guard: FILEIMPL_HPP_57ESIF0K */
