#include "hanoi_widget.hpp"
#include <cassert>
#include <cstddef>
#include <cstdlib>
#include <qbrush.h>
#include <qdebug.h>
#include <qgraphicsscene.h>
#include <qnamespace.h>
#include <qpen.h>
#include <qrgb.h>
#include <qwidget.h>

HanoiWidget::HanoiWidget(QWidget* parent) 
    : QGraphicsView(parent)
    , scene_(new QGraphicsScene(this))
{
    scene_->setSceneRect(0, 0, scene_width_, scene_height_);
    setScene(scene_);

    setMinimumSize(scene_width_ + frameWidth() * 2, scene_height_ + frameWidth() * 2);    
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}

void HanoiWidget::draw_rods(){
    for (size_t i = 0; i < rods_count; ++i) {
        size_t curr_x = x_first + i * distance;
        draw_rod(curr_x, base_y, rod_height);
        draw_base(curr_x - rod_base_width / 2, base_y, rod_base_width, rod_width);
    };
};

void HanoiWidget::draw_rod(size_t x, size_t y, size_t height){
    scene_->addLine(x, y, x, y - height, QPen(Qt::white, 8));
};

void HanoiWidget::draw_base(size_t x, size_t y, size_t width, size_t heigt) {
    scene_->addLine(x, y, x + width, y, QPen(Qt::white, heigt));
    // scene_->addRect(x, y, width, heigt, );
};

void HanoiWidget::draw_disks(array_sequence<list_sequence<uint8_t>> rods, size_t total_disk_count, int selected_rod) {

    size_t disk_width_increment = (max_disk_size - min_disk_size) / (total_disk_count - 1);
    size_t disk_height = (rod_height * 0.9) / total_disk_count;

    size_t rod_index = 0;
    size_t disk_index = 0;
    for(auto rod: rods){
        for(auto disk: rod){
            size_t disk_width = min_disk_size + disk * (disk_width_increment);
            size_t y_rod = (base_y - rod_width / 2) - (disk_index + 1) * disk_height;
            y_rod -= selected_rod == rod_index && disk_index == rod.size() - 1 ? rod_height * 0.2 : 0;

            scene_->addRect(
                x_first - disk_width / 2 + rod_index * distance, 
                y_rod, 
                disk_width, 
                disk_height,
                QPen(Qt::NoPen),
                QBrush(qRgb(255 - disk * 20, 0, 0)) //TODO: disk colors
            );
            ++disk_index;
        }
        disk_index = 0;
        ++rod_index;
    }
}

void HanoiWidget::clear_canvas(){
    scene_->clear();
}

int  HanoiWidget::rod_clicked_at(int x) {
    for (int i = 0; i < 3; ++i) {
        if (abs((int)(x - (x_first + i * distance))) < distance * 0.8) {
            return i;
        }
    }
    return -1;
};

void HanoiWidget::draw_selection(int index){
    scene_->addLine(
        x_first - (rod_base_width / 2) + (index * distance), 
        base_y + scene_height_ * 0.05, 
        x_first + (rod_base_width / 2) + (index * distance), 
        base_y + scene_height_ * 0.05,
        QPen(Qt::yellow, 4)
    );
};

