#include "creature.h"

Creature::Creature(const std::string &name, const std::string &type, int power)
    : name(name), type(type), power(power) {}

std::string Creature::getName() const {
    return name;
}

std::string Creature::getType() const {
    return type;
}

int Creature::getPower() const {
    return power;
}

bool Creature::operator<(const Creature &other) const {
    return name < other.name;
}

bool Creature::operator>(const Creature &other) const {
    return name > other.name;
}

bool Creature::operator==(const Creature &other) const {
    return name == other.name;
}

std::ostream &operator<<(std::ostream &os, const Creature &creature) {
    os << "Name: " << creature.name << ", Type: " << creature.type << ", Power: " << creature.power;
    return os;
}
