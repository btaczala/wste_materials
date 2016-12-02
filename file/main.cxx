#include <iostream>

#include "file.h"

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

        filesystem::OpenFlags flags{argc == 2 ? O_RDONLY : O_WRONLY};
        filesystem::File f{fileToRead, flags};

        if (argc == 2) {
            cout << f.read() << endl;
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
