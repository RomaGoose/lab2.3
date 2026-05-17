#include "main_controller.hpp"
#include "game_controller.hpp"
#include "hanoi_widget.hpp"
#include "mainwindow.hpp"
#include "sequence_stack.hpp"
#include "settings_controller.hpp"
#include <memory>
#include <qobject.h>

main_controller::main_controller(QObject* parent) 
    : main_window_(new MainWindow())
    , hanoi_widget_(new HanoiWidget(main_window_)) 
    , settings_(main_window_->get_type_combo(), main_window_->get_rods_count_cpin()){

    main_window_->add_hanoi_widget(hanoi_widget_);
    hanoi_widget_->draw_rods();

    setup_game(settings_.get_type_index());

    connect(
        &settings_,
        &settings_controller::container_type_changed,
        this,
        &main_controller::on_container_type_changed
    );
};

void main_controller::on_container_type_changed(int index) {
    setup_game(index);
};

void main_controller::setup_game(int type){
    switch (type) {
    case 0:
        game_ = std::make_unique<game_controller<list_stack>>(hanoi_widget_, settings_.get_rods_count());
        break;
    case 1:
        game_ = std::make_unique<game_controller<array_stack>>(hanoi_widget_, settings_.get_rods_count());
        break;
    }

    connect(
        &settings_, &settings_controller::disk_count_changed,
        game_.get(), &game_controller_base::on_disks_changed
    );
}
void main_controller::show() {
    main_window_->show();
}



