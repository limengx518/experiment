#ifndef NAILCAPTURE_H
#define NAILCAPTURE_H

#include <QMainWindow>
#include <QObject>
#include "reccapture.h"
#include "mylabel.h"

class NailCapture : public QMainWindow
{
    Q_OBJECT
public:
    explicit NailCapture(QWidget *parent = nullptr);

signals:
    void finishCapture();

public slots:
    void startNailCapture();
    void cutNailScreen(QPixmap pixmap);

private:
    MyLabel *m_nailImage;
    RecCapture *m_capture;

};

#endif // NAILCAPTURE_H
