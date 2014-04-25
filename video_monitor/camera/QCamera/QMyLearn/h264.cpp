#include "h264.h"
#include <QDebug>
#include <QImage>
#include <QTime>
#include <QWaitCondition>
#include <QSemaphore>
#include <QFile>
#include <QTextStream>
//#include "absurface.h"
extern void *p_video_frame;
extern bool video_frame;
extern int write_point;
extern int read_point ;
extern void* v_video_frame[]  ;
extern QMutex mutex;
extern QWaitCondition bufferNotFull;
extern bool begin_transport;
unsigned char * share_memory_555_264 = new unsigned char[10000000];
int share_read_point = 0;
int share_write_point = 0 ;
int share_junk_data = 0 ;
int share_write_end_point = -1 ;
QSemaphore usedBytes;
H264::H264( QObject *parent ) :
    QThread(parent)
{
// fBank[0] = new unsigned char[BANK_SIZE];

    f_out = fopen("d:/99999999.264", "wb+");  //接着是打开文件
    f_out_yuv = fopen("d:/99999999yuv.yuv", "wb+");
    if (!f_out)
    {
        fprintf(stderr, "could not open %s\n", "outputfilename");
        exit(1);
    }
 av_register_all();
 codec = avcodec_find_encoder(AV_CODEC_ID_H264);  // 函数用于查找一个与codec ID相匹配的已注册的编码器。
 if (!codec)
 {
     fprintf(stderr, "codec not found\n");
     exit(1);
 }
//zhao 头文件 3577行
 c = avcodec_alloc_context3( codec ); //函数用于分配一个AVCodecContext并设置默认值，如果失败返回NULL，并可用av_free()进行释放。


 /* put sample parameters */
// c->bit_rate = 640*480*3*8/2*5;  //设置采样参数，即比特率
  c->bit_rate = 640*480;  //设置采样参数，即比特率
 /* resolution must be a multiple of two */// 设置分辨率，必须是2的倍数
 c->width = 640;
 c->height = 480;
 /* frames per second *///设置帧率//该帧率为25，其实timebase = 1/framerate,分别为分子和分母。
 c->time_base.den = 5;
 c->time_base.num = 1;
// c->time_base = (AVRational){1,25};
 c->gop_size = 10; /* emit one intra frame every ten frames *///设置GOP大小,该值表示每10帧会插入一个I帧（intra frame）。
 c->max_b_frames=1;//设置B帧最大数,　c->max_b_frames = 1; 该值表示在两个非B帧之间，所允许插入的B帧的最大帧数。
//   c->pix_fmt = PIX_FMT_YUV420P;  //设置像素格式,该值将像素格式设置为YUV420P。
  c->pix_fmt = AV_PIX_FMT_YUV420P;  //设置像素格式,该值将像素格式设置为YUV420P。
  c->qblur = 0.5;
  c->qcompress = 0.5;
  c->b_quant_offset = 1.25;
  c->b_quant_factor = 1.25;
//  c->i_quant_offset = 0.0;
//  c->i_quant_factor = -0.8;
  av_opt_set(c->priv_data, "preset", "superfast", 0);
  av_opt_set(c->priv_data, "tune", "zerolatency", 0);
  if ( avcodec_open2(c, codec, NULL) < 0 )

 // if (avcodec_open(c, codec) < 0)  //函数用给定的AVCodec来初始化AVCodecContext
  {
      fprintf(stderr, "could not open codec\n");
      exit(1);
  }
}

 void H264::run(){
//     static    AVFrame *m_pRGBFrame =  new AVFrame[1];  //RGB帧数据
//     static     AVFrame *m_pYUVFrame = new AVFrame[1];  //YUV帧数据
//       uint8_t * yuv_buff;//
      //  yuv_buff = (uint8_t *) malloc((size * 3) / 2); // size for YUV 420
       // int pp =   avpicture_fill((AVPicture*)m_pYUVFrame, (uint8_t*)yuv_buff, AV_PIX_FMT_YUV420P, 640, 480);
  AVPacket pkt;
while ( 1 ) {
   // exec();
   //  qDebug()<<"   void H264::run(){ ";
     static int a = 0 ;
     a++;
   //  memset( yuv_buff , 0 , (size * 3) / 2 ) ;
//      qDebug()<<" H264 write_point"<<write_point;
//      qDebug()<<"H264 read_point"<<read_point;
   // if ( video_frame == true ) {
    //     qDebug()<<" H264 write_point"<<a;
//         qDebug()<<"H264 read_point"<<read_point;

        if ( write_point   !=  read_point &&  (( read_point +1 )%20) != write_point ) {
            read_point = ( read_point + 1 )%20;
             qDebug()<< "  %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" ;
            qDebug()<< "   write_point"<<  write_point ;
             qDebug()<< "read_point "  << read_point;


    //           if ( ( ( read_point < write_point )&& (   write_point - read_point < 13 )) || ( ( read_point > write_point )&& ( read_point - write_point > 4 )) ){
//               mutex.lock();
//                bufferNotFull.wakeOne();
//                mutex.unlock();
  //     }
     //            qDebug()<<" H264 write_point"<<write_point;
     //            qDebug()<<"H264 read_point"<<read_point;
            AVPacket pkt;

            av_init_packet(&pkt);
                    pkt.data = NULL;    // packet data will be allocated by the encoder
                    pkt.size = 0;
//            const QImage img(( uchar* )v_video_frame[ read_point ],
//                         640,
//                         480,
//                        QImage::Format_RGB888);

//            QString file = "d:/cap-image2/";
//          //  if(a ==1 )

// // qDebug()<<"H264::run(){ aH264::run(){ aH264::run(){ aH264::run(){ aH264::run(){ aH264::run(){ a"<< a ;
//            file += QString::number(a);
//             file+="w";
//             file += QString::number(write_point);
//               file+="r";
//              file += QString::number(read_point);
//            file+=".jpg";
           // if(a < 20 )
       //    img.save(file);
         //  img.save(file);


               AVFrame *m_pRGBFrame =  new AVFrame[1];  //RGB帧数据
                AVFrame *m_pYUVFrame = new AVFrame[1];  //YUV帧数据
                          int size = 640 * 480;
                         uint8_t * yuv_buff;//
                  //        SwsContext * scxt = sws_getContext(cloneFrame.width(),cloneFrame.height(),AV_PIX_FMT_RGB24,cloneFrame.width(),cloneFrame.height(),AV_PIX_FMT_YUV420P,SWS_POINT,NULL,NULL,NULL);
          SwsContext * scxt = sws_getContext(640,480,AV_PIX_FMT_RGB24,640,480,AV_PIX_FMT_YUV420P,SWS_BICUBIC,NULL,NULL,NULL);
          yuv_buff = (uint8_t *) malloc((size * 3) / 2); // size for YUV 420
          memset( yuv_buff , 0 , (size * 3) / 2 ) ;
          int ppp =   avpicture_fill((AVPicture*)m_pRGBFrame, (uint8_t*)v_video_frame[ read_point ], AV_PIX_FMT_RGB24, 640, 480);
        //     qDebug()<<"ppp"<<ppp;
            //               // 翻转RGB图像
            //                    m_pRGBFrame->data[0]  += m_pRGBFrame->linesize[0] * (cloneFrame.height() - 1);
            //                    m_pRGBFrame->linesize[0] *= -1;
            //                    m_pRGBFrame->data[1]  += m_pRGBFrame->linesize[1] * (cloneFrame.height() / 2 - 1);
            //                    m_pRGBFrame->linesize[1] *= -1;
            //                    m_pRGBFrame->data[2]  += m_pRGBFrame->linesize[2] * (cloneFrame.height() / 2 - 1);
            //                    m_pRGBFrame->linesize[2] *= -1;

                          //将YUV buffer 填充YUV Frame
                        int pp =   avpicture_fill((AVPicture*)m_pYUVFrame, (uint8_t*)yuv_buff, AV_PIX_FMT_YUV420P, 640, 480);
              //          qDebug()<<"pp"<<pp;
                  int heig = sws_scale(scxt,m_pRGBFrame->data,m_pRGBFrame->linesize,0,480,m_pYUVFrame->data,m_pYUVFrame->linesize);

//                  int w_count =  fwrite(m_pYUVFrame->data[0], 1,(640*480) , f_out_yuv);
//                   int w_count1 =  fwrite(m_pYUVFrame->data[1], 1,(640*480)/4 , f_out_yuv);
//                   int w_count2 =  fwrite(m_pYUVFrame->data[2], 1,(640*480)/4 , f_out_yuv);
//                   int cccc= w_count+w_count+w_count;
                   static int cou = 0;
                   cou++;
//                           QFile file1("d:/1/yuvs.txt");
//                           if (!file1.open(QIODevice::Append | QIODevice::Text))
//                               return;
//                           QTextStream out1(&file1);
//                           out1 << "m_pYUVFrame "  <<cou<<":"<<cccc<<"\n";
//                          //  out << "The fNtesToStream is: " << fNumBytesToStream <<"\n";
//                           file1.close();

                  out_size = avcodec_encode_video2( c, &pkt, m_pYUVFrame, &got_packet);
                if (   begin_transport == true   ) {
//                static int  have_file = 0;
//                if (have_file == 0 ) {

//               if (  QFile::exists("d:/1/264.txt")  ){
//               QFile::remove("d:/1/264.txt");
//               }
//                }
//               have_file++;
//                        QFile file("d:/1/264.txt");
//                        if (!file.open(QIODevice::Append | QIODevice::Text))
//                            return;
//                        QTextStream out(&file);
//                        out << " " <<  pkt.size <<"\n";
//                       //  out << "The fNumBytesToStream is: " << fNumBytesToStream <<"\n";
//                        file.close();
             //      qDebug()<<" pkt.size "<< pkt.size;
                  int size_count =  pkt.size  ;// fwrite( pkt.data, 1, pkt.size, f_out );
                  static int frame_coune_i = 1;
             //      qDebug()<<"frame_coune_iframe_coune_iframe_coune_iframe_coune_iframe_coune_i"<<frame_coune_i;
                  frame_coune_i++;
              //     qDebug() << "size_countsize_countsize_countsize_countsize_count"<<size_count;
                  static int bbb= 0 ;
                  static int  counttt = 0;
                  counttt += size_count;

                  if ( bbb == 12 ) {}
//                  if ( share_write_point < share_read_point &&  share_write_point + pkt.size > share_read_point ) {
//                      qDebug()<<"   share_write_point < share_read_point ";
//                      return;
//                  }
                  //写指针到结尾 ， 进入循环
                  if ( share_write_end_point != -1 ) {
                      if (share_read_point < 640*480*4  )  {
                           av_free_packet( &pkt );
                          return;
                      }
                      if ( share_write_point > share_read_point && share_read_point > 640*480*4 ) {
                          share_write_point = 0 ;
                      }
                  }
                  if ( share_write_point < 8000000 ) {

                  memcpy ( &share_memory_555_264[ share_write_point ],  pkt.data ,pkt.size );
                  if ( share_write_point + pkt.size >= 8000000  ) {
                      qDebug()<<"pkt.size " <<pkt.size ;
                  share_write_end_point = share_write_point + pkt.size ;
                  }
              //    if ( share_read_point == 0 ) {
                 //     share_write_point += size_count ;
                  //    return;
              //        }
             //     share_write_point = 0 ;




//                  for ( int got_output = 1; got_output; ) {
//                      fflush(stdout);
//                        static int a = 0;
//                        a++;
//                        if ( a == 5 ) {
//                            a=0;
//                   int   ret = avcodec_encode_video2(c, &pkt, NULL, &got_output);
//                      if (ret < 0) {
//                          fprintf(stderr, "Error encoding frame\n");
//                          exit(1);
//                      }

//                      if (got_output) {
//                       //   printf("Write frame %3d (size=%5d)\n", i, pkt.size);
//                     //     fwrite(pkt.data, 1, pkt.size, f_out );
//                          QFile file("d:/1/264.txt");
//                          if (!file.open(QIODevice::Append | QIODevice::Text))
//                              return;
//                          QTextStream out(&file);
//                          out << "flush " <<  pkt.size <<"\n";
//                         //  out << "The fNumBytesToStream is: " << fNumBytesToStream <<"\n";
//                          file.close();
//                          av_free_packet(&pkt);
//                      }
//                        }
//                  }

//                 // share_write_end_point =0;
//               //   } else {

//                  }
                  share_write_point += size_count ;
                  usedBytes.release( size_count );
                   qDebug()<<" ~~~~~~*&*&*&*&*&*&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&++++~~~~~~~~~~~~~~~~~ " ;
                   qDebug()<<QTime::currentTime();
                   qDebug()<<" size_count "  << size_count;
                  qDebug()<<" share_write_point " <<share_write_point;
                  qDebug()<<" share_read_point " <<share_read_point;
                  qDebug()<<"w - r =  " <<share_write_point - share_read_point  ;
                  qDebug()<<" 264 file size " <<counttt;

                  qDebug()<< "   write_point"<<  write_point ;
                   qDebug()<< "read_point "  << read_point;

                   static int uuu = 0 ;
                   if ( uuu == 0 ) {
                if ( QFile::exists("d:/xxxxxxx.264") ) {
                    QFile::remove("d:/xxxxxxx.264");
                }}
                   uuu++;
              FILE  * f_outt = fopen("d:/xxxxxxx.264", "ab+");
                 fwrite(pkt.data, 1, pkt.size, f_outt);
                  fclose(f_outt);
//                         // int w_count =  fwrite(m_pYUVFrame->data[0], 1,(640*480) , f_outt);
// //                          fwrite(m_pYUVFrame->data[1], 1,(640*480)/4 , f_outt);
// //                          fwrite(m_pYUVFrame->data[2], 1,(640*480)/4 , f_outt);
//                          fclose(f_outt);
//                  bbb++;
                  }
                   av_free_packet( &pkt );
                 delete m_pRGBFrame;  //RGB帧数据
                  delete m_pYUVFrame ;  //YUV帧数据
                  free(yuv_buff);
                  sws_freeContext( scxt );
                  QThread::msleep(110);

                    qDebug()<< "  %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" ;
        } else {
            QThread::msleep(150);
        }

//        const QImage img((uchar *) p_video_frame,
//                     640,
//                     480,
//                    QImage::Format_RGB888);
//       // img.save("d:/zhaozhiyuan5655555456464646465.jpg");
//        a++;
//         qDebug()<<"H264::run() "<< a ;
//         qDebug()<<"H264::run() "<< QTime::currentTime();
   // }
  //  video_frame  = false;


}


 }

 }

    void H264::set_frame( const QVideoFrame &frame ) {
        static int count  = 0;
        count++;
         //qDebug()<<"void H264::set_frame(const QVideoFrame &frame){ count  H264" <<count;
        QString file = "d:/cap-image/";
         //qDebug()<<"111111222222222222222222222299999999999999999999999999999999999999999999999999999999999";
        if (frame.isValid()) {
            static int a = 1;
            if (a ==1) {
          QVideoFrame  cloneFrame(frame);
        cloneFrame.map(QAbstractVideoBuffer::ReadOnly);
        const QImage img(cloneFrame.bits(),
                     cloneFrame.width(),
                     cloneFrame.height(),
                    QImage::Format_RGB888);
       // file += QString(a);
        file+="firsttime";
        file+=".jpg";
//        img.save(file);
          a++;
            }


//
        }
    }
    void H264::okk(){
    //qDebug()<<"thread  run ``````---------------------------------------------------------------";
    }
