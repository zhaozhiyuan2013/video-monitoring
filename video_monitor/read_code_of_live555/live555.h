#ifndef LIVE555_H
#define LIVE555_H

#include <QThread>
#include <QCoreApplication>
#include "liveMedia.hh"
#include "BasicUsageEnvironment.hh"
#include "MatroskaFileServerDemux.hh"
#include "OggFileServerDemux.hh"

class MatroskaFileServerDemux;
class OggFileServerDemux;
//namespace live5555 {





// To make the second and subsequent client for each stream reuse the same
// input stream as the first client (rather than playing the file from the
// start for each client), change the following "False" to "True":


// To stream *only* MPEG-1 or 2 video "I" frames
// (e.g., to reduce network bandwidth),
// change the following "False" to "True":




class live555 : public QThread
{
    Q_OBJECT
public:
    explicit live555(QObject *parent = 0);
    void run();
    TaskScheduler* scheduler;
    UserAuthenticationDatabase* authDB;
     RTSPServer* rtspServer;
     UsageEnvironment* env;
     Boolean iFramesOnly ;
     Boolean reuseFirstSource;

//      void announceStream(RTSPServer* rtspServer, ServerMediaSession* sms,
//                    char const* streamName, char const* inputFileName); // fwd
      void announceStream(RTSPServer* rtspServer, ServerMediaSession* sms,
                    char const* streamName, char const* inputFileName) {
       char* url = rtspServer->rtspURL(sms);
       UsageEnvironment& env = rtspServer->envir();
       env << "\n\"" << streamName << "\" stream, from the file \""
           << inputFileName << "\"\n";
       env << "Play this stream using the URL \"" << url << "\"\n";
       delete[] url;
     }



signals:

public slots:

};
#endif // LIVE555_H
