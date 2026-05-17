#pragma once

#include "array_sequence.hpp"
#include "hanoi_widget.hpp"
#include "game_model.hpp"
#include "sequence_stack.hpp"
#include <cassert>
#include <cstddef>
#include <cstdint>
#include <qkeysequence.h>
#include <qtmetamacros.h>
#include "game_controller_base.hpp"

template <template <class> class Stack>
class game_controller : public game_controller_base {
    HanoiWidget* view_;
    game_model<Stack> model_;

    int selected_rod = -1;
public:
    game_controller(HanoiWidget* view, size_t total_disk_count);
    ~game_controller() override = default;
private:
    void update_view();
    array_sequence<list_sequence<uint8_t>> stacks_to_lists(array_sequence<array_stack<uint8_t>> stacks) const;

public slots:
    void on_disks_changed(int new_disk_count) override {
        model_ = game_model<Stack>(new_disk_count);
        update_view();
    };

    void on_rod_clicked(int index) override { //TODO: lifting animation

        if (selected_rod != -1 && index != -1){
            if(selected_rod == index){
                selected_rod = -1;
                update_view();
                return;
            }

            if(model_.can_move(selected_rod, index)){
                model_.move(selected_rod, index);
                selected_rod = -1;
            }
            else {
                //TODO: error message
            }
        }
        else{
            selected_rod = index;
        }
        update_view();
    } 
};

template <template <class> class Stack>
game_controller<Stack>::game_controller(HanoiWidget* view, size_t total_disk_count)
    : view_(view)
    , model_(total_disk_count) {

    connect(
        view_,
        &HanoiWidget::rod_clicked,
        this,
        &game_controller_base::on_rod_clicked
    );
    update_view();
};

template <template <class> class Stack>
void game_controller<Stack>::update_view() {
    view_->clear_canvas();

    auto stack_rods = model_.get_rods_data();
    auto array_rods = stacks_to_lists(stack_rods);
    
    view_->draw_rods();
    view_->draw_disks(array_rods, model_.get_total_disk_count(), selected_rod);
    if(selected_rod != -1){
        view_->draw_selection(selected_rod);
    }
}

template <template <class> class Stack>
array_sequence<list_sequence<uint8_t>> 
game_controller<Stack>::stacks_to_lists(array_sequence<array_stack<uint8_t>> stacks) const {
    
    array_sequence<list_sequence<uint8_t>> arrays;

    size_t i = 0;
    for(auto stack: stacks){
        arrays.append(list_sequence<uint8_t>());
        while(!stack.is_empty()){
            arrays[i].prepend(stack.top());
            stack.pop();
        }
        ++i;
    }
    return arrays;
}
