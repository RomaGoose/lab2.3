#pragma once

#include <qobject.h>

class game_controller_base  : public QObject {

    Q_OBJECT

public: 
    virtual ~game_controller_base();

public slots:
    virtual void on_disks_changed(int new_disk_count) = 0;
};
