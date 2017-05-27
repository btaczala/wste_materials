#ifndef EX2_HPP_GWJCVDEW
#define EX2_HPP_GWJCVDEW

#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <list>
#include <numeric>
#include <vector>

template <class OutputIterator, class Size, class Assignable>
void iota_n(OutputIterator first, Size n, Assignable value) {
    std::generate_n(first, n, [&value]() { return value++; });
}

namespace my_std {
int findN(const std::vector<int>& v, int n) {
    // auto vit = std::find(v.begin(), v.end(), n);
    auto vit = std::find_if(v.begin(), v.end(),
                            [n](int value) -> bool { return value == n; });
    if (vit == v.end()) return -1;
    return std::distance(v.begin(), vit);
}

void insert_to_list(std::list<int>& l) {
    l = std::list<int>();
    int counter = 0;
    std::generate_n(std::back_inserter(l), 10,
                    [&counter]() -> int { return counter++; });
}

std::vector<int> randomize() {
    std::vector<int> random;
    std::generate_n(std::back_inserter(random), std::rand() % 100, std::rand);
    return random;
}

void print(const std::vector<std::string> v, std::ostream& s) {
    std::for_each(v.begin(), v.end() - 1,
                  [&s](const std::string& str) { s << str << ", "; });
    s << v[v.size() - 1];
}

std::string upper(const std::string& str) {
    std::string t = str;
    std::for_each(t.begin(), t.end(), [](char& t) { t = std::toupper(t); });
    return t;
}

double mean(const std::vector<int>& v) {
    if (v.empty()) return 0.0f;

    int sum = 0;
    std::for_each(v.begin(), v.end(), [&sum](int value) { sum += value; });
    return static_cast<double>(sum) / static_cast<double>(v.size());
}

std::size_t count_odd(const std::vector<int>& v) {
    return std::count_if(v.begin(), v.end(), [](int d) { return d % 2 != 0; });
}

int closest_to_zero(const std::vector<int>& v) {
    auto it = std::min_element(v.begin(), v.end(), [](int f, int s) -> bool {
        return std::abs(f) < std::abs(s);
    });

    return *it;
}

std::vector<std::size_t> find_all (const std::vector<int>& v, int N)
{
    std::vector<std::size_t> toReturn;
    auto it = std::find(v.begin(), v.end(), N);

    while(it != v.end())
    {
        toReturn.push_back(std::distance(v.begin(), it));
        it = std::find(++it, v.end(), N); 
    }

    return toReturn;
}

























}

#endif /* end of include guard: EX2_HPP_GWJCVDEW */
