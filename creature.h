#ifndef CREATURE_H
#define CREATURE_H

#include <string>
#include <iostream>

class Creature {
public:
    Creature(const std::string &name, const std::string &type, int power);

    std::string getName() const;
    std::string getType() const;
    int getPower() const;

    bool operator<(const Creature &other) const;
    bool operator>(const Creature &other) const;
    bool operator==(const Creature &other) const;

    friend std::ostream &operator<<(std::ostream &os, const Creature &creature);

private:
    std::string name;
    std::string type;
    int power;
};

#endif // CREATURE_H
