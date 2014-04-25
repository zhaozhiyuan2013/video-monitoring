#include "absurface.h"
#include <QVideoSurfaceFormat>
//absurface::absurface()
//{
//}
#include <QTimer>
#include <QVideoFrame>
#include <QDateTime>
extern "C"
{
#include <math.h>
#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>
#include <libswscale/swscale.h>
#include <libavutil/opt.h>
#include <libavutil/channel_layout.h>
#include <libavutil/common.h>
#include <libavutil/imgutils.h>
#include <libavutil/mathematics.h>
#include <libavutil/samplefmt.h>
#include <libavutil/opt.h>
#include <libavcodec/avcodec.h>
#include <libavutil/channel_layout.h>
#include <libavutil/common.h>
#include <libavutil/imgutils.h>
#include <libavutil/mathematics.h>
#include <libavutil/samplefmt.h>
};
#include <QThread>
#include <QMutex>
#include <QWaitCondition>
#include <QVideoFrame>
#pragma comment(lib,"avutil.lib")
#pragma comment(lib,"avcodec.lib")
#pragma comment(lib,"avformat.lib")
#pragma comment(lib,"swscale.lib")

#define INBUF_SIZE 4096
#define AUDIO_INBUF_SIZE 20480
#define AUDIO_REFILL_THRESH 4096
#include <QDebug>
QMutex mutex;
void* v_video_frame[ 20 ]  ;
int write_point = 0;
int read_point = 0;
void * p_video_frame = malloc ( 640*480*3);
bool video_frame = false ;
QWaitCondition bufferNotFull;

bool absurface::present ( const QVideoFrame & frame ) {
  //   qDebug()<<"  absurface::present ( const QVideoFrame & frame ) {  ";
 // QVideoSurfaceFormat aa = surfaceFormat();

//   qDebug()<<"aa.frameRate();aa.frameRate();aa.frameRate();aa.frameRate();aa.frameRate();  "<<aa.frameRate();
//   qDebug()<<"aa.frameRate();aa.frameRate();aa.frameRate();aa.frameRate();aa.frameRate();  "<<aa.frameSize();
//   qDebug()<<isActive();

  //static    AVFrame *m_pRGBFrame =  new AVFrame[1];  //RGB帧数据
//  static     AVFrame *m_pYUVFrame = new AVFrame[1];  //YUV帧数据
//  static  AVCodec *codec;
//  static   AVCodecContext *c= NULL;
//  static   AVPacket avpkt, pkt;
//     qDebug()<<"frame"<<frame.pixelFormat();
    static int a = 0;
//     qDebug()<<"frameframeframeframeframeframeframeframeframeframe   start time " <<frame.startTime();
//      qDebug()<<"frameframeframeframeframeframeframeframeframeframe   end time " <<frame.endTime();
//    if( a > 1 && cloneFrame == frame  ) {
//        static int bbb = 1;
//         qDebug()<<"absurface::present(const QVideoFrame & frame){  frame  same "<<  bbb ;
//        bbb++;
//    }
    if (frame.isValid() ) {
    //    emit capture_sleep();
     //    qDebug()<<"absurface write_point"<<write_point;
    //     qDebug()<<"absurface read_point"<<read_point;
        if ( ( ( read_point < write_point )&& (   write_point - read_point >= 16 )) || ( ( read_point > write_point )&& ( read_point - write_point <= 4 )) ){
//                  mutex.lock();
//                  bufferNotFull.wait(&mutex);
//                  mutex.unlock();
        }
        video_frame = true;
         QVideoFrame  cloneFrame ( frame );
            cloneFrame.map(QAbstractVideoBuffer::ReadOnly);
         //   if ( write_point < 8 || ( write_point ==9  && read_point >0 ) || ( read_point > write_point + 1 ) ) {
                if( ( write_point + 1 ) % 20 != read_point  ) {

                memcpy( (void *)v_video_frame[ write_point ] , cloneFrame.bits(), 640*480*3 );
                write_point = ( write_point + 1 ) % 20;
            }
                cloneFrame.unmap();
    //     qDebug()<<" bool absurface::present(const QVideoFrame & frame){ valid frame    count      " <<a;
//        static QTime aaaaaa ;
//        if ( a == 3 )  {
//            aaaaaa = QTime::currentTime();
//         }

    //      qDebug()<< "begig   "<<aaaaaa;
     //            qDebug()<<QTime::currentTime();

                QThread::msleep(150);
                if (  b_get ==true )
                a+=1;
                return true;
             }

             return true;
  }
