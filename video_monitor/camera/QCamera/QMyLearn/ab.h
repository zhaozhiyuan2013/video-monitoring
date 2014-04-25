#ifndef AB_H
#define AB_H

#include <QAbstractVideoSurface>

class ab : public QAbstractVideoSurface
{
public:

    ab(QObject * parent=NULL) : QAbstractVideoSurface(parent)
       {

    }

    virtual bool present(const QVideoFrame & frame);
    virtual QList<QVideoFrame::PixelFormat>	supportedPixelFormats(QAbstractVideoBuffer::HandleType type = QAbstractVideoBuffer::NoHandle) const {
        return QList<QVideoFrame::PixelFormat>() << QVideoFrame::Format_RGB24;
   }

};

#endif // AB_H
