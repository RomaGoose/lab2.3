#pragma once
#include "hanoi_widget.hpp"
#include "game_model.hpp"

class game_controller_base {
public: 
    virtual ~game_controller_base() = default;
};

template <template <class> class Stack>
class game_controller : game_controller_base {
    HanoiWidget* view_;
    game_model<Stack> model_;
public:
    game_controller(HanoiWidget* view, game_model<Stack> model);
};