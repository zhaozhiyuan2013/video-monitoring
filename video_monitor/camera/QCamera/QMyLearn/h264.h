#ifndef H264_H
#define H264_H

#include <QThread>
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
#include <QVideoFrame>
class H264 : public QThread
{
    Q_OBJECT
public:
    explicit H264(QObject *parent = 0);
    AVCodec *codec;
    AVCodecContext *c;
    int out_size, size, outbuf_size,got_packet,x,y;
    FILE *f_out,*f_in;
     FILE *f_out_yuv;
    AVFrame *picture;
    uint8_t *outbuf, *picture_buf;
    AVPacket avpkt, pktt;

    void run();
signals:

public slots:
    void okk();
    void set_frame(const QVideoFrame &);
};

#endif // H264_H
