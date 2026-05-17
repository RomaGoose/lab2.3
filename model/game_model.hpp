#pragma once

#include "array_sequence.hpp"
#include <cassert>
#include <cstddef>
#include <cstdint>

template <template <class> class Stack>
class game_model {
    array_sequence<Stack<uint8_t>> rods;

    size_t total_disk_count_;
    static constexpr uint8_t rods_count_ = 3;
public: 
    game_model(size_t total_disk_count);

    array_sequence<Stack<uint8_t>> get_rods_data() const;
    size_t get_total_disk_count() const;
    bool can_move(uint8_t rod_1, uint8_t rod_2) const;
    void move(uint8_t rod_1, uint8_t rod_2);
};

template <template <class> class Stack>
game_model<Stack>::game_model(size_t total_disk_count) : total_disk_count_(total_disk_count) {
    for(size_t i = 0; i < rods_count_; ++i){
        rods.append(Stack<uint8_t>());
    }
    for(uint8_t disk = total_disk_count; disk > 0; --disk){
        rods[0].push(disk-1);
    }
};

template <template <class> class Stack>
bool game_model<Stack>::can_move(uint8_t rod_from, uint8_t rod_to) const  {
    if (rods[rod_from].is_empty()) return false;
    if (rods[rod_to].is_empty()) return true;

    return rods[rod_from].top() <=  rods[rod_to].top();
};

template <template <class> class Stack>
void game_model<Stack>::move(uint8_t rod_from, uint8_t rod_to) {
    rods[rod_to].push(rods[rod_from].top());
    rods[rod_from].pop();
};

template <template <class> class Stack>
array_sequence<Stack<uint8_t>> game_model<Stack>::get_rods_data() const {
    return rods;
};

template <template <class> class Stack>
size_t game_model<Stack>::get_total_disk_count() const {
    return total_disk_count_;
};

