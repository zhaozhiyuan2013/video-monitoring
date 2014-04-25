/**********
This library is free software; you can redistribute it and/or modify it under
the terms of the GNU Lesser General Public License as published by the
Free Software Foundation; either version 2.1 of the License, or (at your
option) any later version. (See <http://www.gnu.org/copyleft/lesser.html>.)

This library is distributed in the hope that it will be useful, but WITHOUT
ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License for
more details.

You should have received a copy of the GNU Lesser General Public License
along with this library; if not, write to the Free Software Foundation, Inc.,
51 Franklin Street, Fifth Floor, Boston, MA 02110-1301  USA
**********/
// "liveMedia"
// Copyright (c) 1996-2014 Live Networks, Inc.  All rights reserved.
// A file source that is a plain byte stream (rather than frames)
// Implementation

#include "ByteStreamFileSource.hh"
#include "InputFile.hh"
#include "GroupsockHelper.hh"
#include <QDebug>
#include <QSemaphore>
////////// ByteStreamFileSource //////////
#include <QFile>
#include <QTextStream>
//#include <QTime>
#include <QString>

extern unsigned char * share_memory_555_264;
extern int share_read_point ;
extern int share_write_point  ;
extern int share_junk_data  ;
extern QSemaphore usedBytes;
extern int share_write_end_point ;
 bool begin_transport = false;
ByteStreamFileSource*
ByteStreamFileSource::createNew(UsageEnvironment& env, char const* fileName,
				unsigned preferredFrameSize,
				unsigned playTimePerFrame) {
  FILE* fid = OpenInputFile(env, fileName);
  if (fid == NULL) return NULL;

  ByteStreamFileSource* newSource
    = new ByteStreamFileSource(env, fid, preferredFrameSize, playTimePerFrame);
  newSource->fFileSize = GetFileSize(fileName, fid);

  return newSource;
}

ByteStreamFileSource*
ByteStreamFileSource::createNew(UsageEnvironment& env, FILE* fid,
				unsigned preferredFrameSize,
				unsigned playTimePerFrame) {
  if (fid == NULL) return NULL;

  ByteStreamFileSource* newSource = new ByteStreamFileSource(env, fid, preferredFrameSize, playTimePerFrame);
  newSource->fFileSize = GetFileSize(NULL, fid);

  return newSource;
}

void ByteStreamFileSource::seekToByteAbsolute(u_int64_t byteNumber, u_int64_t numBytesToStream) {
  SeekFile64(fFid, (int64_t)byteNumber, SEEK_SET);

  fNumBytesToStream = numBytesToStream;
  fLimitNumBytesToStream = fNumBytesToStream > 0;
}

void ByteStreamFileSource::seekToByteRelative(int64_t offset, u_int64_t numBytesToStream) {
  SeekFile64(fFid, offset, SEEK_CUR);

  fNumBytesToStream = numBytesToStream;
  fLimitNumBytesToStream = fNumBytesToStream > 0;
}

void ByteStreamFileSource::seekToEnd() {
  SeekFile64(fFid, 0, SEEK_END);
}

ByteStreamFileSource::ByteStreamFileSource(UsageEnvironment& env, FILE* fid,
					   unsigned preferredFrameSize,
					   unsigned playTimePerFrame)
  : FramedFileSource(env, fid), fFileSize(0), fPreferredFrameSize(preferredFrameSize),
    fPlayTimePerFrame(playTimePerFrame), fLastPlayTime(0),
    fHaveStartedReading(False), fLimitNumBytesToStream(False), fNumBytesToStream(0) {
#ifndef READ_FROM_FILES_SYNCHRONOUSLY
  makeSocketNonBlocking(fileno(fFid));
#endif

  // Test whether the file is seekable
  fFidIsSeekable = FileIsSeekable(fFid);
}

ByteStreamFileSource::~ByteStreamFileSource() {
  if (fFid == NULL) return;

#ifndef READ_FROM_FILES_SYNCHRONOUSLY
  envir().taskScheduler().turnOffBackgroundReadHandling(fileno(fFid));
#endif

  CloseInputFile(fFid);
}

