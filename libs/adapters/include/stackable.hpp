#pragma once

#include <algorithm>
#include <concepts>
#include <cstddef>

template <class Container>
concept stackable = requires (Container c, const Container& cref, typename Container::value_type item) {
    typename Container::value_type;
    typename Container::reference;

    { c.pop() } -> std::same_as<void>;
    { c.push(item) } -> std::same_as<void>;
    { c.push(std::move(item)) } -> std::same_as<void>;
    { c.top() } -> std::same_as<typename Container::value_type&>;

    { cref.top() } -> std::convertible_to<typename Container::value_type>;

    { cref.size() } -> std::same_as<size_t>;
    { cref.is_empty() } -> std::same_as<bool>;
};
