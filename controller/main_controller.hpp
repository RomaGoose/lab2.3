#pragma once

#include "game_controller_base.hpp"
#include "hanoi_widget.hpp"
#include "mainwindow.hpp"
#include "settings_controller.hpp"
#include <memory>
#include <qobject.h>
#include <qtmetamacros.h>

class main_controller : public QObject {
    Q_OBJECT
private:
    MainWindow* main_window_;
    HanoiWidget* hanoi_widget_;

    std::unique_ptr<game_controller_base> game_;
    settings_controller settings_;

public:
    main_controller(QObject* parent = nullptr);

    void show();
private:
    void setup_game(int type);

    void setup_ui();
    void setup_connections();

public slots:
    void on_container_type_changed(int index);
    void on_reset();
    void on_solve();
    void on_speed_changed(int value);
    void on_error_message(const QString& message);
};