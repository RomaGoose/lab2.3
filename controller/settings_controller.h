#pragma once

#include <qcombobox.h>
#include <qspinbox.h>
class settings_controller{
    QComboBox* type_combo_;
    QSpinBox* rods_count_spin_;
public: 
    settings_controller(QComboBox* type_combo, QSpinBox* rods_count_spin);
};