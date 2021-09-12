#include "nailcapture.h"

NailCapture::NailCapture(QWidget *parent) : QMainWindow(parent)
{

}

void NailCapture::cutNailScreen(QPixmap pixmap)
{

    m_nailImage=new MyLabel();

    if(!pixmap.toImage().isNull()){
        qDebug()<<"所截的图不是空的!!";
        qDebug()<<"宽："<<pixmap.width()<<"高："<<pixmap.height();
    }

    m_nailImage->setimagetolabel(pixmap);
    m_nailImage->setFixedSize(pixmap.width(),pixmap.height());

    //钉在桌面
    m_nailImage->show();

    //发送信号 告知qml钉图结束
    emit finishCapture();
}

void NailCapture::startNailCapture()
{
    qDebug()<<"开始钉图";
    m_capture = new RecCapture();
    connect(m_capture,SIGNAL(signalCompleteCapture(QPixmap)),
            this,SLOT(cutNailScreen(QPixmap)));
    m_capture->show();
}
