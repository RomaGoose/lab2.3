#pragma once

#include "array_sequence.hpp"
#include "hanoi_widget.hpp"
#include "game_model.hpp"
#include "list_sequence.hpp"
#include "sequence_stack.hpp"
#include <cassert>
#include <cstddef>
#include <cstdint>
#include <qkeysequence.h>
#include <qobject.h>
#include <qtmetamacros.h>
#include <qtimer.h>
#include "game_controller_base.hpp"

template <template <class> class Stack>
class game_controller : public game_controller_base {
    HanoiWidget* view_;
    game_model<Stack> model_;

    QTimer* solve_timer_;
    list_sequence<array_sequence<uint8_t>> solution_steps; //TODO: queue
    static constexpr int min_delay = 10;
    int delay;

    int selected_rod = -1;

public:
    game_controller(HanoiWidget* view, size_t total_disk_count);
    ~game_controller() override = default;
    void set_speed(int value) override {
        delay = min_delay / (value / 100.0f);
        solve_timer_->setInterval(delay);
        if (solve_timer_->isActive()) solve_timer_->start();
    }
    void solve() override {
        generate_solution(0, 2, model_.get_total_disk_count());

        solve_timer_->start(delay);
    };

private:
    void update_view();
    array_sequence<list_sequence<uint8_t>> stacks_to_lists(array_sequence<array_stack<uint8_t>> stacks) const;
    void generate_solution(uint8_t from, uint8_t to, size_t disk_number); 


public slots:
    void on_disks_changed(int new_disk_count) override {
        solve_timer_->stop();
        model_ = game_model<Stack>(new_disk_count);
        update_view();
    };

    void on_rod_clicked(int index) override { //TODO: lifting animation
        if(solve_timer_->isActive()) return;
        
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
                emit error_message("Нельзя больший диск ставить на меньший");
            }
        }
        else{
            selected_rod = index;
        }
        update_view();
    } 
    void on_step() override {
        if (solution_steps.size() == 0){
            solve_timer_->stop();
            return;
        }

        model_.move(solution_steps.first()[0], solution_steps.first()[1]);
        solution_steps.pop_first();
        update_view();
    }
    
};

template <template <class> class Stack>
game_controller<Stack>::game_controller(HanoiWidget* view, size_t total_disk_count)
    : view_(view)
    , model_(total_disk_count) 
    , solve_timer_(new QTimer(this)){

    connect(
        view_,
        &HanoiWidget::rod_clicked,
        this,
        &game_controller_base::on_rod_clicked
    );
    connect(
        solve_timer_,
        &QTimer::timeout,
        this,
        &game_controller_base::on_step
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
template <template <class> class Stack>
void game_controller<Stack>::generate_solution(uint8_t from, uint8_t to, size_t disk_number) {
    if(disk_number == 1) {
        solution_steps.append(array_sequence{from, to});
    }
    else{
        uint8_t other = 3 - from - to;
        generate_solution(from, other, disk_number - 1);
        solution_steps.append(array_sequence{from, to});
        generate_solution(other, to, disk_number - 1);
    }
}; 
