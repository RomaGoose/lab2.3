#include <algorithm>
#include <concepts>
#include "sequence_concept.hpp"

template <class Container>
concept stackable = requires (Container c, const Container& cref, typename Container::value_type item) {
    typename Container::value_type;
    typename Container::reference;

    { c.pop() } -> std::same_as<void>;
    { c.push(item) } -> std::same_as<void>;
    { c.push(std::move(item)) } -> std::same_as<void>;
    { c.top() } -> std::same_as<typename Container::value_type&>;

    { cref.top() } -> std::same_as<typename Container::value_type>;
};

template <sequence Seq>
struct seq_stack_adapter {
    
    Seq items_;
    
    using value_type = typename Seq::value_type;
    using reference = typename Seq::reference;
    
    void push(const value_type& item) {
        items_.append(item);
    }
    void push(value_type&& item) {
        items_.append(std::move(item));
    }
    void pop(){
        items_.pop_last();
    }
    reference top(){
        items_.last();
    }
    value_type top() const {
        items_.last();
    }
};