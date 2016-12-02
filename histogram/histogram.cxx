#include <algorithm>
#include <iostream>
#include <numeric>
#include <stdexcept>

#include "fs.hpp"
#include "utils.hpp"

namespace {
const size_t kMinimalArguments{2};
}

void printUsage(const std::string &programName) {
    using std::cout;
    using std::endl;

    cout << programName << " path_to_file " << "[searchedWord]" << endl;
}

int main(int argc, char *argv[]) {
    using std::cout;
    using std::endl;

    try {
        if (static_cast<size_t>(argc) < kMinimalArguments) {
            printUsage(argv[0]);
            throw std::runtime_error("Incorrect number of arguments");
        }

        std::string searchedWord;
        if (argc > 2) {
            searchedWord = argv[2];
        }

        auto buff = fs::readFile(argv[1]);
        const auto splitted = utils::split(buff, argc == 4 ? argv[3] : " ");

        const auto result = std::count_if(splitted.begin(), splitted.end(), [&](const auto &a) -> bool {
            if (searchedWord.empty()) {
                return true;
            } else {
                return searchedWord == a;
            }
        });

        cout << result << endl;
        return EXIT_SUCCESS;

    } catch (const std::exception &ex) {
        cout << ex.what() << endl;
        return EXIT_FAILURE;
    }
}
