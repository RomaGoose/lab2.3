#pragma once

#include "game_controller.h"
#include "hanoi_widget.h"
#include "mainwindow.h"
#include "settings_controller.h"
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
};