#include "longcapture.h"
#include <QApplication>
#include <QScreen>
#include <QClipboard>
#include <QDesktopWidget>
#include <QTimer>
#include <QDebug>
#include <QKeyEvent>
#include <QLabel>
#include <QPainter>
#include <QWheelEvent>

LongCapture::LongCapture(QWidget *parent)
    : QWidget(parent)
{
    Qt::WindowFlags m_flags = windowFlags();
    setWindowFlags(m_flags | Qt::WindowStaysOnTopHint);
    setWindowOpacity(1);
    label=new QLabel(this);
    label->setText(tr("截图中......"));
    label->setAlignment(Qt::AlignCenter);
    setSizeIncrement(label->size());
    m_pixmaps=new QVector<QPixmap>();
//    timer=new QTimer;
//    connect(timer,SIGNAL(timeout()),this,SLOT(shotScreen()));
//    timer->start(1000);
}

LongCapture::~LongCapture()
{
    if(!m_pixmaps->isEmpty()){
        m_pixmaps->clear();
    }
    delete m_pixmaps;
}

void LongCapture::wheelEvent(QWheelEvent *event)
{
    int longs=event->angleDelta().y();
    if(longs>0){
        qDebug()<<"1";
    }
}

void LongCapture::shotScreen()
{
    QPixmap pixmap;
    pixmap=QApplication::primaryScreen()->grabWindow(0);
    m_pixmaps->append(pixmap);
    QClipboard *clipboard=QApplication::clipboard();
    clipboard->setPixmap(pixmap);
}

void LongCapture::keyPressEvent(QKeyEvent *event)
{
    // Esc 键退出截图;
    if (event->key() == Qt::Key_Escape){
        //退出截图
        close();
    }

    // Eeter键完成矩形区域截图;
    if (event->key() == Qt::Key_Enter || event->key() == Qt::Key_Return)
    {
//        combinePix();

//        emit signalCompleteCapture(m_capturePixmap);

        close();
    }
}

void LongCapture::combinePix()
{
    if(m_pixmaps->size()==1){

    }
}
