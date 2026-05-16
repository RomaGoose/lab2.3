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
    
    static constexpr size_t rods_count = 3;
    static constexpr size_t scene_width_ = 900;
    static constexpr size_t scene_height_ = 500;


    void draw_rod(size_t x, size_t y, size_t heigt);
    void draw_base(size_t x, size_t y, size_t width, size_t heigt);
};