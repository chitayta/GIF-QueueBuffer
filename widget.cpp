#include "widget.h"
#include "gifdisplayer.h"
#include <QVBoxLayout>
#include <QGridLayout>
#include <QDebug>
#include <QFileInfo>
#include <QDir>
#include <QFileInfoList>
#include <QMovie>
#include <QLabel>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
//    GIFDisplayer* gifItemDislayer4;
//    gifItemDislayer4 = new GIFDisplayer("E:/VNG/Qt Project/GIF3/gif/tct.gif");
//    gifItemDislayer4->setCursor(Qt::PointingHandCursor);
//    GIFDisplayer* gifItemDislayer2 = new GIFDisplayer("E:/VNG/Qt Project/GIF3/gif/tct2.gif");
//    GIFDisplayer* gifItemDislayer3 = new GIFDisplayer("E:/VNG/Qt Project/GIF3/gif/keke.gif");
//    mainLayout = new QVBoxLayout;
//    mainLayout->addWidget(gifItemDislayer4, 0, Qt::AlignCenter);
//    mainLayout->addWidget(gifItemDislayer2, 0, Qt::AlignCenter);
//    mainLayout->addWidget(gifItemDislayer3, 0, Qt::AlignCenter);
//    setLayout(mainLayout);


//    mainGridLayout = new QGridLayout();
//    dir.setPath("E:/VNG/Qt Project/GIF3/gif");
//    fileInfoList = new QFileInfoList(dir.entryInfoList (QStringList()<<"*.gif"));
//    gifItemDislayer = new GIFDisplayer*[fileInfoList->count()];
//    qDebug() << fileInfoList->count();
//    for (int index = 0; index < fileInfoList->count(); index++)
//    {
//        gifItemDislayer[index] = new GIFDisplayer(fileInfoList->at(index).absoluteFilePath(), QSize(300,200));

//    }
//    int count = 1;
//    for (int r = 0; r < 10; r++)
//    {
//        for (int c = 0; c < 5; c++)
//        {
//            if (count <= fileInfoList->count())
//                mainGridLayout->addWidget(&(*gifItemDislayer[5*r+c]), r, c);
//            else break;
//            count++;
//        }
//        if (count > fileInfoList->count())
//            break;
//    }
//    setLayout(mainGridLayout);

/*
    QMovie* movie = new QMovie("E:/VNG/Qt Project/GIF3/gif/smile.gif");
    movie->start();
    QLabel* imageLabel = new QLabel;
    imageLabel->setMovie(movie);

    mainLayout = new QVBoxLayout;
    mainLayout->addWidget(imageLabel, 0, Qt::AlignCenter);
    setLayout(mainLayout);

    */
    GIFDisplayer* dis = new GIFDisplayer("E:/VNG/Qt Project/GIF8/gif/giphy.gif", QSize(400, 300));

    mainLayout = new QVBoxLayout;
    mainLayout->addWidget(dis, 0, Qt::AlignCenter);
    setLayout(mainLayout);
}

Widget::~Widget()
{

}
