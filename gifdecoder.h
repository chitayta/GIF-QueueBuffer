//---------------------------------------------------------
//  Name:       Chi Tay Ta
//  File:       gifdecoder.h
//  Project:    Qt-File-Explorer
//  Purpose:    Header file of class GIFDecoder.
//              Read frame image from gif file.
//---------------------------------------------------------

#ifndef GIFDECODER_H
#define GIFDECODER_H

#include <QObject>
#include <QThread>
#include <QImageReader>
#include <QImage>
#include <QPixmap>
#include <QMap>
#include <QTimer>
#include <QQueue>

#define MINIMUM_FRAME_BUFFER        1
#define NUMBER_FRAME_BUFFER         2
#define DEFAULT_SCALED_WIDTH        300
#define DEFAULT_SCALED_HEIGHT       200

class GIFDisplayer;
class QElapsedTimer;
class FrameInfo
{
public:
    QImage         imageItem;
    quint64        timeDelay;
    FrameInfo(QImage image, quint64 time): imageItem(image), timeDelay(time){}
    FrameInfo(){}
};

class GIFDecoder : public QObject
{
    Q_OBJECT

    QString             fileName;
    GIFDisplayer*       displayer;
    QImageReader        reader;
    QSize               frameSize;
    quint64             imageCountValue;
    quint64             firstFrameReadTime;
    QElapsedTimer*      timer;
    FrameInfo           frameInfo;
public:
    QPixmap             firstFramePixmap;
    quint64             frameNumber;
    QQueue<FrameInfo>   itemBuffer;

    GIFDecoder(GIFDisplayer* displayer, QString fileName, QSize size);
    quint64 imageCount();
    void resetDecoder();

public slots:
    void onTimerDelayTimeOut();
};

#endif // GIFDECODER_H
