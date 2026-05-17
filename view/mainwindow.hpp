#pragma once

#include "hanoi_widget.hpp"
#include <QMainWindow>
#include <qcombobox.h>
#include <qobject.h>
#include <qpushbutton.h>
#include <qspinbox.h>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow{

    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

    void add_hanoi_widget(HanoiWidget* widget);
    void add_settings_widget(QWidget* widget);
    
    QComboBox* get_type_combo();
    QSpinBox* get_rods_count_cpin();

    QPushButton* get_reset_btn();
    QPushButton* get_solve_btn();

    void show_message(const QString& message);
private:
    Ui::MainWindow* ui;
    HanoiWidget* hanoi_widget;

};