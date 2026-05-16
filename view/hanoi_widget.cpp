#include "hanoi_widget.h"
#include <qgraphicsscene.h>
#include <qwidget.h>

HanoiWidget::HanoiWidget(QWidget* parent) 
    : QGraphicsView(parent)
    , scene_(new QGraphicsScene(this))
{
    scene_->setSceneRect(0, 0, scene_width_, scene_height_);
    setScene(scene_);
}