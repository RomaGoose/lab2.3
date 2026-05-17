#include "game_controller_base.hpp"
#include <qobject.h>

game_controller_base::game_controller_base(QObject* parent) : QObject(parent) {};
game_controller_base::~game_controller_base() = default;