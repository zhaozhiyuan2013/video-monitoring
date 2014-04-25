#include "mainwindow.h"
#include <QApplication>
#include "productor2.h"

#include "live555.h"
#include "thread1.h"
int main(int argc, char *argv[])
{
   QApplication a(argc, argv);
//   MainWindow w;
//    w.productor_video->start();

//    w.z264->start();

   productor2  productor_video;
   productor_video.start();
    H264 z264;
    z264.start();
    live555    fggg;
    fggg.start();
        qDebug()<<" begin            -----";

//    w.show();
  //  H264 *z264;
//     productor2  *productor_video;
// //    z264 = new H264( );
// //    z264->start();
//    productor_video = new productor2();
//    productor_video->start();

//    z264.wait();
//    productor_video.wait();
  //  QObject::connect( &w, SIGNAL( ok() ), &z264, SLOT( okk() ) );

//    productor_video.wait();
//    z264.wait();
//     w.z264->wait();
//    w.productor_video->wait();
//   fggg.wait();
    return a.exec();
}
