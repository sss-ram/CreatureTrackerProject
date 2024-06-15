#include "creature_tracker.h"

// Implementing CreatureTracker methods as required in creature_tracker.h

CreatureTracker::CreatureTracker() : creatures(), typeStats() {}

void CreatureTracker::addCreature(const Creature& creature) {
    creatures.insert(creature);
    
    if (!typeStats.find(creature.getType())) {
        CreatureTypeStats stats(creature.getType());
        stats.addCreature(creature.getPower());
        typeStats.insert(creature.getType(), stats);
    } else {
        // Increment the count and total power for the type
        auto it = typeStats.find(creature.getType());
        if (it != typeStats.end()) {
            CreatureTypeStats updatedStats = it->second;
            updatedStats.addCreature(creature.getPower());
            typeStats.remove(creature.getType());
            typeStats.insert(creature.getType(), updatedStats);
        }
    }
}

void CreatureTracker::removeCreature(const std::string& name) {
    for (const auto& creature : creatures) {
        if (creature.getName() == name) {
            auto it = typeStats.find(creature.getType());
            if (it != typeStats.end()) {
                CreatureTypeStats updatedStats = it->second;
                updatedStats.removeCreature(creature.getPower());
                typeStats.remove(creature.getType());
                if (updatedStats.getCount() > 0) {
                    typeStats.insert(creature.getType(), updatedStats);
                }
            }
            creatures.remove(creature);
            break;
        }
    }
}

bool CreatureTracker::creatureExists(const std::string& name) const {
    for (const auto& creature : creatures) {
        if (creature.getName() == name) {
            return true;
        }
    }
    return false;
}

void CreatureTracker::printAllCreatures() const {
    creatures.inorder();
}

void CreatureTracker::printCreatureTypeStats(const std::string& type) const {
    auto it = typeStats.find(type);
    if (it != typeStats.end()) {
        std::cout << it->second << std::endl;
    } else {
        std::cout << "No creatures of type " << type << " found." << std::endl;
    }
}

void CreatureTracker::printAllCreatureTypeStats() const {
    typeStats.print();
}
