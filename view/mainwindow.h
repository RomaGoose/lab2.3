#pragma once

#include "hanoi_widget.h"
#include <QMainWindow>
#include <qcombobox.h>
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
    
    QComboBox* get_type_combo();
    QSpinBox* get_rods_count_cpin();
private:
    Ui::MainWindow* ui;
    HanoiWidget* hanoi_widget;

};