static void pgm_save(unsigned char *buf, int wrap, int xsize, int ysize,
                     FILE*f)
{
    int i;
 //buf += 64;
    //fprintf(f,"P5n%d %dn%dn",xsize,ysize,255);
    for(i=0;i<ysize;i++)
        fwrite(buf + i * wrap,1,xsize,f);
}
bool	absurface::start(const QVideoSurfaceFormat & format){
    static int a =1;
    a ++;
     //qDebug()<<"start" <<a;
     //qDebug()<<"(const QVideoSurfaceFormat & format){ "<< format.frameRate();
      QAbstractVideoSurface::start( format );
        return true;
}
//QList<QVideoFrame::PixelFormat>	absurface::supportedPixelFormats(
//        QAbstractVideoBuffer::HandleType type) const {

//     qDebug()<<"type"<<type;
//   QList<QVideoFrame::PixelFormat>	 a;
//    return QList<QVideoFrame::PixelFormat>() << QVideoFrame::Format_RGB24<<QVideoFrame::Format_YUV420P;
//   //    return QList<QVideoFrame::PixelFormat>() <<QVideoFrame::Format_YUV420P;
//}
void  absurface::make_h264_file(){

}
    void absurface::time_end(){
//         qDebug()<<"end";
//         qDebug()<<QTime::currentTime();
//         qDebug()<<QDateTime::currentDateTime();
//     //   b_get=false;

//        if (a > 2) return ;
//        static int a = 0 ;
//  a ++;
//        QString file = "d:/cap-image/";
//      //  if(a ==1 )
//         qDebug()<<" void absurface::time_end(){    emit sent( cloneFrame ); count "<<a;
//        emit sent( cloneFrame );
//        cloneFrame.map(QAbstractVideoBuffer::ReadOnly);
//        const QImage img(cloneFrame.bits(),
//                     cloneFrame.width(),
//                     cloneFrame.height(),
//                     QVideoFrame::imageFormatFromPixelFormat(cloneFrame.pixelFormat()));
//       // file += QString(a);
//        file+="xxx.jpg";
//        if(a < 20 )
//        img.save(file);
//        b_get =false;
//        static    AVFrame *m_pRGBFrame =  new AVFrame[1];  //RGB帧数据
//          static     AVFrame *m_pYUVFrame = new AVFrame[1];  //YUV帧数据
//          static  AVCodec *codec;
//          static   AVCodecContext *c= NULL;
//          static   AVPacket avpkt, pkt;
//         //    qDebug()<<"frame"<<frame.pixelFormat();
//        //    if (frame.isValid()&& b_get =true ) {
//                //        cloneFrame(frame);
//                         qDebug()<<"cloneFrame"<<cloneFrame.pixelFormat();
//                          qDebug()<<"imageFormatFromPixelFormat"<< QVideoFrame::imageFormatFromPixelFormat(cloneFrame.pixelFormat());

//                        qDebug()<<cloneFrame.width();
//                         qDebug()<<cloneFrame.height();
//                       int size = cloneFrame.width() * cloneFrame.height();
//                        uint8_t * yuv_buff;//
//               //        SwsContext * scxt = sws_getContext(cloneFrame.width(),cloneFrame.height(),AV_PIX_FMT_RGB24,cloneFrame.width(),cloneFrame.height(),AV_PIX_FMT_YUV420P,SWS_POINT,NULL,NULL,NULL);
//                       SwsContext * scxt = sws_getContext(cloneFrame.width(),cloneFrame.height(),AV_PIX_FMT_RGB24,cloneFrame.width(),cloneFrame.height(),AV_PIX_FMT_YUV420P,SWS_BICUBIC,NULL,NULL,NULL);
//                       yuv_buff = (uint8_t *) malloc((size * 3) / 2); // size for YUV 420
//                      int ppp =   avpicture_fill((AVPicture*)m_pRGBFrame, (uint8_t*)cloneFrame.bits(), AV_PIX_FMT_RGB24, cloneFrame.width(), cloneFrame.height());
//          qDebug()<<"ppp"<<ppp;
//        //               // 翻转RGB图像
//        //                    m_pRGBFrame->data[0]  += m_pRGBFrame->linesize[0] * (cloneFrame.height() - 1);
//        //                    m_pRGBFrame->linesize[0] *= -1;
//        //                    m_pRGBFrame->data[1]  += m_pRGBFrame->linesize[1] * (cloneFrame.height() / 2 - 1);
//        //                    m_pRGBFrame->linesize[1] *= -1;
//        //                    m_pRGBFrame->data[2]  += m_pRGBFrame->linesize[2] * (cloneFrame.height() / 2 - 1);
//        //                    m_pRGBFrame->linesize[2] *= -1;

//                       //将YUV buffer 填充YUV Frame
//                     int pp =   avpicture_fill((AVPicture*)m_pYUVFrame, (uint8_t*)yuv_buff, AV_PIX_FMT_YUV420P, cloneFrame.width(), cloneFrame.height());
//                     qDebug()<<"pp"<<pp;
//               int heig =  sws_scale(scxt,m_pRGBFrame->data,m_pRGBFrame->linesize,0, cloneFrame.height(),m_pYUVFrame->data,m_pYUVFrame->linesize);
//             qDebug()<<"he"<<heig;
//            if (a ==1 ) {
//                f_out = fopen("d:/xxx.yuv", "wb+");  //接着是打开文件
//                if (!f_out)
//                {
//                    fprintf(stderr, "could not open %s\n", "xx");
//                    exit(1);
//                     fclose(f_out);
//                }

//                 qDebug()<<"cloneFrame.size();"<<cloneFrame.size();
//         int w_count =  fwrite(m_pYUVFrame->data[0], 1,(640*480) , f_out);
//         fwrite(m_pYUVFrame->data[1], 1,(640*480)/4 , f_out);
//         fwrite(m_pYUVFrame->data[2], 1,(640*480)/4 , f_out);
//             qDebug()<<"write in xx.yuv size "<< w_count;


//            }

//               //               pgm_save(m_pYUVFrame->data[0], m_pYUVFrame->linesize[0],
//        //                        cloneFrame.width(),  cloneFrame.height(), f_out);
//        //               pgm_save(m_pYUVFrame->data[1], m_pYUVFrame->linesize[1],
//        //                       cloneFrame.width()/2,  cloneFrame.height(), f_out);
//        //               pgm_save(m_pYUVFrame->data[2], m_pYUVFrame->linesize[2],
//        //                        cloneFrame.width()/2,  cloneFrame.height(), f_out);
//                        qDebug()<<"width" <<  m_pYUVFrame->width;
//                          qDebug()<<"height"<< m_pYUVFrame->height;
//                           qDebug()<<"pkt_size"<< m_pYUVFrame->pkt_size;
//                            qDebug()<<"format"<< m_pYUVFrame->format;
//                   //    int size_count = fwrite( m_pYUVFrame->data, 1, (size * 3) / 2, f_out);


//                       delete yuv_buff;



//                       if (a ==1 ) {

//                            av_register_all();
//                           codec = avcodec_find_encoder(CODEC_ID_H264);  //函数用于查找一个与codec ID相匹配的已注册的编码器。
//                           if (!codec)
//                           {
//                               fprintf(stderr, "codec not found\n");
//                               exit(1);
//                           }
//                       //zhao 头文件 3577行
//                           c = avcodec_alloc_context3( codec ); //函数用于分配一个AVCodecContext并设置默认值，如果失败返回NULL，并可用av_free()进行释放。


//                           /* put sample parameters */
//                           c->bit_rate = 300000;  //设置采样参数，即比特率
//                           /* resolution must be a multiple of two */// 设置分辨率，必须是2的倍数
//                           c->width = 640;
//                           c->height = 480;
//                           /* frames per second *///设置帧率//该帧率为25，其实timebase = 1/framerate,分别为分子和分母。
//                           c->time_base.den = 25;
//                           c->time_base.num = 1;
//                          // c->time_base = (AVRational){1,25};
//                           c->gop_size = 10; /* emit one intra frame every ten frames *///设置GOP大小,该值表示每10帧会插入一个I帧（intra frame）。
//                           c->max_b_frames=1;//设置B帧最大数,　c->max_b_frames = 1; 该值表示在两个非B帧之间，所允许插入的B帧的最大帧数。
//                        //   c->pix_fmt = PIX_FMT_YUV420P;  //设置像素格式,该值将像素格式设置为YUV420P。
//                            c->pix_fmt = AV_PIX_FMT_YUV420P;  //设置像素格式,该值将像素格式设置为YUV420P。
//                            if ( avcodec_open2(c, codec, NULL) < 0 )

//                           // if (avcodec_open(c, codec) < 0)  //函数用给定的AVCodec来初始化AVCodecContext
//                            {
//                                fprintf(stderr, "could not open codec\n");
//                                exit(1);
//                            }
//                       }
//                 av_init_packet(&pkt);
//                     pkt.data = NULL;    // packet data will be allocated by the encoder
//                     pkt.size = 0;

//                             int   got_packet_ptr;
//                              qDebug()<<"c"<<c->height;
//                              qDebug()<<"c"<< c->time_base.den;
//                              qDebug()<<"c"<< c->bit_rate;
//                              qDebug()<<"c"<<c->gop_size;
//                              qDebug()<<"c"<<c->max_b_frames;
//                              qDebug()<<"c"<<c->pix_fmt;
//        int   u_size= -1;
//         //        u_size = avcodec_encode_video2(c, &pkt, m_pYUVFrame, &got_packet_ptr);
//                                     if (u_size == 0&& a <= 20)
//                                     {
//                                          qDebug()<<"success"<<a;
//                                          qDebug()<<" pkt.size"<< pkt.size;
//                                //         if( pkt.size>0)
//                               //       fwrite(pkt.data, 1, pkt.size, f_out);
//                                     }
//                       if (a == 20) {

//                       }


//                      // do something with the image ...
//         qDebug()<<"// do something with the ";
//                       cloneFrame.unmap();
//                    //   return true;
//             //      }

//        b_get =true;
//       // present();

    }

