#-------------------------------------------------
#
# Project created by QtCreator 2013-11-26T20:57:51
#
#-------------------------------------------------

QT       -= core gui
QT       += multimedia
QT       += multimediawidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QMyLearn
TEMPLATE = app
LIBS += "Ws2_32.lib"
INCLUDEPATH += "$$_PRO_FILE_PWD_/include"
INCLUDEPATH += "$$_PRO_FILE_PWD_/liveMedia"

INCLUDEPATH += "$$_PRO_FILE_PWD_/include"
LIBS +="$$_PRO_FILE_PWD_/lib/avcodec.lib"
LIBS +="$$_PRO_FILE_PWD_/lib/avformat.lib"
LIBS +="$$_PRO_FILE_PWD_/lib/swscale.lib"
LIBS +="$$_PRO_FILE_PWD_/lib/avdevice.lib"
LIBS +="$$_PRO_FILE_PWD_/lib/avfilter.lib"
LIBS +="$$_PRO_FILE_PWD_/lib/avutil.lib"
LIBS +="$$_PRO_FILE_PWD_/lib/postproc.lib"
LIBS +="$$_PRO_FILE_PWD_/lib/swresample.lib"

SOURCES += main.cpp\
        mainwindow.cpp \
    absurface.cpp \
    make264.cpp \
    h264.cpp \
    capture.cpp \
    ab.cpp \
    productor.cpp \
    BasicUsageEnvironment/BasicHashTable.cpp \
    BasicUsageEnvironment/BasicTaskScheduler.cpp \
    BasicUsageEnvironment/BasicTaskScheduler0.cpp \
    BasicUsageEnvironment/BasicUsageEnvironment.cpp \
    BasicUsageEnvironment/BasicUsageEnvironment0.cpp \
    BasicUsageEnvironment/DelayQueue.cpp \
    groupsock/GroupEId.cpp \
    groupsock/Groupsock.cpp \
    groupsock/GroupsockHelper.cpp \
    groupsock/IOHandlers.cpp \
    groupsock/NetAddress.cpp \
    groupsock/NetInterface.cpp \
    groupsock/inet.c \
    liveMedia/AC3AudioFileServerMediaSubsession.cpp \
    liveMedia/AC3AudioRTPSink.cpp \
    liveMedia/AC3AudioRTPSource.cpp \
    liveMedia/AC3AudioStreamFramer.cpp \
    liveMedia/ADTSAudioFileServerMediaSubsession.cpp \
    liveMedia/ADTSAudioFileSource.cpp \
    liveMedia/AMRAudioFileServerMediaSubsession.cpp \
    liveMedia/AMRAudioFileSink.cpp \
    liveMedia/AMRAudioFileSource.cpp \
    liveMedia/AMRAudioRTPSink.cpp \
    liveMedia/AMRAudioRTPSource.cpp \
    liveMedia/AMRAudioSource.cpp \
    liveMedia/AudioInputDevice.cpp \
    liveMedia/AudioRTPSink.cpp \
    liveMedia/AVIFileSink.cpp \
    liveMedia/Base64.cpp \
    liveMedia/BasicUDPSink.cpp \
    liveMedia/BasicUDPSource.cpp \
    liveMedia/BitVector.cpp \
    liveMedia/ByteStreamFileSource.cpp \
    liveMedia/ByteStreamMemoryBufferSource.cpp \
    liveMedia/ByteStreamMultiFileSource.cpp \
    liveMedia/DarwinInjector.cpp \
    liveMedia/DeviceSource.cpp \
    liveMedia/DigestAuthentication.cpp \
    liveMedia/DVVideoFileServerMediaSubsession.cpp \
    liveMedia/DVVideoRTPSink.cpp \
    liveMedia/DVVideoRTPSource.cpp \
    liveMedia/DVVideoStreamFramer.cpp \
    liveMedia/EBMLNumber.cpp \
    liveMedia/FileServerMediaSubsession.cpp \
    liveMedia/FileSink.cpp \
    liveMedia/FramedFileSource.cpp \
    liveMedia/FramedFilter.cpp \
    liveMedia/FramedSource.cpp \
    liveMedia/GSMAudioRTPSink.cpp \
    liveMedia/H261VideoRTPSource.cpp \
    liveMedia/H263plusVideoFileServerMediaSubsession.cpp \
    liveMedia/H263plusVideoRTPSink.cpp \
    liveMedia/H263plusVideoRTPSource.cpp \
    liveMedia/H263plusVideoStreamFramer.cpp \
    liveMedia/H263plusVideoStreamParser.cpp \
    liveMedia/H264or5VideoFileSink.cpp \
    liveMedia/H264or5VideoRTPSink.cpp \
    liveMedia/H264or5VideoStreamDiscreteFramer.cpp \
    liveMedia/H264or5VideoStreamFramer.cpp \
    liveMedia/H264VideoFileServerMediaSubsession.cpp \
    liveMedia/H264VideoFileSink.cpp \
    liveMedia/H264VideoRTPSink.cpp \
    liveMedia/H264VideoRTPSource.cpp \
    liveMedia/H264VideoStreamDiscreteFramer.cpp \
    liveMedia/H264VideoStreamFramer.cpp \
    liveMedia/H265VideoFileServerMediaSubsession.cpp \
    liveMedia/H265VideoFileSink.cpp \
    liveMedia/H265VideoRTPSink.cpp \
    liveMedia/H265VideoRTPSource.cpp \
    liveMedia/H265VideoStreamDiscreteFramer.cpp \
    liveMedia/H265VideoStreamFramer.cpp \
    liveMedia/InputFile.cpp \
    liveMedia/JPEGVideoRTPSink.cpp \
    liveMedia/JPEGVideoRTPSource.cpp \
    liveMedia/JPEGVideoSource.cpp \
    liveMedia/Locale.cpp \
    liveMedia/MatroskaDemuxedTrack.cpp \
    liveMedia/MatroskaFile.cpp \
    liveMedia/MatroskaFileParser.cpp \
    liveMedia/MatroskaFileServerDemux.cpp \
    liveMedia/MatroskaFileServerMediaSubsession.cpp \
    liveMedia/Media.cpp \
    liveMedia/MediaSession.cpp \
    liveMedia/MediaSink.cpp \
    liveMedia/MediaSource.cpp \
    liveMedia/MP3ADU.cpp \
    liveMedia/MP3ADUdescriptor.cpp \
    liveMedia/MP3ADUinterleaving.cpp \
    liveMedia/MP3ADURTPSink.cpp \
    liveMedia/MP3ADURTPSource.cpp \
    liveMedia/MP3ADUTranscoder.cpp \
    liveMedia/MP3AudioFileServerMediaSubsession.cpp \
    liveMedia/MP3AudioMatroskaFileServerMediaSubsession.cpp \
    liveMedia/MP3FileSource.cpp \
    liveMedia/MP3Internals.cpp \
    liveMedia/MP3InternalsHuffman.cpp \
    liveMedia/MP3InternalsHuffmanTable.cpp \
    liveMedia/MP3StreamState.cpp \
    liveMedia/MP3Transcoder.cpp \
    liveMedia/MPEG1or2AudioRTPSink.cpp \
    liveMedia/MPEG1or2AudioRTPSource.cpp \
    liveMedia/MPEG1or2AudioStreamFramer.cpp \
    liveMedia/MPEG1or2Demux.cpp \
    liveMedia/MPEG1or2DemuxedElementaryStream.cpp \
    liveMedia/MPEG1or2DemuxedServerMediaSubsession.cpp \
    liveMedia/MPEG1or2FileServerDemux.cpp \
    liveMedia/MPEG1or2VideoFileServerMediaSubsession.cpp \
    liveMedia/MPEG1or2VideoRTPSink.cpp \
    liveMedia/MPEG1or2VideoRTPSource.cpp \
    liveMedia/MPEG1or2VideoStreamDiscreteFramer.cpp \
    liveMedia/MPEG1or2VideoStreamFramer.cpp \
    liveMedia/MPEG2IndexFromTransportStream.cpp \
    liveMedia/MPEG2TransportFileServerMediaSubsession.cpp \
    liveMedia/MPEG2TransportStreamFramer.cpp \
    liveMedia/MPEG2TransportStreamFromESSource.cpp \
    liveMedia/MPEG2TransportStreamFromPESSource.cpp \
    liveMedia/MPEG2TransportStreamIndexFile.cpp \
    liveMedia/MPEG2TransportStreamMultiplexor.cpp \
    liveMedia/MPEG2TransportStreamTrickModeFilter.cpp \
    liveMedia/MPEG2TransportUDPServerMediaSubsession.cpp \
    liveMedia/MPEG4ESVideoRTPSink.cpp \
    liveMedia/MPEG4ESVideoRTPSource.cpp \
    liveMedia/MPEG4GenericRTPSink.cpp \
    liveMedia/MPEG4GenericRTPSource.cpp \
    liveMedia/MPEG4LATMAudioRTPSink.cpp \
    liveMedia/MPEG4LATMAudioRTPSource.cpp \
    liveMedia/MPEG4VideoFileServerMediaSubsession.cpp \
    liveMedia/MPEG4VideoStreamDiscreteFramer.cpp \
    liveMedia/MPEG4VideoStreamFramer.cpp \
    liveMedia/MPEGVideoStreamFramer.cpp \
    liveMedia/MPEGVideoStreamParser.cpp \
    liveMedia/MultiFramedRTPSink.cpp \
    liveMedia/MultiFramedRTPSource.cpp \
    liveMedia/OggDemuxedTrack.cpp \
    liveMedia/OggFile.cpp \
    liveMedia/OggFileParser.cpp \
    liveMedia/OggFileServerDemux.cpp \
    liveMedia/OggFileServerMediaSubsession.cpp \
    liveMedia/OggFileSink.cpp \
    liveMedia/OnDemandServerMediaSubsession.cpp \
    liveMedia/ourMD5.cpp \
    liveMedia/OutputFile.cpp \
    liveMedia/PassiveServerMediaSubsession.cpp \
    liveMedia/ProxyServerMediaSession.cpp \
    liveMedia/QCELPAudioRTPSource.cpp \
    liveMedia/QuickTimeFileSink.cpp \
    liveMedia/QuickTimeGenericRTPSource.cpp \
    liveMedia/RTCP.cpp \
    liveMedia/RTPInterface.cpp \
    liveMedia/RTPSink.cpp \
    liveMedia/RTPSource.cpp \
    liveMedia/RTSPClient.cpp \
    liveMedia/RTSPCommon.cpp \
    liveMedia/RTSPRegisterSender.cpp \
    liveMedia/RTSPServer.cpp \
    liveMedia/RTSPServerSupportingHTTPStreaming.cpp \
    liveMedia/ServerMediaSession.cpp \
    liveMedia/SimpleRTPSink.cpp \
    liveMedia/SimpleRTPSource.cpp \
    liveMedia/SIPClient.cpp \
    liveMedia/StreamParser.cpp \
    liveMedia/StreamReplicator.cpp \
    liveMedia/T140TextRTPSink.cpp \
    liveMedia/TCPStreamSink.cpp \
    liveMedia/TextRTPSink.cpp \
    liveMedia/TheoraVideoRTPSink.cpp \
    liveMedia/TheoraVideoRTPSource.cpp \
    liveMedia/uLawAudioFilter.cpp \
    liveMedia/VideoRTPSink.cpp \
    liveMedia/VorbisAudioRTPSink.cpp \
    liveMedia/VorbisAudioRTPSource.cpp \
    liveMedia/VP8VideoRTPSink.cpp \
    liveMedia/VP8VideoRTPSource.cpp \
    liveMedia/WAVAudioFileServerMediaSubsession.cpp \
    liveMedia/WAVAudioFileSource.cpp \
    liveMedia/rtcp_from_spec.c \
    UsageEnvironment/HashTable.cpp \
    UsageEnvironment/strDup.cpp \
    UsageEnvironment/UsageEnvironment.cpp \
    live555.cpp \
    productor2.cpp \
    thread1.cpp

