#include "main_controller.hpp"
#include "game_controller.hpp"
#include "game_controller_base.hpp"
#include "hanoi_widget.hpp"
#include "mainwindow.hpp"
#include "sequence_stack.hpp"
#include "settings_controller.hpp"
#include <memory>
#include <qobject.h>

main_controller::main_controller(QObject* parent) 
    : main_window_(new MainWindow())
    , hanoi_widget_(new HanoiWidget(main_window_)) 
    , settings_(this) {

    setup_ui();
    setup_connections();
};

void main_controller::setup_ui() {
    main_window_->add_hanoi_widget(hanoi_widget_);
    setup_game(settings_.get_type_index());
    main_window_->add_settings_widget(settings_.get_settings_widget());
};
void main_controller::setup_connections() {
    connect(
        &settings_,
        &settings_controller::container_type_changed,
        this,
        &main_controller::on_container_type_changed
    );
    connect(
        &settings_,
        &settings_controller::reset,
        this,
        &main_controller::on_reset
    );
    connect(
        &settings_,
        &settings_controller::solve,
        this,
        &main_controller::on_solve
    );
    connect(
        &settings_,
        &settings_controller::change_speed,
        this,
        &main_controller::on_speed_changed
    );
    connect(
        game_.get(),
        &game_controller_base::error_message,
        this, 
        &main_controller::on_error_message
    );
};

void main_controller::on_speed_changed(int value) {
    game_->set_speed(value);
};

void main_controller::on_error_message(const QString& msg){
    main_window_->show_message(msg);
}

void main_controller::on_container_type_changed(int index) {
    setup_game(index);
};

void main_controller::on_reset() {
    setup_game(settings_.get_type_index());
}

void main_controller::on_solve() {
    setup_game(settings_.get_type_index());
    game_->solve();
}

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

    game_->set_speed(settings_.get_speed());
}
void main_controller::show() {
    main_window_->show();
}