//     qDebug()<<"get new video frame;";

//     qDebug()<<"QVideoFrame::imageFormatFromPixelFormat"<<  QVideoFrame::imageFormatFromPixelFormat(cloneFrame.pixelFormat());
//   if ( a == 1 ) {
//    mp_worktimer = new QTimer(this);
//    connect( mp_worktimer, SIGNAL( timeout() ), this, SLOT( time_end() ) );
//    mp_worktimer->start(1000);
//}
  //  b_get =false;
//                 qDebug()<<"cloneFrame"<<cloneFrame.pixelFormat();
//                  qDebug()<<"imageFormatFromPixelFormat"<< QVideoFrame::imageFormatFromPixelFormat(cloneFrame.pixelFormat());
       //        cloneFrame.map(QAbstractVideoBuffer::ReadOnly);
            //   memcpy(p_video_frame, cloneFrame.bits(), 640*480*3 );

//                qDebug()<<"cloneFrame.bits()"<<sizeof(cloneFrame.bits());
//            //    qDebug()<<"cloneFrame.bits()"<<5636strlen(cloneFrame.bits());
//               const QImage img(cloneFrame.bits(),
//                            cloneFrame.width(),
//                            cloneFrame.height(),
//                            QVideoFrame::imageFormatFromPixelFormat(cloneFrame.pixelFormat()));
//         //       qDebug()<<cloneFrame.width();
//         //        qDebug()<<cloneFrame.height(); SWS_BILINEAR
//               int size = cloneFrame.width() * cloneFrame.height();
//                uint8_t * yuv_buff;//
//       //        SwsContext * scxt = sws_getContext(cloneFrame.width(),cloneFrame.height(),AV_PIX_FMT_RGB24,cloneFrame.width(),cloneFrame.height(),AV_PIX_FMT_YUV420P,SWS_POINT,NULL,NULL,NULL);
//               SwsContext * scxt = sws_getContext(cloneFrame.width(),cloneFrame.height(),AV_PIX_FMT_RGB24,cloneFrame.width(),cloneFrame.height(),AV_PIX_FMT_YUV420P,SWS_BICUBIC,NULL,NULL,NULL);
//               yuv_buff = (uint8_t *) malloc((size * 3) / 2); // size for YUV 420
//              int ppp =   avpicture_fill((AVPicture*)m_pRGBFrame, (uint8_t*)cloneFrame.bits(), AV_PIX_FMT_RGB24, cloneFrame.width(), cloneFrame.height());
//  qDebug()<<"ppp"<<ppp;
// //               // 翻转RGB图像
// //                    m_pRGBFrame->data[0]  += m_pRGBFrame->linesize[0] * (cloneFrame.height() - 1);
// //                    m_pRGBFrame->linesize[0] *= -1;
// //                    m_pRGBFrame->data[1]  += m_pRGBFrame->linesize[1] * (cloneFrame.height() / 2 - 1);
// //                    m_pRGBFrame->linesize[1] *= -1;
// //                    m_pRGBFrame->data[2]  += m_pRGBFrame->linesize[2] * (cloneFrame.height() / 2 - 1);
// //                    m_pRGBFrame->linesize[2] *= -1;

