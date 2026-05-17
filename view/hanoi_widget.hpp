#pragma once

#include "array_sequence.hpp"
#include <cstddef>
#include <cstdint>
#include <qgraphicsscene.h>
#include <qgraphicsview.h>
#include <qtmetamacros.h>

class HanoiWidget : public QGraphicsView {

    Q_OBJECT

public:
    explicit HanoiWidget(QWidget *parent = nullptr);

    void draw_rods();
    void draw_disks(array_sequence<array_sequence<uint8_t>> rods, size_t total_disk_count);
    // void draw_disks();
    // void reset();
    
private:
    QGraphicsScene* scene_;
    
    static constexpr size_t rods_count = 3;
    static constexpr size_t scene_width_ = 900;
    static constexpr size_t scene_height_ = 500;

    static constexpr size_t distance = scene_width_ / rods_count;
    static constexpr size_t x_first = distance / 2;
    //TODO: base_y?

    static constexpr size_t rod_base_width = distance * 0.8;
    static constexpr size_t max_disk_size = rod_base_width * 0.9;
    static constexpr size_t min_disk_size = rod_base_width * 0.2;
    static constexpr size_t base_y = scene_height_ * 0.8;
    static constexpr size_t rod_height = scene_height_ * 0.6;
    static constexpr size_t rod_width = 8;

    void draw_rod(size_t x, size_t y, size_t heigt);
    void draw_base(size_t x, size_t y, size_t width, size_t heigt);
};