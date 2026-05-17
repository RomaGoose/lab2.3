#pragma once

#include <cstddef>
#include <qboxlayout.h>
#include <qcombobox.h>
#include <qobject.h>
#include <qpushbutton.h>
#include <qslider.h>
#include <qspinbox.h>
#include <qwidget.h>
class settings_controller : public QObject {

    Q_OBJECT

    QWidget* settings_widget_;
    QVBoxLayout* layout_;


    QComboBox* type_combo_;
    QSpinBox* rods_count_spin_;

    QSlider* speed_slider;
    static constexpr int initial_speed = 25;

    QPushButton* reset_btn_;
    QPushButton* solve_btn_;


public: 
    settings_controller(QObject* parent = nullptr);

    size_t get_type_index() const;
    size_t get_rods_count() const;
    int get_speed() const;

    QWidget* get_settings_widget() const;

private:
    void setup_ui();
    void setup_connections();

signals:
    void disk_count_changed(int new_count);
    void container_type_changed(int new_type_index);
    void reset();
    void solve();
    void change_speed(int value);

private slots:
    void on_combo_changed(int index);
    void on_spin_changed(int value);
    void on_reset_btn_pressed();
    void on_solve_btn_pressed();
    void on_speed_changed(int value);
};