//               //将YUV buffer 填充YUV Frame
//             int pp =   avpicture_fill((AVPicture*)m_pYUVFrame, (uint8_t*)yuv_buff, AV_PIX_FMT_YUV420P, cloneFrame.width(), cloneFrame.height());
//             qDebug()<<"pp"<<pp;
//       int heig =        sws_scale(scxt,m_pRGBFrame->data,m_pRGBFrame->linesize,0, cloneFrame.height(),m_pYUVFrame->data,m_pYUVFrame->linesize);
//     qDebug()<<"he"<<heig;
//       //               pgm_save(m_pYUVFrame->data[0], m_pYUVFrame->linesize[0],
// //                        cloneFrame.width(),  cloneFrame.height(), f_out);
// //               pgm_save(m_pYUVFrame->data[1], m_pYUVFrame->linesize[1],
// //                       cloneFrame.width()/2,  cloneFrame.height(), f_out);
// //               pgm_save(m_pYUVFrame->data[2], m_pYUVFrame->linesize[2],
// //                        cloneFrame.width()/2,  cloneFrame.height(), f_out);
//                qDebug()<<"width" <<  m_pYUVFrame->width;
//                  qDebug()<<"height"<< m_pYUVFrame->height;
//                   qDebug()<<"pkt_size"<< m_pYUVFrame->pkt_size;
//                    qDebug()<<"format"<< m_pYUVFrame->format;
//           //    int size_count = fwrite( m_pYUVFrame->data, 1, (size * 3) / 2, f_out);


