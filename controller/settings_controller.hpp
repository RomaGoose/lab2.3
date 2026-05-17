#pragma once

#include <cstddef>
#include <qcombobox.h>
#include <qspinbox.h>
class settings_controller{
    QComboBox* type_combo_;
    QSpinBox* rods_count_spin_;
public: 
    settings_controller(QComboBox* type_combo, QSpinBox* rods_count_spin);

    size_t get_type_index() const;
    size_t get_rods_count() const;
};