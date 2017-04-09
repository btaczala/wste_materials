#ifndef FILEINTERFACE_HPP_DNFBJGTA
#define FILEINTERFACE_HPP_DNFBJGTA

#include <string>

struct FileInterface {
    FileInterface(const std::string& filename) : _filename(filename) {}
    virtual ~FileInterface() {}

    //! This function throws an exception when file cannot be opened
    virtual void open() = 0; 
    virtual bool isOpen() const noexcept = 0;

   private:
    const std::string _filename;
};

#endif /* end of include guard: FILEINTERFACE_HPP_DNFBJGTA */
