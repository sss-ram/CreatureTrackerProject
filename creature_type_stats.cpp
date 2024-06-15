#include "creature_type_stats.h"

CreatureTypeStats::CreatureTypeStats(const std::string &type)
    : type(type), count(0), totalPower(0) {}

void CreatureTypeStats::addCreature(int power) {
    count++;
    totalPower += power;
}

void CreatureTypeStats::removeCreature(int power) {
    if (count > 0) {
        count--;
        totalPower -= power;
    }
}

std::string CreatureTypeStats::getType() const {
    return type;
}

int CreatureTypeStats::getCount() const {
    return count;
}

int CreatureTypeStats::getTotalPower() const {
    return totalPower;
}

std::ostream &operator<<(std::ostream &os, const CreatureTypeStats &stats) {
    os << "Type: " << stats.type << ", Count: " << stats.count << ", Total Power: " << stats.totalPower;
    return os;
}
