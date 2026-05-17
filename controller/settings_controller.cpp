#include "settings_controller.hpp"
#include <qboxlayout.h>
#include <qcombobox.h>
#include <qlabel.h>
#include <qlayoutitem.h>
#include <qobject.h>
#include <qpushbutton.h>
#include <qspinbox.h>
#include <qwidget.h>

settings_controller::settings_controller(QObject* parent) 
    : QObject(parent) {

    settings_widget_ = new QWidget();
    layout_ = new QVBoxLayout(settings_widget_);

    type_combo_ = new QComboBox();
    type_combo_->addItems({
        "List sequence", 
        "Array sequence"
    });

    rods_count_spin_ = new QSpinBox();
    rods_count_spin_->setRange(3, 10);


    QHBoxLayout* hbox_buttons = new QHBoxLayout();
    
    reset_btn_ = new QPushButton();
    reset_btn_->setText("Сбросить");

    solve_btn_ = new QPushButton();
    solve_btn_->setText("Решить");

    hbox_buttons->addWidget(reset_btn_);
    hbox_buttons->addWidget(solve_btn_);


    layout_->addWidget(new QLabel("Тип адаптируемой последовательности:"));
    layout_->addWidget(type_combo_);
    layout_->addWidget(new QLabel("Количество дисков:"));
    layout_->addWidget(rods_count_spin_);
    layout_->addStretch();
    layout_->addLayout(hbox_buttons);

    connect(
        type_combo_, 
        &QComboBox::currentIndexChanged, 
        this, 
        &settings_controller::on_combo_changed
    );
    connect(
        rods_count_spin_, 
        &QSpinBox::valueChanged, 
        this, 
        &settings_controller::on_spin_changed
    );
    connect(
        reset_btn_,
        &QPushButton::pressed,
        this,
        &settings_controller::on_reset_btn_pressed
    );
    connect(
        solve_btn_,
        &QPushButton::pressed,
        this,
        &settings_controller::on_solve_btn_pressed
    );
};

QWidget* settings_controller::get_settings_widget() const {
    return settings_widget_;
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
void settings_controller::on_reset_btn_pressed(){
    emit reset();
}
void settings_controller::on_solve_btn_pressed(){
    emit solve();
}