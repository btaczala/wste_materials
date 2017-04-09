#include <complex>
#include <iostream>

struct MyCustomType {
    std::string _function;
};

template <typename T>
class Calculator {
   public:
    Calculator() : _result(T{}) {}

    Calculator(T defaultValue) : _result(defaultValue) {}

    template <typename U>
    void add(U u) {
        _result += u;
    }

    T result() const noexcept { return _result; }

   private:
    T _result;
};

int main(int, char* []) {
    Calculator<int> calc;
    Calculator<std::complex<int> > calc2{std::complex<int>{0, 0}};

    calc.add(std::string{"sin(0)"});

    return 0;
}
