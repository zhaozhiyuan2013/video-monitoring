#ifndef PRODUCTOR2_H
#define PRODUCTOR2_H

#include <QThread>
#include <QCamera>
#include <QCameraViewfinder>
#include <QCameraImageCapture>
#include "absurface.h"
  #include <qactiongroup.h>
#include<QAction>
class productor2 : public QThread
{
    Q_OBJECT
public:
    explicit productor2(QObject *parent = 0);
     QCamera *camera;
     absurface *zz;
     void run();
signals:

public slots:
    void capture_sleep();


};

#endif // PRODUCTOR2_H
