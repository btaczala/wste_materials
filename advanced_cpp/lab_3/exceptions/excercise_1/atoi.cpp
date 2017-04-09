#include <exception>
#include <iostream>
#include <string>
#include <vector>

void* operator new(size_t size) {
    throw std::bad_alloc();
    return nullptr;
}

int my_atoi(const std::string& str) {
    int value = std::atoi(str.c_str());
    if (value == 0 && str == "0") {
        return value;
    }

    if (value != 0) return value;

    throw std::invalid_argument("Bad argument");
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "" << std::endl;
        return EXIT_FAILURE;
    }

    int* p;
    try {
        p = new int;
        std::cout << my_atoi(argv[1]) << std::endl;
        delete p;
    } catch (const std::exception& ex) {
        std::cerr << "Exception happened " << ex.what() << std::endl;
        delete p;
    } catch (const std::bad_alloc& ex) {
        std::cerr << "Bad Exception happened " << ex.what() << std::endl;
    }
    return EXIT_SUCCESS;
}
