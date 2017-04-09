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

    // throw std::invalid_argument("Bad argument");
    throw 10;
}

int main(int argc, char* argv[]) {
    if (argc < 2) return EXIT_FAILURE;

    try {
        std::cout << my_atoi(argv[1]) << std::endl;
    } catch (int v) {
        std::cerr << "Exception happened " << std::endl;
    }

    return EXIT_SUCCESS;
}
