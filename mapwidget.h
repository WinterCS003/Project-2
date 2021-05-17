#ifndef MAPWIDGET_H
#define MAPWIDGET_H

#include <QStackedWidget>

class mapwidget : public QStackedWidget
{
public:
    explicit mapwidget(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;
signals:

private:
    QImage usMapOutline;
};

#endif // MAPWIDGET_H
