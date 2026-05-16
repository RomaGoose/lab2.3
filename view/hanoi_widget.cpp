#include "hanoi_widget.hpp"
#include <cstddef>
#include <qgraphicsscene.h>
#include <qnamespace.h>
#include <qpen.h>
#include <qwidget.h>

HanoiWidget::HanoiWidget(QWidget* parent) 
    : QGraphicsView(parent)
    , scene_(new QGraphicsScene(this))
{
    scene_->setSceneRect(0, 0, scene_width_, scene_height_);
    setScene(scene_);

    // setMinimumSize(900, 500);
    // setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
}

void HanoiWidget::draw_rods(){
    constexpr size_t distance = scene_width_ / 3;
    constexpr size_t x_first = distance / 2;

    for (size_t i = 0; i < rods_count; ++i) {
        size_t curr_x = x_first + i * distance;
        draw_rod(curr_x, scene_height_ * 0.8, scene_height_ * 0.6);
        draw_base(curr_x - distance * 0.4, scene_height_ * 0.8, distance * 0.8, 8);
    };
};

void HanoiWidget::draw_rod(size_t x, size_t y, size_t height){
    scene_->addLine(x, y, x, y - height, QPen(Qt::white, 8));
};

void HanoiWidget::draw_base(size_t x, size_t y, size_t width, size_t heigt) {
    scene_->addLine(x, y, x + width, y, QPen(Qt::white, heigt));
    // scene_->addRect(x, y, width, heigt, );
};
