#include "mainwindow.hpp"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow){

    ui->setupUi(this);
}

MainWindow::~MainWindow(){
    delete ui;
}

QComboBox* MainWindow::get_type_combo() {
    return ui->cbx_seq_type;
};

QSpinBox* MainWindow::get_rods_count_cpin() {
    return ui->spn_disk_number;
};


QPushButton* MainWindow::get_reset_btn() {
    return ui->btn_reset;
};

QPushButton* MainWindow::get_solve_btn() {
    return ui->btn_solve;
};


void MainWindow::add_hanoi_widget(HanoiWidget* widget) {
    ui->central_hl->layout()->addWidget(widget);
};