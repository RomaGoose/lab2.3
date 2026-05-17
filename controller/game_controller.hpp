#pragma once

#include "array_sequence.hpp"
#include "hanoi_widget.hpp"
#include "game_model.hpp"
#include "sequence_stack.hpp"
#include <cassert>
#include <cstddef>
#include <cstdint>

class game_controller_base {
public: 
    virtual ~game_controller_base() = default;
};

template <template <class> class Stack>
class game_controller : public game_controller_base {
    HanoiWidget* view_;
    game_model<Stack> model_;
public:
    game_controller(HanoiWidget* view, size_t total_disk_count);
private:
    void update_view();
    array_sequence<array_sequence<uint8_t>> stacks_to_arrays(array_sequence<array_stack<uint8_t>> stacks) const;
};



template <template <class> class Stack>
game_controller<Stack>::game_controller(HanoiWidget* view, size_t total_disk_count)
    : view_(view)
    , model_(total_disk_count) {

    update_view();
};

template <template <class> class Stack>
void game_controller<Stack>::update_view() {
    auto stack_rods = model_.get_rods_data();
    auto array_rods = stacks_to_arrays(stack_rods);
    assert(array_rods[0][0] == 0);
    assert(array_rods[0][1] == 1);
    assert(array_rods[0][2] == 2);
    view_->draw_disks(array_rods, model_.get_total_disk_count());
}

template <template <class> class Stack>
array_sequence<array_sequence<uint8_t>> 
game_controller<Stack>::stacks_to_arrays(array_sequence<array_stack<uint8_t>> stacks) const {
    
    array_sequence<array_sequence<uint8_t>> arrays;

    size_t i = 0;
    for(auto stack: stacks){
        arrays.append(array_sequence<uint8_t>());
        while(!stack.is_empty()){
            arrays[i].append(stack.top());
            stack.pop();
        }
        ++i;
    }
    return arrays;
}
