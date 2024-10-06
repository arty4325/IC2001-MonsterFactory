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
    this->running = true;
    while(true) {
        int secondsLeft = this->sleepTime;

        while (secondsLeft > 0) {
            if (!this->running) {
                QThread::sleep(1);
                continue;
            }
            QThread::sleep(1);
            secondsLeft--;
        }

        Maldad* maldad = new Maldad(); // Instancia un objeto de maldad
        cola->push(maldad); // Pone ese objeto en la cola
    }
}

void MaldadThread::changeTime(int time){
    this-> sleepTime = time;
}

void MaldadThread::stop(int val){
    if(val == 2){
        this->running = false;
    } else {
        this->running = true;
    }
}


