#pragma once

#include "stackable.hpp"

template <stackable S> 
class stack {
    S items_;

public:
    using value_type = typename S::value_type;
    using reference = typename S::reference;
    
    void push(const value_type& item) {
        items_.push(item);
    }
    void push(value_type&& item) {
        items_.push(std::move(item));
    }
    void pop(){
        items_.pop();
    }
    reference top(){
        items_.top();
    }
    const reference top() const {
        items_.top();
    }
    size_t size() const noexcept {
        return items_.size();
    }
    bool is_empty() const {
        return items_.size() == 0;
    }
};
