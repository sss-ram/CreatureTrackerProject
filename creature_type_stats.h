#ifndef CREATURE_TYPE_STATS_H
#define CREATURE_TYPE_STATS_H

#include <string>
#include <iostream>

class CreatureTypeStats {
public:
    CreatureTypeStats(const std::string &type);

    void addCreature(int power);
    void removeCreature(int power);

    std::string getType() const;
    int getCount() const;
    int getTotalPower() const;

    friend std::ostream &operator<<(std::ostream &os, const CreatureTypeStats &stats);

private:
    std::string type;
    int count;
    int totalPower;
};

#endif // CREATURE_TYPE_STATS_H
