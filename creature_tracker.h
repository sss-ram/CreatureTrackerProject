#ifndef CREATURE_TRACKER_H
#define CREATURE_TRACKER_H

#include "creature.h"
#include "creature_type_stats.h"
#include "bs_tree.hpp"
#include "hash_table.hpp"

class CreatureTracker {
public:
    CreatureTracker();

    void addCreature(const Creature& creature);
    void removeCreature(const std::string& name);
    bool creatureExists(const std::string& name) const;
    void printAllCreatures() const;
    void printCreatureTypeStats(const std::string& type) const;
    void printAllCreatureTypeStats() const;

private:
    BSTree<Creature> creatures;
    HashTable<CreatureTypeStats> typeStats;
};

#endif // CREATURE_TRACKER_H
