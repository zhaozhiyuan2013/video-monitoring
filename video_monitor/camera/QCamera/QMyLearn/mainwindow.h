#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QMediaRecorder>
#include <QWidget>
  #include <qcamera.h>
  #include <qmediaplayer.h>
  #include <qmediarecorder.h>
  #include <qvideowidget.h>
  #include <qcameraviewfinder.h>
  #include <qactiongroup.h>
#include "absurface.h"
#include "ab.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QUrl>
#include <QAbstractVideoSurface>
#include "productor.h"
#include "absurface.h"
#include <QVideoSurfaceFormat>
#include <QSize>
#include "h264.h"
#include "QVideoRendererControl"

namespace Ui {
class MainWindow;
}

class QCamera;
class QCameraViewfinder;
class QCameraImageCapture;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
  productor  *productor_video;
  H264 *z264;
private slots:
    void captureImage();
    void displayImage(int,QImage);
    void saveImage();
signals:
    void ok();
private:
    Ui::MainWindow *ui;

    QMediaRecorder *recorder;
    QCamera *camera;
    QCameraViewfinder *viewfinder;
    QCameraImageCapture *imageCapture;
    QVideoSurfaceFormat *videosurface;
    absurface *zz;


    ab *aaa;
   //live555    *fggg;

    QVideoRendererControl *control ;
};

#endif // MAINWINDOW_H
