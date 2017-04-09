#include <iostream>
#include <map>
#include <set>
#include <string>

struct SomeType {
    friend std::ostream& operator<<(std::ostream& os, SomeType t);

   private:
    SomeType();
    bool b;
};

std::ostream& operator<<(std::ostream& os, SomeType t) {
    os << t.b;
    return os;
}

int main(int, char* []) {
    std::map<SomeType, std::string> mapaaa{{}};

    return 0;
}
