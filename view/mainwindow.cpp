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

void MainWindow::add_hanoi_widget(HanoiWidget* widget) {
    ui->central_hl->layout()->addWidget(widget);
};

void MainWindow::add_settings_widget(QWidget* widget) {
    ui->central_hl->layout()->addWidget(widget);
};
