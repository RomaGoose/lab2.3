#include <algorithm>
#include <concepts>

template <class Container>
concept stackable = requires (Container c, const Container& cref, typename Container::value_type item) {
    typename Container::value_type;

    { c.pop() } -> std::same_as<void>;
    { c.push(item) } -> std::same_as<void>;
    { c.push(std::move(item)) } -> std::same_as<void>;
    { c.top() } -> std::same_as<typename Container::value_type&>;

    { cref.top() } -> std::same_as<typename Container::value_type>;
};