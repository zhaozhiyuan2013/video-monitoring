#include <QtWidgets>
#include <QCamera>
#include <QCameraViewfinder>
#include <QCameraImageCapture>
#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    z264 = new H264( );
    z264->start();
    productor_video = new productor();
    productor_video->start();

//        fggg  = new live555();
//    fggg.start();


   // videosurface = new QVideoSurfaceFormat;
  //  videosurface->setFrameRate(5);
//    qDebug()<<"videosurface->setFrameRate(25);  " <<ok ;
   // camera=new QCamera(this);
   // connect( this, SIGNAL( ok() ), z264, SLOT( okk() ) );
   // camera = new QCamera(0);//1

//        QByteArray cameraDevice;

//        QActionGroup *videoDevicesGroup = new QActionGroup(this);
//        videoDevicesGroup->setExclusive(true);
//        foreach(const QByteArray &deviceName, QCamera::availableDevices()) {
//            QString description = camera->deviceDescription(deviceName);
//            QAction *videoDeviceAction = new QAction(description, videoDevicesGroup);
//            videoDeviceAction->setCheckable(true);
//            videoDeviceAction->setData(QVariant(deviceName));
//            cameraDevice = deviceName;
//            break;
//        }

//        delete camera;
//        camera = new QCamera(cameraDevice,this);//1
 //   viewfinder=new QCameraViewfinder(this);
   // imageCapture=new QCameraImageCapture(camera);
// qDebug()<<"captureDestination"<<imageCapture->captureDestination();
// //   ui->horizontalLayout_View->addWidget(viewfinder);
//   QImage::Format zhao =   QVideoFrame::imageFormatFromPixelFormat(QVideoFrame::Format_YUV420P );
//    qDebug()<< "QImage::Format"<<( QImage::Format)zhao;

   ui->label_Display->setScaledContents(true);
//     qDebug()<<" mode "<<camera->captureMode();
//   // camera->setCaptureMode(QCamera::CaptureVideo);
//     qDebug()<<" mode "<<camera->captureMode();
//     qDebug()<<"CaptureViewfinder "<<camera->isCaptureModeSupported(QCamera::CaptureViewfinder);
//     qDebug()<<"CaptureStillImage "<<camera->isCaptureModeSupported(QCamera::CaptureStillImage);
//     qDebug()<<"CaptureVideo "<<camera->isCaptureModeSupported(QCamera::CaptureVideo);
    //recorder = new QMediaRecorder(camera);
    //  QAbstractVideoSurface  xx;
  //  recorder->set
  // camera->set
    // QUrl zzzzzz("d:/zzzzzzzzz.avi");
  //  recorder->setOutputLocation(zzzzzz);
//    zz = new  absurface();
 //   qDebug()<<"zz->isFormatSupported(*videosurface);  "<< zz->isFormatSupported(*videosurface);

 //   zz->start(*videosurface);
  //    qDebug()<<"zz->isFormatSupported(*videosurface);  "<< zz->isFormatSupported(*videosurface);
    // connect( zz, SIGNAL( sent(const QVideoFrame &) ), z264, SLOT( set_frame( const QVideoFrame &) ) );
//ui->label_Display->setPixmap();
//    if (! zz->isFormatSupported(QVideoSurfaceFormat(QSize(320, 240),  QVideoFrame::Format_YUV420P))) {
//         qWarning() << "1111111surface doesn't support camera format :QVideoFrame::Format_YUV420PQVideoFrame::Format_YUV420P, cant start";
//    }else {
//         qDebug()<<"support";
//    }
     //camera->setNotifyInterval(10);
    // aaa = new ab();

//   camera->setViewfinder(aaa);
   // control = camera->service()->requestControl<QVideoRendererControl *>();
//    if (control) { control->setSurface(zz);
//     qDebug()<<" if (control) { control->setSurface(zz); if (control) { control->setSurface(zz); if (control) { control->setSurface(zz); if (control) { control->setSurface(zz);";
//    } else {
//         qDebug()<<" camera->setViewfinder(zz); camera->setViewfinder(zz); camera->setViewfinder(zz); camera->setViewfinder(zz);";
//    }
//    camera->moveToThread();
//    camera->start();

  //  recorder->record();
//     qDebug()<<" mode "<<camera->captureMode();
//     qDebug()<<"CaptureViewfinder "<<camera->isCaptureModeSupported(QCamera::CaptureViewfinder);
//     qDebug()<<"CaptureStillImage "<<camera->isCaptureModeSupported(QCamera::CaptureStillImage);
//     qDebug()<<"CaptureVideo "<<camera->isCaptureModeSupported(QCamera::CaptureVideo);

    //setBufferFormat
      // QCameraImageCapture::CaptureToBuffer
//    imageCapture->setCaptureDestination( QCameraImageCapture::CaptureToBuffer );
//     qDebug()<<"zhichi file "<< imageCapture->isCaptureDestinationSupported(QCameraImageCapture::CaptureToFile);
//     qDebug()<<"zhichi buffer "<< imageCapture->isCaptureDestinationSupported(QCameraImageCapture::CaptureToBuffer);
//     qDebug()<<"captureDestination"<<imageCapture->captureDestination();
//    QList<QVideoFrame::PixelFormat> zzz =  imageCapture->supportedBufferFormats();
//     qDebug()<<zzz.size();
//    imageCapture->setBufferFormat(QVideoFrame::Format_YUV420P);
//    connect(imageCapture, SIGNAL(imageCaptured(int,QImage)), this, SLOT(displayImage(int,QImage)));

//    connect(ui->pushButton_Capture, SIGNAL(clicked()), this, SLOT(captureImage()));
//    connect(ui->pushButton_Save, SIGNAL(clicked()), this, SLOT(saveImage()));
  //  connect(ui->pushButton_Quit, SIGNAL(clicked()), qApp, SLOT(quit()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::captureImage()
{emit ok();
    //recorder->stop();
//     qDebug()<<	imageCapture->bufferFormat();
//    ui->statusBar->showMessage(tr("正在捕获图片"), 1000);
//    imageCapture->capture();
}

void MainWindow::displayImage(int /*id*/, QImage image)
{
    emit ok();

//    ui->label_Display->setPixmap(QPixmap::fromImage(image));
//    ui->statusBar->showMessage(tr("捕获成功"), 5000);
}

void MainWindow::saveImage()
{emit ok();
//     qDebug() << "/home/xavier/teste" ;
//   recorder->setOutputLocation(QUrl("d:/zzzzzzzzz.avi"));
//     recorder->record();
//    QString fileName=QFileDialog::getSaveFileName(this, tr("keep"), QDir::homePath(), tr("jpeg格式文件(*.jpg)"));
//    if(fileName.isEmpty()) {
//        ui->statusBar->showMessage(tr("cancel"), 5000);
//        return;
//    }
//    const QPixmap* pixmap=ui->label_Display->pixmap();
//    if(pixmap) {
//        pixmap->save(fileName);
//        ui->statusBar->showMessage(tr("保存成功"), 5000);
//    }
}
