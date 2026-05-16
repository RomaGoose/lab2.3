#include "settings_controller.hpp"

settings_controller::settings_controller(QComboBox* type_combo, QSpinBox* rods_count_spin) 
    : type_combo_(type_combo)
    , rods_count_spin_(rods_count_spin) {};