//               delete yuv_buff;
//                     static int a = 0 ;
//               a ++;


//               if (a ==1 ) {
//                   f_out = fopen("d:/xx.264", "wb+");  //接着是打开文件
//                   if (!f_out)
//                   {
//                       fprintf(stderr, "could not open %s\n", "xx");
//                       exit(1);
//                   }
//                    av_register_all();
//                   codec = avcodec_find_encoder(CODEC_ID_H264);  //函数用于查找一个与codec ID相匹配的已注册的编码器。
//                   if (!codec)
//                   {
//                       fprintf(stderr, "codec not found\n");
//                       exit(1);
//                   }
//               //zhao 头文件 3577行
//                   c = avcodec_alloc_context3( codec ); //函数用于分配一个AVCodecContext并设置默认值，如果失败返回NULL，并可用av_free()进行释放。


//                   /* put sample parameters */
//                   c->bit_rate = 300000;  //设置采样参数，即比特率
//                   /* resolution must be a multiple of two */// 设置分辨率，必须是2的倍数
//                   c->width = 640;
//                   c->height = 480;
//                   /* frames per second *///设置帧率//该帧率为25，其实timebase = 1/framerate,分别为分子和分母。
//                   c->time_base.den = 25;
//                   c->time_base.num = 1;
//                  // c->time_base = (AVRational){1,25};
//                   c->gop_size = 10; /* emit one intra frame every ten frames *///设置GOP大小,该值表示每10帧会插入一个I帧（intra frame）。
//                   c->max_b_frames=1;//设置B帧最大数,　c->max_b_frames = 1; 该值表示在两个非B帧之间，所允许插入的B帧的最大帧数。
//                //   c->pix_fmt = PIX_FMT_YUV420P;  //设置像素格式,该值将像素格式设置为YUV420P。
//                    c->pix_fmt = AV_PIX_FMT_YUV420P;  //设置像素格式,该值将像素格式设置为YUV420P。
//                    if ( avcodec_open2(c, codec, NULL) < 0 )

