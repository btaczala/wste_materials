
#include <cstdio>
#include <fstream>
#include <iostream>

#include "FileInterface.hpp"
#include "FileImpl.hpp"

std::string read_file(const std::string& filename) {
    std::ifstream t(filename.c_str());
    std::string str((std::istreambuf_iterator<char>(t)),
                    std::istreambuf_iterator<char>());
    return str;
}

bool write(const std::string& buff, const std::string& filename) {
    std::ofstream out{filename.c_str()};
    out << buff;
    out.close();

    return true;
}

bool exsits(const std::string& filename) {
    std::ifstream f(filename.c_str());
    return f.good();
}

int main(int argc, char* argv[]) {
    if (argc < 3) return EXIT_FAILURE;

    const std::string source = argv[1];
    const std::string destination = argv[2];

    FileInterface* sourceFile = new FileImpl ( source );
}
