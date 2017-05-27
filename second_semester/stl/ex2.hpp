#ifndef EX2_HPP_GWJCVDEW
#define EX2_HPP_GWJCVDEW

#include <algorithm>
#include <cstdlib>
#include <vector>

namespace my_std {
int findN(const std::vector<int>& v, int n) {
    auto vit = std::find(v.begin(), v.end(), n);
    if (vit == v.end()) return -1;
    return std::distance(v.begin(), vit);
}

std::vector<int> randomize() {
    std::vector<int> random;
    std::generate_n(std::back_inserter(random), std::rand() % 100, std::rand);
    return random;
}
}

#endif /* end of include guard: EX2_HPP_GWJCVDEW */