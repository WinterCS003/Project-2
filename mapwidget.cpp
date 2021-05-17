#include "mapwidget.h"

#include <QPainter>

mapwidget::mapwidget(QWidget *parent) : QWidget(parent)
{
    usMapOutline.load("usmap.png");
    usMapOutline = usMapOutline.scaled(781, 441);
}

void mapwidget::paintEvent(QPaintEvent *event)
{
    QPainter painter;
    QPoint point;

    painter.begin(this);
    painter.drawImage(point, usMapOutline);

    QWidget::paintEvent(event);
    painter.end();
}
