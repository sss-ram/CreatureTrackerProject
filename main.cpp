#include "creature_tracker.h"
#include <iostream>

int main() {
    CreatureTracker tracker;

    Creature creature1("Dragon", "Fire", 100);
    Creature creature2("Unicorn", "Magic", 80);
    Creature creature3("Goblin", "Earth", 50);

    tracker.addCreature(creature1);
    tracker.addCreature(creature2);
    tracker.addCreature(creature3);

    std::cout << "All creatures:" << std::endl;
    tracker.printAllCreatures();

    std::cout << "Type stats for 'Fire':" << std::endl;
    tracker.printCreatureTypeStats("Fire");

    std::cout << "Type stats for 'Magic':" << std::endl;
    tracker.printCreatureTypeStats("Magic");

    std::cout << "All creature type stats:" << std::endl;
    tracker.printAllCreatureTypeStats();

    tracker.removeCreature("Dragon");

    std::cout << "All creatures after removing Dragon:" << std::endl;
    tracker.printAllCreatures();

    std::cout << "All creature type stats after removing Dragon:" << std::endl;
    tracker.printAllCreatureTypeStats();

    return 0;
}
