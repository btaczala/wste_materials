#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
#include <iomanip>
#include <sstream>

struct Employee {
    std::string _name; 
    std::string _surname; 
    int m_height;
};

std::string json(const Employee& e)
{
}

std::ostream& operator<<(std::ostream& os, const Employee& b)
{
    os << b._name << " " << b._surname << " " << b.m_height; 
    return os;
}

std::istream& operator>> (std::istream& is, Employee& e)
{
    is >> e._name >> e._surname >> e.m_height;
    return is;
}
    


int main(int , char *[]) {

    Employee a;
    std::cin >> a;

    std::ostringstream ss;

    ss << json(Bartek) << std::endl;

    return 0;
}
