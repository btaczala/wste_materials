#include <iostream>

struct DateOfBirth {
    DateOfBirth(std::uint8_t day, std::uint8_t month, std::uint64_t year) {
        if (day > 31) throw std::runtime_error("");
        if (month > 12) throw std::runtime_error("");
    }

    std::uint8_t day;
    std::uint8_t month;
    std::uint64_t year;
};

struct Human {
    Human(const DateOfBirth& db) : m_date_of_birth(db) {}

    std::string getName() const { return m_name; }
    virtual void setName(const std::string& name) = 0;

    void setColor(const std::string& _c) { color = _c; }

   protected:
    std::string m_name;
    const DateOfBirth m_date_of_birth;
    std::string color;
};

struct Man : public Human {
    Man(const DateOfBirth& db, int _w) : Human(db), weight(_w) {}

    virtual void setName(const std::string& name) {
        if (name == "judy") {
            throw std::runtime_error("man cannot be named judy");
        }
        m_name = name;
    }

    int getWeight() { return weight; }

   protected:
    const int weight;
};

struct Woman : public Human {
    Woman(const DateOfBirth& db) : Human(db) {}
    virtual void setName(const std::string& name) {
        if (name == "judy") {
            throw std::runtime_error("man cannot be named judy");
        }
        m_name = name;
    }
};

int main(int, char* []) {
    Man m{DateOfBirth{31, 10, 2019}, 10};
    Woman n{DateOfBirth{31, 10, 2019}};

    return 0;
}
