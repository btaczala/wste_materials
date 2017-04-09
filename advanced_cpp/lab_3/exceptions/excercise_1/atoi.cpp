#include <exception>
#include <iostream>
#include <string>
#include <vector>

int my_atoi(const std::string& str) {
    int value = std::atoi(str.c_str());
    if (value == 0 && str == "0") {
        return value;
    }

    if (value != 0) return value;

    throw std::invalid_argument("Bad argument");
}

std::vector<int> foo(const std::vector<std::string>& strs) noexcept {
    std::vector<int> toBeReturned;
    try {
        for (const std::string val : strs) {
            toBeReturned.push_back(my_atoi(val));
        }
    } catch (const std::bad_alloc&) {
        // .. 
    }
    return toBeReturned;
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        std::cerr << "" << std::endl;
        return EXIT_FAILURE;
    }

    std::vector<std::string> vec{argv[1], argv[2]};
    try {
        auto v = foo(vec);
        for (auto i : v) std::cout << i << std::endl;
    } catch (const std::exception& ex) {
        std::cerr << "Exception " << std::endl;
    }
}