void ByteStreamFileSource::doGetNextFrame() {
  if (feof(fFid) || ferror(fFid) || (fLimitNumBytesToStream && fNumBytesToStream == 0)) {
    handleClosure();
    return;
  }

#ifdef READ_FROM_FILES_SYNCHRONOUSLY
  doReadFromFile();
#else
  if (!fHaveStartedReading) {
    // Await readable data from the file:
    envir().taskScheduler().turnOnBackgroundReadHandling(fileno(fFid),
	       (TaskScheduler::BackgroundHandlerProc*)&fileReadableHandler, this);
    fHaveStartedReading = True;
  }
#endif
}

void ByteStreamFileSource::doStopGettingFrames() {
  envir().taskScheduler().unscheduleDelayedTask(nextTask());
#ifndef READ_FROM_FILES_SYNCHRONOUSLY
  envir().taskScheduler().turnOffBackgroundReadHandling(fileno(fFid));
  fHaveStartedReading = False;
#endif
}

void ByteStreamFileSource::fileReadableHandler(ByteStreamFileSource* source, int /*mask*/) {
  if (!source->isCurrentlyAwaitingData()) {
    source->doStopGettingFrames(); // we're not ready for the data yet
    return;
  }
  source->doReadFromFile();
}

void ByteStreamFileSource::doReadFromFile() {
  // Try to read as many bytes as will fit in the buffer provided (or "fPreferredFrameSize" if less)
  if (fLimitNumBytesToStream && fNumBytesToStream < (u_int64_t)fMaxSize) {
    fMaxSize = (unsigned)fNumBytesToStream;
  }
  if (fPreferredFrameSize > 0 && fPreferredFrameSize < fMaxSize) {
    fMaxSize = fPreferredFrameSize;
    qDebug()<<fPreferredFrameSize;
  }
#ifdef READ_FROM_FILES_SYNCHRONOUSLY
  static int a = 0 ;
  a++;
  static int count = 0;
  count += fMaxSize;
//  FILE *zz;
//  zz = fopen("d:/123456.txt","w+");
//  char aa[25];
//  itoa( count,aa , 10);
//  fwrite ( aa,1,10,zz );
//  fclose(zz);

//    qDebug()<<" ByteStreamFileSource::doReadFromFile() {   172  count ==   " <<count ;
//    qDebug()<<" ByteStreamFileSource::doReadFromFile() {   173    ==   " <<a;
//    qDebug()<<" ByteStreamFileSource::doReadFromFile() {   174   fMaxSize ==   " << fMaxSize;
//  FILE *readdd ;
//  readdd = fopen("d:/99999999.264" ,"rb");
  static int aa = 0;
  //if ( aa == 0)
  //fFid = readdd;
  aa++;
  bool rool = false;
 qDebug()<<"   READ_FROM_FILES_SYNCHRONOUSLY fMaxSize  aa"<<    fMaxSize <<"dd"<<aa ;
 //fMaxSize  = 3000;

   begin_transport = true;
 if ( share_write_point > share_read_point ) {
   if (  share_write_point - share_read_point < fMaxSize )
     fMaxSize = share_write_point - share_read_point ;

 }
  qDebug()<<"   READ_FROM_FILES_SYNCHRONOUSLY fMaxSize  aa"<<    fMaxSize <<"dd"<<aa ;
  usedBytes.acquire( fMaxSize );

  if ( share_write_point < share_read_point ) {
  if (   share_write_end_point - share_read_point < fMaxSize ) {
      fMaxSize = share_write_end_point - share_read_point;
      share_write_end_point = -1 ;
      qDebug() << " zhuan wan ";
       rool =true;
  }


  }

  qDebug()<<"  ------@#$#$%%%%%%%^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^9999999999999999999999999999999999---------- "  ;
  qDebug()<<"   share_write_point   " <<share_write_point ;
  qDebug()<<" share_read_point  " <<share_read_point;
  qDebug()<<"   share_write_point p- share_read_point   " <<  (share_write_point-  share_read_point)  ;
  qDebug()<<"   fMaxSize   " << fMaxSize ;
  qDebug()<<"   share_write_end_point   " << share_write_end_point;
  if ( (share_write_point > share_read_point && share_write_point - share_read_point >= fMaxSize ) || share_write_point < share_read_point ) {
        static int first = 1;
        if ( first == 1 && ( share_write_point - share_read_point > 3000) )  {
         //   usedBytes.acquire( share_write_point - 3000 );
            qDebug() << "aa " << aa <<"    if ( first == 1 && ( share_write_point - share_read_point > 3000) )  {  ";
          share_read_point  =  share_write_point - 3000;
         fMaxSize = 2000;
        }
        first++;

         memcpy( fTo,  &share_memory_555_264[ share_read_point ] ,fMaxSize );


//         QFile file("d:/123456.txt");
//             if (!file.open(QIODevice::Append | QIODevice::Text))
//                 return;

//             QTextStream out(&file);
//             out << "The magic number is: " << count <<"\n";
//              out << "The fNumBytesToStream is: " << fNumBytesToStream <<"\n";
//               out << "fMaxSize is: " << fMaxSize <<"\n";
//                out << "fPreferredFrameSize is: " << fPreferredFrameSize <<"\n";
//       //          out << "The magic number is: " << count <<"\n";
//       //           out << "The magic number is: " << count <<"\n";
//       //            out << "The magic number is: " << count <<"\n";
//       //    //  out << QString ( QTime::currentTime() );
//             file.close();
         if (  rool ) {
         share_read_point = 0 ;
         }else {
         share_read_point +=  fMaxSize; }
        fFrameSize = fMaxSize;
  }


  //if ( )
  //memcpy( fTo, src ,fMaxSize );
 // fFrameSize = fread(fTo, 1, fMaxSize, fFid );
 // fclose (readdd ) ;
 // fFrameSize = fread(fTo, 1, fMaxSize, fFid);
#else
  if (fFidIsSeekable) {
    fFrameSize = fread(fTo, 1, fMaxSize, fFid);
  } else {
    // For non-seekable files (e.g., pipes), call "read()" rather than "fread()", to ensure that the read doesn't block:
    fFrameSize = read(fileno(fFid), fTo, fMaxSize);
  }
#endif
//  if (fFrameSize == 0) {
//    handleClosure();
//    return;
//  }
//  fNumBytesToStream -= fFrameSize;

//  // Set the 'presentation time':
//  if (fPlayTimePerFrame > 0 && fPreferredFrameSize > 0) {
//    if (fPresentationTime.tv_sec == 0 && fPresentationTime.tv_usec == 0) {
//      // This is the first frame, so use the current time:
//      gettimeofday(&fPresentationTime, NULL);
//    } else {
//      // Increment by the play time of the previous data:
//      unsigned uSeconds	= fPresentationTime.tv_usec + fLastPlayTime;
//      fPresentationTime.tv_sec += uSeconds/1000000;
//      fPresentationTime.tv_usec = uSeconds%1000000;
//    }

//    // Remember the play time of this data:
//    fLastPlayTime = (fPlayTimePerFrame*fFrameSize)/fPreferredFrameSize;
//    fDurationInMicroseconds = fLastPlayTime;
//  } else {
//    // We don't know a specific play time duration for this data,
//    // so just record the current time as being the 'presentation time':
//    gettimeofday(&fPresentationTime, NULL);
//  }

  // Inform the reader that he has data:
#ifdef READ_FROM_FILES_SYNCHRONOUSLY
  // To avoid possible infinite recursion, we need to return to the event loop to do this:
  nextTask() = envir().taskScheduler().scheduleDelayedTask(0,
                (TaskFunc*)FramedSource::afterGetting, this);
#else
  // Because the file read was done from the event loop, we can call the
  // 'after getting' function directly, without risk of infinite recursion:
  FramedSource::afterGetting(this);
#endif
}
