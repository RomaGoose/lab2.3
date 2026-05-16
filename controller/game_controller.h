#pragma once
#include "hanoi_widget.h"
#include "game_model.h"

class game_controller_base {
    virtual ~game_controller_base() = default;
};

template <template <class> class Stack>
class game_controller : game_controller_base {
    HanoiWidget* view_;
    game_model<Stack> model_;
public:
    game_controller(HanoiWidget* view, game_model<Stack> model);
};