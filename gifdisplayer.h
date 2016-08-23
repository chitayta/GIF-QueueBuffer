//---------------------------------------------------------
//  Name:       Chi Tay Ta
//  File:       gifdisplayer.h
//  Project:    Qt-File-Explorer
//  Purpose:    Header file of class GIFDisplayer.
//              Widget to display gif image.
//---------------------------------------------------------

#ifndef GIFDISPLAYER_H
#define GIFDISPLAYER_H

#include <QWidget>
#include "gifdecoder.h"
#include <QString>
#include <QQueue>
#include <QMap>
#include <QEvent>
#include <QPainter>
#include <QThread>

class QTimer;
class QLabel;
class GIFDecoder;
class QVBoxLayout;
class QElapsedTimer;
enum State{
    Start,
    Stop,
};
class GIFDisplayer : public QWidget
{
    Q_OBJECT

    QThread decodeThread;

    QVBoxLayout*    mainLayout;
    GIFDecoder*     decoder;
    QSize           size;
    QLabel*         image;
    QString         fileName;
    quint64         nextTimeDelay;
    QPixmap         firstFramePixmap;
    QPixmap         currentPixmap;
    QTimer*         timerDelay;
    quint64         currentFrameNumber;
    quint64         time;
    FrameInfo       item;
    State           gifState;
public:
    explicit GIFDisplayer(QString fileName, QSize size = QSize(), QWidget *parent = 0);
    explicit GIFDisplayer(QWidget *parent = 0);
    ~GIFDisplayer();
    void start();
    void stop();

protected:
    void enterEvent(QEvent*);
    void leaveEvent(QEvent*);

signals:
    void finishedDisplay(quint64);
public slots:
    void play();
    void replyTimeOut();
};

#endif // GIFDISPLAYER_H