HEADERS  += mainwindow.h \
    absurface.h \
    include/libavcodec/avcodec.h \
    include/libavcodec/avfft.h \
    include/libavcodec/dxva2.h \
    include/libavcodec/old_codec_ids.h \
    include/libavcodec/vaapi.h \
    include/libavcodec/vda.h \
    include/libavcodec/vdpau.h \
    include/libavcodec/version.h \
    include/libavcodec/xvmc.h \
    include/libavdevice/avdevice.h \
    include/libavdevice/version.h \
    include/libavfilter/asrc_abuffer.h \
    include/libavfilter/avcodec.h \
    include/libavfilter/avfilter.h \
    include/libavfilter/avfiltergraph.h \
    include/libavfilter/buffersink.h \
    include/libavfilter/buffersrc.h \
    include/libavfilter/version.h \
    include/libavformat/avformat.h \
    include/libavformat/avio.h \
    include/libavformat/version.h \
    include/libavutil/adler32.h \
    include/libavutil/aes.h \
    include/libavutil/attributes.h \
    include/libavutil/audio_fifo.h \
    include/libavutil/audioconvert.h \
    include/libavutil/avassert.h \
    include/libavutil/avconfig.h \
    include/libavutil/avstring.h \
    include/libavutil/avutil.h \
    include/libavutil/base64.h \
    include/libavutil/blowfish.h \
    include/libavutil/bprint.h \
    include/libavutil/bswap.h \
    include/libavutil/buffer.h \
    include/libavutil/channel_layout.h \
    include/libavutil/common.h \
    include/libavutil/cpu.h \
    include/libavutil/crc.h \
    include/libavutil/dict.h \
    include/libavutil/downmix_info.h \
    include/libavutil/error.h \
    include/libavutil/eval.h \
    include/libavutil/ffversion.h \
    include/libavutil/fifo.h \
    include/libavutil/file.h \
    include/libavutil/frame.h \
    include/libavutil/hmac.h \
    include/libavutil/imgutils.h \
    include/libavutil/intfloat.h \
    include/libavutil/intfloat_readwrite.h \
    include/libavutil/intreadwrite.h \
    include/libavutil/lfg.h \
    include/libavutil/log.h \
    include/libavutil/lzo.h \
    include/libavutil/macros.h \
    include/libavutil/mathematics.h \
    include/libavutil/md5.h \
    include/libavutil/mem.h \
    include/libavutil/murmur3.h \
    include/libavutil/old_pix_fmts.h \
    include/libavutil/opt.h \
    include/libavutil/parseutils.h \
    include/libavutil/pixdesc.h \
    include/libavutil/pixfmt.h \
    include/libavutil/random_seed.h \
    include/libavutil/rational.h \
    include/libavutil/ripemd.h \
    include/libavutil/samplefmt.h \
    include/libavutil/sha.h \
    include/libavutil/sha512.h \
    include/libavutil/stereo3d.h \
    include/libavutil/time.h \
    include/libavutil/timecode.h \
    include/libavutil/timestamp.h \
    include/libavutil/version.h \
    include/libavutil/xtea.h \
    include/libpostproc/postprocess.h \
    include/libpostproc/version.h \
    include/libswresample/swresample.h \
    include/libswresample/version.h \
    include/libswscale/swscale.h \
    include/libswscale/version.h \
    make264.h \
    h264.h \
    capture.h \
    ab.h \
    productor.h\
    liveMedia/EBMLNumber.hh \
    liveMedia/H263plusVideoStreamParser.hh \
    liveMedia/MatroskaDemuxedTrack.hh \
    liveMedia/MatroskaFileParser.hh \
    liveMedia/MatroskaFileServerMediaSubsession.hh \
    liveMedia/MP3ADUdescriptor.hh \
    liveMedia/MP3AudioMatroskaFileServerMediaSubsession.hh \
    liveMedia/MP3Internals.hh \
    liveMedia/MP3InternalsHuffman.hh \
    liveMedia/MP3StreamState.hh \
    liveMedia/MPEGVideoStreamParser.hh \
    liveMedia/OggDemuxedTrack.hh \
    liveMedia/OggFileParser.hh \
    liveMedia/OggFileServerMediaSubsession.hh \
    liveMedia/ourMD5.hh \
    liveMedia/rtcp_from_spec.h \
    liveMedia/StreamParser.hh \
    include/AC3AudioFileServerMediaSubsession.hh \
    include/AC3AudioRTPSink.hh \
    include/AC3AudioRTPSource.hh \
    include/AC3AudioStreamFramer.hh \
    include/ADTSAudioFileServerMediaSubsession.hh \
    include/ADTSAudioFileSource.hh \
    include/AMRAudioFileServerMediaSubsession.hh \
    include/AMRAudioFileSink.hh \
    include/AMRAudioFileSource.hh \
    include/AMRAudioRTPSink.hh \
    include/AMRAudioRTPSource.hh \
    include/AMRAudioSource.hh \
    include/AudioInputDevice.hh \
    include/AudioRTPSink.hh \
    include/AVIFileSink.hh \
    include/Base64.hh \
    include/BasicHashTable.hh \
    include/BasicUDPSink.hh \
    include/BasicUDPSource.hh \
    include/BasicUsageEnvironment.hh \
    include/BasicUsageEnvironment_version.hh \
    include/BasicUsageEnvironment0.hh \
    include/BitVector.hh \
    include/Boolean.hh \
    include/ByteStreamFileSource.hh \
    include/ByteStreamMemoryBufferSource.hh \
    include/ByteStreamMultiFileSource.hh \
    include/DarwinInjector.hh \
    include/DelayQueue.hh \
    include/DeviceSource.hh \
    include/DigestAuthentication.hh \
    include/DVVideoFileServerMediaSubsession.hh \
    include/DVVideoRTPSink.hh \
    include/DVVideoRTPSource.hh \
    include/DVVideoStreamFramer.hh \
    include/FileServerMediaSubsession.hh \
    include/FileSink.hh \
    include/FramedFileSource.hh \
    include/FramedFilter.hh \
    include/FramedSource.hh \
    include/GroupEId.hh \
    include/Groupsock.hh \
    include/groupsock_version.hh \
    include/GroupsockHelper.hh \
    include/GSMAudioRTPSink.hh \
    include/H261VideoRTPSource.hh \
    include/H263plusVideoFileServerMediaSubsession.hh \
    include/H263plusVideoRTPSink.hh \
    include/H263plusVideoRTPSource.hh \
    include/H263plusVideoStreamFramer.hh \
    include/H264or5VideoFileSink.hh \
    include/H264or5VideoRTPSink.hh \
    include/H264or5VideoStreamDiscreteFramer.hh \
    include/H264or5VideoStreamFramer.hh \
    include/H264VideoFileServerMediaSubsession.hh \
    include/H264VideoFileSink.hh \
    include/H264VideoRTPSink.hh \
    include/H264VideoRTPSource.hh \
    include/H264VideoStreamDiscreteFramer.hh \
    include/H264VideoStreamFramer.hh \
    include/H265VideoFileServerMediaSubsession.hh \
    include/H265VideoFileSink.hh \
    include/H265VideoRTPSink.hh \
    include/H265VideoRTPSource.hh \
    include/H265VideoStreamDiscreteFramer.hh \
    include/H265VideoStreamFramer.hh \
    include/HandlerSet.hh \
    include/HashTable.hh \
    include/InputFile.hh \
    include/IOHandlers.hh \
    include/JPEGVideoRTPSink.hh \
    include/JPEGVideoRTPSource.hh \
    include/JPEGVideoSource.hh \
    include/liveMedia.hh \
    include/liveMedia_version.hh \
    include/Locale.hh \
    include/MatroskaFile.hh \
    include/MatroskaFileServerDemux.hh \
    include/Media.hh \
    include/MediaSession.hh \
    include/MediaSink.hh \
    include/MediaSource.hh \
    include/MP3ADU.hh \
    include/MP3ADUinterleaving.hh \
    include/MP3ADURTPSink.hh \
    include/MP3ADURTPSource.hh \
    include/MP3ADUTranscoder.hh \
    include/MP3AudioFileServerMediaSubsession.hh \
    include/MP3FileSource.hh \
    include/MP3Transcoder.hh \
    include/MPEG1or2AudioRTPSink.hh \
    include/MPEG1or2AudioRTPSource.hh \
    include/MPEG1or2AudioStreamFramer.hh \
    include/MPEG1or2Demux.hh \
    include/MPEG1or2DemuxedElementaryStream.hh \
    include/MPEG1or2DemuxedServerMediaSubsession.hh \
    include/MPEG1or2FileServerDemux.hh \
    include/MPEG1or2VideoFileServerMediaSubsession.hh \
    include/MPEG1or2VideoRTPSink.hh \
    include/MPEG1or2VideoRTPSource.hh \
    include/MPEG1or2VideoStreamDiscreteFramer.hh \
    include/MPEG1or2VideoStreamFramer.hh \
    include/MPEG2IndexFromTransportStream.hh \
    include/MPEG2TransportFileServerMediaSubsession.hh \
    include/MPEG2TransportStreamFramer.hh \
    include/MPEG2TransportStreamFromESSource.hh \
    include/MPEG2TransportStreamFromPESSource.hh \
    include/MPEG2TransportStreamIndexFile.hh \
    include/MPEG2TransportStreamMultiplexor.hh \
    include/MPEG2TransportStreamTrickModeFilter.hh \
    include/MPEG2TransportUDPServerMediaSubsession.hh \
    include/MPEG4ESVideoRTPSink.hh \
    include/MPEG4ESVideoRTPSource.hh \
    include/MPEG4GenericRTPSink.hh \
    include/MPEG4GenericRTPSource.hh \
    include/MPEG4LATMAudioRTPSink.hh \
    include/MPEG4LATMAudioRTPSource.hh \
    include/MPEG4VideoFileServerMediaSubsession.hh \
    include/MPEG4VideoStreamDiscreteFramer.hh \
    include/MPEG4VideoStreamFramer.hh \
    include/MPEGVideoStreamFramer.hh \
    include/MultiFramedRTPSink.hh \
    include/MultiFramedRTPSource.hh \
    include/NetAddress.hh \
    include/NetCommon.h \
    include/NetInterface.hh \
    include/OggFile.hh \
    include/OggFileServerDemux.hh \
    include/OggFileSink.hh \
    include/OnDemandServerMediaSubsession.hh \
    include/OutputFile.hh \
    include/PassiveServerMediaSubsession.hh \
    include/ProxyServerMediaSession.hh \
    include/QCELPAudioRTPSource.hh \
    include/QuickTimeFileSink.hh \
    include/QuickTimeGenericRTPSource.hh \
    include/RTCP.hh \
    include/RTPInterface.hh \
    include/RTPSink.hh \
    include/RTPSource.hh \
    include/RTSPClient.hh \
    include/RTSPCommon.hh \
    include/RTSPRegisterSender.hh \
    include/RTSPServer.hh \
    include/RTSPServerSupportingHTTPStreaming.hh \
    include/ServerMediaSession.hh \
    include/SimpleRTPSink.hh \
    include/SimpleRTPSource.hh \
    include/SIPClient.hh \
    include/strDup.hh \
    include/StreamReplicator.hh \
    include/T140TextRTPSink.hh \
    include/TCPStreamSink.hh \
    include/TextRTPSink.hh \
    include/TheoraVideoRTPSink.hh \
    include/TheoraVideoRTPSource.hh \
    include/TunnelEncaps.hh \
    include/uLawAudioFilter.hh \
    include/UsageEnvironment.hh \
    include/UsageEnvironment_version.hh \
    include/VideoRTPSink.hh \
    include/VorbisAudioRTPSink.hh \
    include/VorbisAudioRTPSource.hh \
    include/VP8VideoRTPSink.hh \
    include/VP8VideoRTPSource.hh \
    include/WAVAudioFileServerMediaSubsession.hh \
    include/WAVAudioFileSource.hh\
    live555.h \
    productor2.h \
    thread1.h

FORMS    += mainwindow.ui
