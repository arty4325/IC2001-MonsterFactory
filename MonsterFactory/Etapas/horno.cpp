#include "horno.h"


Horno::Horno() {}

Horno::Horno(int sleepTime, Cola<Mounstro*>* colaMounstro , Cola<Mounstro*>* primeraBandeja, Cola<Mounstro*>* segundaBandeja, Cola<Mounstro*>* terceraBandeja, Cola<Mounstro*>* cuartaBandeja ) {
    this->sleepTime = sleepTime;
    this->running = true;
    this->primeraBandeja = primeraBandeja;
    this->primeraBandeja->changeMax(2);
    this->segundaBandeja = segundaBandeja;
    this->segundaBandeja->changeMax(2);
    this->terceraBandeja = terceraBandeja;
    this->terceraBandeja->changeMax(2);
    this->cuartaBandeja = cuartaBandeja;
    this->cuartaBandeja->changeMax(2);
    this->colaMounstro = colaMounstro;
    //this->queueLabel;
}

void Horno::run()
{
    this->running = true;
    while(true) {
        int secondsLeft = this->sleepTime;
        while (secondsLeft > 0) {
            if (!this->running) {
                QThread::sleep(this->sleepTime);
                continue;
            }
            QThread::sleep(this->sleepTime);
            secondsLeft--;
            // AQUI ES CUANDO ESTA RUNNING
            // Falta un condicional que obligue a que cocine
            if(!(primeraBandeja -> isFull()) || !(segundaBandeja -> isFull()) || !(terceraBandeja ->isFull()) || !(cuartaBandeja->isFull())){
                // Hay que ir llenando las bandejas
                qDebug() << "Intenta Llenar";
                while(!(primeraBandeja -> isFull()) && !(colaMounstro ->isEmpty())){
                    qDebug() << "Intenta Llenar 1";
                    primeraBandeja ->push(colaMounstro ->pop() ->data);
                }
                while(!(segundaBandeja -> isFull()) && !(colaMounstro ->isEmpty())){
                    qDebug() << "Intenta Llenar 2";
                    segundaBandeja -> push(colaMounstro -> pop() -> data);
                }

                while(!(terceraBandeja -> isFull()) && !(colaMounstro ->isEmpty())){
                    qDebug() << "Intenta Llenar 3";
                    terceraBandeja -> push(colaMounstro -> pop() -> data);
                }

                while(!(cuartaBandeja -> isFull()) && !(colaMounstro ->isEmpty())){
                    qDebug() << "Intenta Llenar 4";
                    cuartaBandeja -> push(colaMounstro -> pop() -> data);
                }
            }
        }

        //qDebug() << "Hornea";
    }
}

void Horno::changeTime(int time){
    this-> sleepTime = time;
}

void Horno::changeMaxPrimeraBandeja(int time){
    this -> primeraBandeja -> changeMax(time);
}

void Horno::changeMaxSegundaBandeja(int time){
    this -> segundaBandeja -> changeMax(time);
}

void Horno::changeMaxTerceraBandeja(int time){
    this -> terceraBandeja -> changeMax(time);
}

void Horno::changeMaxCuartaBandeja(int time){
    this -> cuartaBandeja -> changeMax(time);
}






