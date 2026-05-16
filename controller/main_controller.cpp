#include "main_controller.h"
#include "hanoi_widget.h"
#include "mainwindow.h"
#include "settings_controller.h"
#include <qobject.h>

main_controller::main_controller(QObject* parent) 
    : main_window_(new MainWindow())
    , hanoi_widget_(new HanoiWidget(main_window_)) 
    , settings_(main_window_->get_type_combo(), main_window_->get_rods_count_cpin()){

    main_window_->add_hanoi_widget(hanoi_widget_);
};

void main_controller::show() {
    main_window_->show();
}



