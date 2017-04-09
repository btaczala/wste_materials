#include <iostream>
#include <vector>
#include "Lotto.hpp"

int main(int, char* []) {
    Lotto machine;

    std::cout << "Podaj ilosc losowan ";
    std::uint32_t n;
    std::cin >> n;

    std::vector<Lotto::Row> results{n};

    std::generate(results.begin(), results.end(),
                  [&machine]() -> Lotto::Row { return machine.generate(); });

    for (const auto one : results) {
        std::cout << one << std::endl;
    }

    return 0;
}
