#ifndef HASH_TABLE_HPP
#define HASH_TABLE_HPP

#include <list>
#include <vector>
#include <string>
#include <functional>
#include <iostream>
#include <optional>

template <typename T>
class HashTable {
public:
    HashTable(size_t capacity = 101)
        : table(capacity), capacity(capacity) {}

    void insert(const std::string& key, const T& value) {
        size_t index = hash_function(key);
        table[index].push_back({key, value});
    }

    void remove(const std::string& key) {
        size_t index = hash_function(key);
        table[index].remove_if([&key](const std::pair<std::string, T>& item) {
            return item.first == key;
        });
    }

    std::optional<T> find(const std::string& key) const {
        size_t index = hash_function(key);
        for (const auto& item : table[index]) {
            if (item.first == key) {
                return item.second;
            }
        }
        return std::nullopt;
    }

    void print() const {
        for (size_t i = 0; i < capacity; ++i) {
            std::cout << i << ": ";
            for (const auto& item : table[i]) {
                std::cout << "[" << item.first << ": " << item.second << "] ";
            }
            std::cout << std::endl;
        }
    }

private:
    std::vector<std::list<std::pair<std::string, T>>> table;
    size_t capacity;

    size_t hash_function(const std::string& key) const {
        std::hash<std::string> hash_fn;
        return hash_fn(key) % capacity;
    }
};

#endif // HASH_TABLE_HPP
