#include "maldadthread.h"
#include "maldad.h"

MaldadThread::MaldadThread() {}

MaldadThread::MaldadThread(int sleepTime, Cola<Maldad*>* cola) {
    this->sleepTime = sleepTime;
    this->cola = cola;
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
            Maldad* energia = new Maldad();
            cola ->push(energia);
            //qDebug() << energia -> type;
        }
    }
}
