#ifndef LONGCAPTURE_H
#define LONGCAPTURE_H

#include <QWidget>

class QLabel;

class LongCapture : public QWidget
{
    Q_OBJECT
public:
    explicit LongCapture(QWidget *parent = nullptr);
    ~LongCapture();
protected:
    void wheelEvent(QWheelEvent *event);
private:
    void keyPressEvent(QKeyEvent *event);
    void combinePix();
    void shotScreen();
private:
    QLabel *label;
    QTimer *timer;
    QVector<QPixmap> *m_pixmaps;
};

#endif // LONGCAPTURE_H
