#pragma once

#include <cstddef>
#include <qgraphicsscene.h>
#include <qgraphicsview.h>
#include <qtmetamacros.h>
class HanoiWidget : public QGraphicsView {

    Q_OBJECT

public:
    explicit HanoiWidget(QWidget *parent = nullptr);

    void draw_rods();
    // void draw_disks();
    // void reset();

private:
    QGraphicsScene* scene_;
    size_t scene_width_ = 900;
    size_t scene_height_ = 500;
};