#include <algorithm>
#include <array>
#include <iostream>
#include <random>
#include <string>
#include <vector>

const std::string help =
    "Scissors cuts Paper\n"
    "Paper covers Rock\n"
    "Rock crushes Lizard\n"
    "Lizard poisons Spock\n"
    "Spock smashes Scissors\n"
    "Scissors decapitates Lizard\n"
    "Lizard eats Paper\n"
    "Paper disproves Spock\n"
    "Spock vaporizes Rock\n"
    "(and as it always has) Rock crushes Scissors\n";

struct Tool {
    typedef std::array<std::string, 2> WinsWithType;

    Tool(const std::string& name, const WinsWithType& winsWith)
        : m_name(name), m_wins(winsWith) {}

    bool winsWith(const Tool& t) const {
        auto f = std::find(m_wins.begin(), m_wins.end(), t.name());
        return f != m_wins.end();
    }
    const std::string& name() const { return m_name; }
    bool operator==(const Tool& t) { return m_name == t.m_name; }

   private:
    const std::string m_name;
    const WinsWithType m_wins;
};

struct Lizard : public Tool {
    Lizard() : Tool("scissors", {{"paper", "spock"}}) {}
};
struct Spock : public Tool {
    Spock() : Tool("spock", {{"rock", "scissors"}}) {}
};
struct Scissors : public Tool {
    Scissors() : Tool("scissors", {{"lizard", "paper"}}) {}
};
struct Paper : public Tool {
    Paper() : Tool("paper", {{"rock", "spock"}}) {}
};

struct Rock : public Tool {
    Rock() : Tool("rock", {{"lizard", "scissors"}}) {}
};

const Tool& winsWith(const Tool& one, const Tool& two) {
    if (one.winsWith(two)) {
        return one;
    }
    return two;
};

struct Player {
    Player() : m_numberOfWins(0), m_tool(nullptr) {}
    Tool* currentTool() const { return m_tool; }

    void randomTool() {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(0, 4);
        auto r = dis(gen);
        if (r == 0) {
            m_tool = new Rock();
        } else if (r == 1) {
            m_tool = new Paper();
        } else if (r == 2) {
            m_tool = new Scissors();
        } else if (r == 3) {
            m_tool = new Lizard();
        } else if (r == 4) {
            m_tool = new Spock();
        }
    }

    int numberOfWins() const { return m_numberOfWins; }

    void win() { m_numberOfWins += 1; }

   private:
    int m_numberOfWins;
    Tool* m_tool;
};

int main(int, char* []) {
    Paper p;
    Rock r;
    Player one, two;

    int i = 0;
    int draws = 0;
    while (++i <= 1000) {
        one.randomTool();
        two.randomTool();

        if (*(one.currentTool()) == *(two.currentTool())) {
            draws++;
            continue;
        }

        if (one.currentTool()->winsWith(*(two.currentTool()))) {
            one.win();
        } else {
            two.win();
        }
    }

    std::cout << "Player 1 wins " << one.numberOfWins() << std::endl;
    std::cout << "Player 2 wins " << two.numberOfWins() << std::endl;
    std::cout << "draws         " << draws << std::endl;

    return 0;
}
