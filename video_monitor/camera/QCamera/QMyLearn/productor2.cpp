#include "productor2.h"
#include <QTime>
productor2::productor2(QObject *parent) :
    QThread(parent)
{
    zz = new  absurface(  );
    camera = new QCamera(0);//1
        QByteArray cameraDevice;

        QActionGroup *videoDevicesGroup = new QActionGroup(this);
        videoDevicesGroup->setExclusive(true);
        foreach(const QByteArray &deviceName, QCamera::availableDevices()) {
            QString description = camera->deviceDescription(deviceName);
            QAction *videoDeviceAction = new QAction(description, videoDevicesGroup);
            videoDeviceAction->setCheckable(true);
            videoDeviceAction->setData(QVariant(deviceName));
            cameraDevice = deviceName;
            break;
        }

     delete camera;
     camera = new QCamera(cameraDevice,this);//1
    // camera->setCaptureMode( QCamera::CaptureStillImage);
     camera->setViewfinder(zz);


     QCamera::CaptureModes capture_mode = QCamera::CaptureStillImage; // Only support this mode

     if ( camera->isCaptureModeSupported( capture_mode ) ) {
          qDebug()<<"support camera ";
         camera->setCaptureMode( capture_mode );
     }
     camera->start();
     connect(zz , SIGNAL(capture_sleep()) ,SLOT( capture_sleep() ));
//      qDebug()<<"p::capture_sleep(){"<<camera->ActiveState;
//      qDebug()<<"p::capture_sleep(){"<<camera->error();
//      qDebug()<<"p::capture_sleep(){"<<camera->isAvailable();
//      qDebug()<<"p::capture_sleep(){"<<camera->isWidgetType();
//       qDebug()<<"p::capture_sleep(){"<<camera->state();
//        qDebug()<<"p::capture_sleep(){  camera->status() "<<camera->status();
//      qDebug()<<"p::capture_sleep(){"<<camera->availableMetaData();
// qDebug()<<"productor::capture_sleep(){productor::capture_sleep(){productor::capture_sleep(){";
}

void productor2::capture_sleep(){
    // qDebug()<<"productor::capture_sleep(){productor::capture_sleep(){productor::capture_sleep(){";
  //  QThread::msleep(150);
}
void productor2::run(){
    static int a =0 ;
    a++;

 //    qDebug()<<"void productor::run(){  ";
    while(1){
   //      qDebug()<<"p::capture_sleep(){"<<camera->isAvailable();
    //   camera->start();
//         qDebug()<<QTime::currentTime();
//          qDebug()<<"  count a == "  <<a;
//          qDebug()<<camera->status();
//         qDebug()<<"void productor::run(){  ";
       //   qDebug()<<"void productor::run(){  ";
    }
}
