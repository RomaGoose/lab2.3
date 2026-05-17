#include "settings_controller.hpp"
#include <qcombobox.h>

settings_controller::settings_controller(QComboBox* type_combo, QSpinBox* rods_count_spin) 
    : type_combo_(type_combo)
    , rods_count_spin_(rods_count_spin) {

    connect(type_combo_, &QComboBox::currentIndexChanged, this, &settings_controller::on_combo_changed);
    connect(rods_count_spin_, &QSpinBox::valueChanged, this, &settings_controller::on_spin_changed);
};


size_t settings_controller::get_type_index() const {
    return type_combo_->currentIndex();
}
size_t settings_controller::get_rods_count() const {
    return rods_count_spin_->value();
}

void settings_controller::on_combo_changed(int index) {
    emit container_type_changed(index);
}

void settings_controller::on_spin_changed(int value){
    emit disk_count_changed(value);
}