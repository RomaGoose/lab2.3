#include "game_controller.h"

template <template <class> class Stack>
game_controller<Stack>::game_controller(HanoiWidget* view, game_model<Stack> model)
    : view_(view)
    , model_(model) {};


