#include <algorithm>
#include <cmath>
#include <iostream>
#include <set>
#include <vector>

struct Shape {
    virtual double area() const = 0;
    virtual ~Shape() {}
};

struct Rect : public Shape {
    Rect(double a, double b) : m_a(a), m_b(b) {}

    virtual double area() const { return m_a * m_b; };

   private:
    double m_a;
    double m_b;
};

struct Square : public Rect {
    Square(double a) : Rect(a, a) {}
};

struct Triangle : public Shape {
    Triangle(double a, double b, double c) : m_a(a), m_b(b), m_c(c) {}

    virtual double area() const { return 0; }

   private:
    double m_a;
    double m_b;
    double m_c;
};

struct Trapezoid : public Shape {
    Trapezoid(const Rect& r, const Triangle& t, const Triangle& t2)
        : m_rect(r), m_t1(t), m_t2(t2) {}

    virtual double area() const { return m_rect.area(); }

   private:
    Rect m_rect;
    Triangle m_t1;
    Triangle m_t2;
};

bool greater_area(const Shape& one, const Shape& two) {
    if (one.area() >= two.area()) {
        return true;
    }
    return false;
}

struct ShapeCmp {
    bool operator()(Shape* o, Shape* t) { return o->area() > t->area(); }
};

int main(int, char* []) {
    std::string input;

    std::set<Shape*, ShapeCmp> shapes;

    while (true) {
        std::cout << "Enter a shape: ";
        std::cin >> input;

        if (input == "square") {
            double bok;
            std::cout << "Give me a side: ";
            std::cin >> bok;
            shapes.insert(new Square(bok));
        }

        if (input == "rect") {
            double bok, bok2;
            std::cout << "Give me two sides: ";
            std::cin >> bok >> bok2;
            shapes.insert(new Rect(bok, bok2));
        }

        if (shapes.size() == 2) break;
    }

    for (auto v : shapes) {
        delete v;
    }
    shapes.clear();

    Square z(15);
    z.area();
    return 0;
}
