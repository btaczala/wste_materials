#include <algorithm>
#include <iostream>
#include <numeric>
#include <stdexcept>

#include "fs.hpp"
#include "utils.hpp"

namespace {
const std::size_t kMinimalArguments{2};
}

int main(int argc, char *argv[]) {
    using std::cout;
    using std::endl;

    try {
        if (static_cast<std::size_t>(argc) < kMinimalArguments) {
            throw std::runtime_error("Incorrect number of arguments");
        }

        const std::string searchedWord{argc == 2 ? "" : argv[2]};
        const auto splitted = utils::split(fs::readFile(argv[1]), argc == 4 ? argv[3] : " ");

        const auto result = std::count_if(splitted.begin(), splitted.end(), [&](const auto &a) -> bool {
            if (searchedWord.empty()) {
                return true;
            } else {
                return searchedWord == a;
            }
        });

        cout << result << endl;

    } catch (const std::exception &ex) {
        cout << ex.what() << endl;
    }
}
