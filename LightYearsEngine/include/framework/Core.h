#pragma once

#include <stdio.h>
#include <memory>
#include <vector>
#include <map>
#include <unordered_map>

namespace ly {
    template <typename T>
    using unique = std::unique_ptr<T>;

    template <typename T>
    using shared = std::shared_ptr<T>;

    template <typename T>
    using weak = std::weak_ptr<T>;

    template <typename T>
    using List = std::vector<T>;

    template <typename KeyType, typename ValueType, typename Pr = std::less<KeyType>>
    using Map = std::map<KeyType, ValueType, Pr>;

    template <typename KeyType, typename ValueType, typename Hasher = std::hash<KeyType>>
    using Dictionary = std::unordered_map<KeyType, ValueType, Hasher>;

#define LOG(M, ...) printf(M "\n", ##__VA_ARGS__);
};  // namespace ly
