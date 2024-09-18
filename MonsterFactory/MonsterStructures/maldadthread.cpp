#include "maldadthread.h"
#include "maldad.h"

MaldadThread::MaldadThread() {}

MaldadThread::MaldadThread(int sleepTime) {
    this->sleepTime = sleepTime;
    this->running = true;
}

void MaldadThread::run()
{
    this -> running = true;
    while(true){
        int secondsLeft = this->sleepTime;
        while(secondsLeft > 0){
            if(!this->running)
            {
                QThread::sleep(1);
                continue;
            }
            QThread::sleep(1);
            Maldad* maldad = new Maldad();
            qDebug() << maldad -> type;
        }
    }
}
