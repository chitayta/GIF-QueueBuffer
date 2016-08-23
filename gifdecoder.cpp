//---------------------------------------------------------
//  Name:       Chi Tay Ta
//  File:       gifdecoder.cpp
//  Project:    Qt-File-Explorer
//  Purpose:    Implementation of class GIFDecoder.
//---------------------------------------------------------

#include "gifdecoder.h"
#include "gifdisplayer.h"
#include <QDebug>
#include <QElapsedTimer>

GIFDecoder::GIFDecoder(GIFDisplayer* displayer, QString fileName, QSize size) : displayer(displayer), fileName(fileName), frameSize(size)
{
    timer = new QElapsedTimer;

    reader.setFileName(fileName);
    imageCountValue = reader.imageCount();
    if (frameSize.isValid())
    {
        reader.setScaledSize(QSize(frameSize.width(), frameSize.height()));
    }
    timer->start();
    firstFramePixmap = QPixmap(QPixmap::fromImage(reader.read()));
    firstFrameReadTime = timer->elapsed();
    qDebug() << "First Frame Read: " << firstFrameReadTime;
}

void GIFDecoder::resetDecoder()
{
    qDebug() << "reset: " << this->thread()->currentThreadId();
    frameNumber = 0;
    itemBuffer.clear();
    reader.setFileName(fileName);
    if (frameSize.isValid())
    {
        reader.setScaledSize(QSize(frameSize.width(), frameSize.height()));
    }
    firstFramePixmap = QPixmap(QPixmap::fromImage(reader.read()));
    for(int index = 0; index < 4; index++)
    {
        frameNumber = frameNumber + 1;
        itemBuffer.enqueue(FrameInfo(reader.read(), reader.nextImageDelay()));
    }
}

void GIFDecoder::onTimerDelayTimeOut()
{
    frameNumber = frameNumber + 1;
    if (frameNumber < imageCountValue)
    {
        itemBuffer.enqueue(FrameInfo(reader.read(), reader.nextImageDelay()));
    }
    else
    {
        reader.setFileName(fileName);
        frameNumber = 0;
        itemBuffer.enqueue(FrameInfo(reader.read(), reader.nextImageDelay()));
    }
}

quint64 GIFDecoder::imageCount()
{
    return this->imageCountValue;
}
