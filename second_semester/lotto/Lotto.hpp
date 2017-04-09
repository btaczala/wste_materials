#ifndef LOTTO_HPP_FMONZTCU
#define LOTTO_HPP_FMONZTCU

#include <algorithm>
#include <array>
#include <cstdlib>
#include <ostream>
#include <set>

struct Lotto {
    typedef std::array<int, 6> Row;
    typedef std::set<Row> CacheType;

    Row generate() const {
        Row r;
        std::generate(r.begin(), r.end(),
                      []() -> int { return std::rand() % 60; });
        cache.insert(r);
        return r;
    }

   private:
    mutable CacheType cache;
};

std::ostream& operator<<(std::ostream& os, const Lotto::Row& r) {
    for (auto v : r) {
        os << " " << v;
    }

    return os;
}

#endif /* end of include guard: LOTTO_HPP_FMONZTCU */
