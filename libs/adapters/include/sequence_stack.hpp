#pragma once

#include "array_sequence.hpp"
#include "sequence_concept.hpp"
#include "stack.hpp"
#include <cstddef>


template <sequence Seq>
struct seq_stack_adapter {
    
    Seq items_;
    
    using value_type = typename Seq::value_type;
    using reference = typename Seq::reference;
    using const_reference = const value_type&;
    
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
        return items_.last();
    }
    const_reference top() const {
        return items_.last();
    }
    size_t size() const noexcept {
        return items_.size();
    }
    bool is_empty() const {
        return items_.size() == 0;
    }
};


template <class T>
using array_stack = stack<seq_stack_adapter<array_sequence<T>>>;
template <class T>
using list_stack = stack<seq_stack_adapter<array_sequence<T>>>;