#ifndef PRODUCTOR_H
#define PRODUCTOR_H

#include <QThread>
#include <QCamera>
#include <QCameraViewfinder>
#include <QCameraImageCapture>
#include "absurface.h"
  #include <qactiongroup.h>
#include<QAction>
class productor : public QThread
{
    Q_OBJECT
public:
    explicit productor(QObject *parent = 0);
     QCamera *camera;
     absurface *zz;
    void run();
signals:

public slots:
    void capture_sleep();

};

#endif // PRODUCTOR_H
