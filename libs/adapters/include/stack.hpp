#pragma once

#include "stackable.hpp"
#include <initializer_list>

template <stackable S> 
class stack {
    S items_;

public:
    using value_type = typename S::value_type;
    using reference = typename S::reference;
    using const_reference = const value_type&;
    
    stack(std::initializer_list<value_type> list = {}) {
        for(auto el: list){
            push(el);
        }
    }

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
        return items_.top();
    }
    const_reference top() const {
        return items_.top();
    }
    size_t size() const noexcept {
        return items_.size();
    }
    bool is_empty() const {
        return items_.size() == 0;
    }
};
