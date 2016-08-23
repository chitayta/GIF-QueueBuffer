//---------------------------------------------------------
//  Name:       Chi Tay Ta
//  File:       gifdisplayer.cpp
//  Project:    Qt-File-Explorer
//  Purpose:    Implementation of class GIFDisplayer.
//---------------------------------------------------------



#include "gifdisplayer.h"
#include <QDebug>
#include <QImage>
#include <QTimer>
#include <QLabel>
#include <QVBoxLayout>
#include <QStyle>
#include <QEvent>
#include <QElapsedTimer>


GIFDisplayer::GIFDisplayer(QString fileName, QSize size ,QWidget *parent) : QWidget(parent), fileName(fileName), size(size)
{
    decoder = new GIFDecoder(this, fileName, size);
    decoder->moveToThread(&decodeThread);
    decodeThread.start();

    firstFramePixmap = QPixmap(decoder->firstFramePixmap);
    image = new QLabel;
    image->setPixmap(firstFramePixmap);
    mainLayout = new QVBoxLayout;
    mainLayout->addWidget(image);
    mainLayout->setMargin(0);
    setLayout(mainLayout);

    timerDelay = new QTimer;
    QObject::connect(timerDelay, SIGNAL(timeout()), this, SLOT(replyTimeOut()));
    QObject::connect(timerDelay, SIGNAL(timeout()), decoder, SLOT(onTimerDelayTimeOut()));
    gifState = Start;
}

GIFDisplayer::GIFDisplayer(QWidget *parent): QWidget(parent)
{

}

void GIFDisplayer::play()
{
    //gifState = Start;
}

void GIFDisplayer::start()
{
    decoder->resetDecoder();
    currentFrameNumber = 0;
    nextTimeDelay = 100;
    currentFrameNumber = currentFrameNumber + 1;
    timerDelay->start(nextTimeDelay);
}

void GIFDisplayer::stop()
{
    timerDelay->stop();
    image->setPixmap(firstFramePixmap);
}

void GIFDisplayer::replyTimeOut()
{
    while(decoder->itemBuffer.count() <= MINIMUM_FRAME_BUFFER);
    item = decoder->itemBuffer.dequeue();
    timerDelay->start(item.timeDelay);
    currentPixmap = QPixmap(QPixmap::fromImage(item.imageItem));
    image->setPixmap(currentPixmap);
    nextTimeDelay = item.timeDelay;
    currentFrameNumber = currentFrameNumber + 1;
    if (currentFrameNumber == decoder->imageCount())
    {
        currentFrameNumber = 0;
    }

}

void GIFDisplayer::enterEvent(QEvent*)
{
    if (gifState == Start)
        this->start();
}

void GIFDisplayer::leaveEvent(QEvent*)
{
    if (gifState == Start)
        this->stop();
}

GIFDisplayer::~GIFDisplayer()
{
}