//                   // if (avcodec_open(c, codec) < 0)  //函数用给定的AVCodec来初始化AVCodecContext
//                    {
//                        fprintf(stderr, "could not open codec\n");
//                        exit(1);
//                    }
//               }
//         av_init_packet(&pkt);
//             pkt.data = NULL;    // packet data will be allocated by the encoder
//             pkt.size = 0;

//                     int   got_packet_ptr;
//                      qDebug()<<"c"<<c->height;
//                      qDebug()<<"c"<< c->time_base.den;
//                      qDebug()<<"c"<< c->bit_rate;
//                      qDebug()<<"c"<<c->gop_size;
//                      qDebug()<<"c"<<c->max_b_frames;
//                      qDebug()<<"c"<<c->pix_fmt;
//int   u_size= -1;
//         u_size = avcodec_encode_video2(c, &pkt, m_pYUVFrame, &got_packet_ptr);
//                             if (u_size == 0&& a <= 20)
//                             {
//                                  qDebug()<<"success"<<a;
//                                  qDebug()<<" pkt.size"<< pkt.size;
//                                 if( pkt.size>0)
//                              fwrite(pkt.data, 1, pkt.size, f_out);
//                             }
//               if (a == 20) {
//                   fclose(f_out);
//               }




//               QString file = "d:/cap-image/";
//             //  if(a ==1 )

//               file += QString::number(a);
//               file+=".jpg";
//              // if(a < 20 )
//            //  img.save(file);
//              // do something with the image ...
// qDebug()<<"// do something with the ";
//          //  cloneFrame.unmap();
//                qDebug()<<QTime::currentTime();
//              return true;
//           }

