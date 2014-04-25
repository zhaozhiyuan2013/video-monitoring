#ifndef ABSURFACE_H
#define ABSURFACE_H
#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <QAbstractVideoSurface>
#include <QTime>
#include <QDebug>
#include <QVideoFrame>
#include <QVideoSurfaceFormat>

 extern void* v_video_frame[]  ;


class absurface : public QAbstractVideoSurface
{
    Q_OBJECT
public:
  //  absurface( );
    absurface(QObject * parent=NULL) : QAbstractVideoSurface(parent)
       {
    for ( int i =0 ; i< 20; i++) {
      v_video_frame[ i ] = malloc ( 640*480*3);
    }
    b_get =true;
    }
bool	start(const QVideoSurfaceFormat & format);
int a;
FILE *f_out;
void make_h264_file();
// QVideoFrame cloneFrame;
 bool b_get;

 virtual bool present(const QVideoFrame & frame);
 virtual QList<QVideoFrame::PixelFormat>	supportedPixelFormats(QAbstractVideoBuffer::HandleType type = QAbstractVideoBuffer::NoHandle) const {
     //qDebug()<<"  supportedPixelFormats(QAbstractVi  ";
     return QList<QVideoFrame::PixelFormat>() << QVideoFrame::Format_RGB24;
}

 QTimer *mp_worktimer;
signals :
 void sent(const QVideoFrame &);
 void capture_sleep();
public slots:
    void time_end();
};

#endif // ABSURFACE_H
