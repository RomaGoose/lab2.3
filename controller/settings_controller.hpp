#pragma once

#include <cstddef>
#include <qcombobox.h>
#include <qpushbutton.h>
#include <qspinbox.h>
class settings_controller : public QObject {

    Q_OBJECT

    QComboBox* type_combo_;
    QSpinBox* rods_count_spin_;

    QPushButton* reset_btn_;
    QPushButton* solve_btn_;

public: 
    settings_controller(QComboBox* type_combo, QSpinBox* rods_count_spin, QPushButton* reset_btn, QPushButton* solve_btn);

    size_t get_type_index() const;
    size_t get_rods_count() const;

signals:
    void disk_count_changed(int new_count);
    void container_type_changed(int new_type_index);
    void reset();
    void solve();
    
private slots:
    void on_combo_changed(int index);
    void on_spin_changed(int value);
    void on_reset_btn_pressed();
    void on_solve_btn_pressed();
};