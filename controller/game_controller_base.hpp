#pragma once

#include <qobject.h>

class game_controller_base  : public QObject {

    Q_OBJECT

public: 
    game_controller_base(QObject* parent = nullptr);
    virtual ~game_controller_base();
    virtual void solve() = 0;

public slots:
    virtual void on_disks_changed(int new_disk_count) = 0;
    virtual void on_rod_clicked(int index) = 0;
    virtual void on_step() = 0;
};