//           return true;
//}
/**
 * Allocate and return an SwsContext. You need it to perform
 * scaling/conversion operations using sws_scale().
 *
 * @param srcW the width of the source image
 * @param srcH the height of the source image
 * @param srcFormat the source image format
 * @param dstW the width of the destination image
 * @param dstH the height of the destination image
 * @param dstFormat the destination image format
 * @param flags specify which algorithm and options to use for rescaling
 * @return a pointer to an allocated context, or NULL in case of error
 * @note this function is to be removed after a saner alternative is
 *       written
 * @deprecated Use sws_getCachedContext() instead.

struct SwsContext *sws_getContext(int srcW, int srcH, enum AVPixelFormat srcFormat,
                                  int dstW, int dstH, enum AVPixelFormat dstFormat,
                                  int flags, SwsFilter *srcFilter,
                                  SwsFilter *dstFilter, const double *param);
#endif
*/
/**
 * Scale the image slice in srcSlice and put the resulting scaled
 * slice in the image in dst. A slice is a sequence of consecutive
 * rows in an image.
 *
 * Slices have to be provided in sequential order, either in
 * top-bottom or bottom-top order. If slices are provided in
 * non-sequential order the behavior of the function is undefined.
 *
 * @param c         the scaling context previously created with
 *                  sws_getContext()
 * @param srcSlice  the array containing the pointers to the planes of
 *                  the source slice
 * @param srcStride the array containing the strides for each plane of
 *                  the source image
 * @param srcSliceY the position in the source image of the slice to
 *                  process, that is the number (counted starting from
 *                  zero) in the image of the first row of the slice
 * @param srcSliceH the height of the source slice, that is the number
 *                  of rows in the slice
 * @param dst       the array containing the pointers to the planes of
 *                  the destination image
 * @param dstStride the array containing the strides for each plane of
 *                  the destination image
 * @return          the height of the output slice
 */
