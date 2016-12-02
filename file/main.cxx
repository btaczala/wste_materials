#include <iostream>

#include "file.h"

enum class OpenType { eReadOnly = 0, eReadWrite };

auto open(const std::string &filename, OpenType t) {

    if (t == OpenType::eReadOnly) {
        return filesystem::File{filename, O_RDONLY};
    } else {
        return filesystem::File{filename, O_WRONLY | O_APPEND};
    }
}

int main(int argc, char *argv[]) {
    using std::cerr;
    using std::cout;
    using std::endl;

    try {
        if (argc < 2) {
            cerr << "Incorrect number of arguments" << endl;
            return EXIT_FAILURE;
        }

        const std::string fileToRead{argv[1]};

        filesystem::File f = open(fileToRead, argc == 2 ? OpenType::eReadOnly : OpenType::eReadWrite);

        if (argc == 2) {
            cout << f.read() << std::flush;
        } else if (argc == 3) {
            const std::string buff{argv[2]};
            f.write(buff);
        }

    } catch (const std::exception &ex) {
        cerr << "Error = " << ex.what() << endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
