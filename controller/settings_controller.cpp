#include "settings_controller.hpp"

settings_controller::settings_controller(QComboBox* type_combo, QSpinBox* rods_count_spin) 
    : type_combo_(type_combo)
    , rods_count_spin_(rods_count_spin) {};


size_t settings_controller::get_type_index() const {
    return type_combo_->currentIndex();
}
size_t settings_controller::get_rods_count() const {
    return rods_count_spin_->value();
}