//int sws_scale(struct SwsContext *c, const uint8_t *const srcSlice[],
//              const int srcStride[], int srcSliceY, int srcSliceH,
//              uint8_t *const dst[], const int dstStride[]);
void video_encode_example(const char * inputfilename , const char *outputfilename)  //编码
{
    AVCodec *codec;
    AVCodecContext *c= NULL;
    int out_size, size, outbuf_size,got_packet,x,y;
    FILE *f_out,*f_in;
    AVFrame *picture;
    uint8_t *outbuf, *picture_buf;
    AVPacket avpkt, pkt;
    int framee = 0;
    int insize = 0;
    //av_init_packet(&pkt);
    printf("Video encoding\n");
  //  pkt.data = NULL, pkt.size = 0;
    /* find the mpeg1 video encoder */
    codec = avcodec_find_encoder(CODEC_ID_H264);  //函数用于查找一个与codec ID相匹配的已注册的编码器。
    if (!codec)
    {
        fprintf(stderr, "codec not found\n");
        exit(1);
    }
//zhao 头文件 3577行
    c = avcodec_alloc_context3( codec ); //函数用于分配一个AVCodecContext并设置默认值，如果失败返回NULL，并可用av_free()进行释放。


    /* put sample parameters */
    c->bit_rate = 300000;  //设置采样参数，即比特率
    /* resolution must be a multiple of two */// 设置分辨率，必须是2的倍数
    c->width = 352;
    c->height = 288;
    /* frames per second *///设置帧率//该帧率为25，其实timebase = 1/framerate,分别为分子和分母。
    c->time_base.den = 25;
    c->time_base.num = 1;
   // c->time_base = (AVRational){1,25};
    c->gop_size = 10; /* emit one intra frame every ten frames *///设置GOP大小,该值表示每10帧会插入一个I帧（intra frame）。
    c->max_b_frames=1;//设置B帧最大数,　c->max_b_frames = 1; 该值表示在两个非B帧之间，所允许插入的B帧的最大帧数。
 //   c->pix_fmt = PIX_FMT_YUV420P;  //设置像素格式,该值将像素格式设置为YUV420P。
     c->pix_fmt = AV_PIX_FMT_YUV420P;  //设置像素格式,该值将像素格式设置为YUV420P。
    //av_opt_set(c->priv_data, "preset", "slow", 0);
    /* open it */
     AVDictionary **opts;
     av_opt_set(c->priv_data, "preset", "slow", 0);
    if ( avcodec_open2(c, codec, NULL) < 0 )

   // if (avcodec_open(c, codec) < 0)  //函数用给定的AVCodec来初始化AVCodecContext
    {
        fprintf(stderr, "could not open codec\n");
        exit(1);
    }

    picture= av_frame_alloc(); //函数用于分配一个AVFrame并设置默认值，如果失败返回NULL，并可用av_free()进行释放。
    /* the codec gives us the frame size, in samples */
    f_out = fopen(outputfilename, "wb+");  //接着是打开文件
    if (!f_out)
    {
        fprintf(stderr, "could not open %s\n", outputfilename);
        exit(1);
    }
    f_in = fopen(inputfilename,"rb+");
    if (!f_in)
    {
        fprintf(stderr, "could not open %s\n", inputfilename);
        exit(1);
    }

    /* alloc image and output buffer */
    outbuf_size = 100000;   //分配图像和输出缓存
    outbuf = (uint8_t *) malloc(outbuf_size);
    size = c->width * c->height;
    picture_buf = ( uint8_t *)malloc((size * 3) / 2 ); /* size for YUV 420 */

    picture->data[0] = picture_buf;
    picture->data[1] = picture->data[0] + size;
    picture->data[2] = picture->data[1] + size / 4;
 //   picture->linesize[0] = c->width;
 //   picture->linesize[1] = c->width / 2;  sws_getContext
 //   picture->linesize[2] = c->width / 2;
//av_new_packet(&pkt, 100000);

    picture->format = c->pix_fmt;
        picture->width  = c->width;
        picture->height = c->height;

        /* the image can be allocated by any means and av_image_alloc() is
         * just the most convenient way if av_malloc() is to be used */
     int   ret = av_image_alloc(picture->data, picture->linesize, c->width, c->height,
                             c->pix_fmt, 10);
    for (;;)
    {
        if (size == 0)
        {
            break;
        }
        av_init_packet(&pkt);
                pkt.data = NULL;    // packet data will be allocated by the encoder
                pkt.size = 0;
        size = fread(picture_buf,sizeof(char),c->width * c->height * 3/2,f_in);  //获取y,u,v偏移量
        picture->data[0] = picture_buf;
        picture->data[1] = picture->data[0] + c->width * c->height;
        picture->data[2] = picture->data[1] + c->width * c->height / 4;
        //4378 line
        //out_size = avcodec_encode_video(c, outbuf, outbuf_size, picture); //从picture中编码一帧视频数据，并存入到outbuf中，而期间所使用的编码器为c。
       // out_size = avcodec_encode_video(c, outbuf, outbuf_size, picture);
              //  for (y = 0; y < c->height; y++) {
              //              for (x = 0; x < c->width; x++) {
              //                  picture->data[0][y * picture->linesize[0] + x] = x + y + framee * 3;
             //               }
             //           }
                        /* Cb and Cr */
              //          for (y = 0; y < c->height/2; y++) {
             //               for (x = 0; x < c->width/2; x++) {
             //                   picture->data[1][y * picture->linesize[1] + x] = 128 + y + framee * 2;
//                                picture->data[2][y * picture->linesize[2] + x] = 64 + x + framee * 5;
//                            }
//                        }
                        picture->pts = framee;
        out_size = avcodec_encode_video2(c, &pkt, picture, &got_packet);
                   //write(fd, pkt.data, pkt.size);
                 //  av_init_packet(&pkt);
       // av_free_packet(&pkt);
       // av_init_packet(&pkt);
      //  pkt.data = NULL, pkt.size = 0;
//av_grow_packet(&pkt, 50);

        printf("encoding frame %3d (size=%5d)\n",framee,  pkt.size);
       //  qDebug()<<out_size;
       int size_count = fwrite(pkt.data, 1, pkt.size, f_out);
        //qDebug() << "size_count"<<size_count;
        //将编码完的数据写入到文件里
     //   memset(pkt.data, 0, pkt.size);
        framee ++;
    }
     //qDebug()<<got_packet<<"got_packet";
    free(picture_buf);
    free(outbuf);
    avcodec_close(c);
    av_free(c);
    av_free(picture);
    printf("\n");
}
