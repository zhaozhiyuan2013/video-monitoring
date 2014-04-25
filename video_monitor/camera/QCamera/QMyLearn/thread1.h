#ifndef THREAD1_H
#define THREAD1_H

#include <QThread>

class thread1 : public QThread
{
    Q_OBJECT
public:
    explicit thread1(QObject *parent = 0);
    void run();
signals:

public slots:

};

#endif // THREAD1_H
