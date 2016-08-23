#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QDir>

class GIFDisplayer;
class QVBoxLayout;
class QGridLayout;
class Widget : public QWidget
{
    Q_OBJECT

    GIFDisplayer** gifItemDislayer;
    QVBoxLayout* mainLayout;
    QGridLayout* mainGridLayout;
    QDir dir;
    QFileInfoList* fileInfoList;
public:
    Widget(QWidget *parent = 0);
    ~Widget();

};

#endif // WIDGET_H
