#include <iostream>
#include <string>

#include <vector>

int my_atoi(const std::string& s) {
    int v = std::atoi(s.c_str());

    if ((v == 0 && s == "0") || v != 0) {
        return v;
    }

    const std::string error = "Problem with " + s;
    throw std::runtime_error(error.c_str());
}

int sum(const std::vector<std::string>& v) {
    int sum = 0;
    try {
        for (const auto& one : v) {
            sum += my_atoi(one);
        }
    } catch (std::exception& ex) {
        throw ex;
    }

    return sum;
}

int main(int argc, char* argv[]) {
    try {
        std::vector<std::string> numbers;
        for (int i = 1; i < argc; ++i) {
            numbers.push_back(argv[i]);
        }

        std::cout << sum(numbers) << std::endl;
    } catch (const std::runtime_error& ex) {
        std::cout << "std::runtime_error" << ex.what() << std::endl;
    } catch (const std::exception& ex) {
        std::cout << "std::exception" << ex.what() << std::endl;
    }
}
