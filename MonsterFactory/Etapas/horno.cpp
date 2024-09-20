#include "horno.h"


Horno::Horno() {}

Horno::Horno(int sleepTime, Cola<Mounstro*>* primeraBandeja, Cola<Mounstro*>* segundaBandeja, Cola<Mounstro*>* terceraBandeja, Cola<Mounstro*>* cuartaBandeja ) {
    this->sleepTime = sleepTime;
    this->running = true;
    this->primeraBandeja = primeraBandeja;
    this->segundaBandeja = segundaBandeja;
    this->terceraBandeja = terceraBandeja;
    this->cuartaBandeja = cuartaBandeja;
    //this->queueLabel;
}

void Horno::run()
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

        //qDebug() << "Hornea";
    }
}

void Horno::changeTime(int time){
    this-> sleepTime = time;
}






