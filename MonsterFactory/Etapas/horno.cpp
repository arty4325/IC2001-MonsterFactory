#include "horno.h"
#include <QDateTime>
#include <QDebug>

Horno::Horno() {}

Horno::Horno(int sleepTime, Cola<Mounstro*>* colaMounstro , Cola<Mounstro*>* primeraBandeja, Cola<Mounstro*>* segundaBandeja, Cola<Mounstro*>* terceraBandeja, Cola<Mounstro*>* cuartaBandeja, Cola<Mounstro*>* colaCalidad ) {
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
    this -> colaCalidad = colaCalidad;
    this->isFirstBlocked = false;
    this->isSecondBlocked = false;
    this->isThirdBlocked = false;
    this->isFourthBlocked = false;
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
            if((!(primeraBandeja -> isFull()) || !(segundaBandeja -> isFull()) || !(terceraBandeja ->isFull()) || !(cuartaBandeja->isFull()))){
                // Hay que ir llenando las bandejas
                //qDebug() << "Intenta Llenar";
                //qDebug() << isFirstBlocked << " " << isSecondBlocked << " " << isThirdBlocked << " " << isFourthBlocked;
                while(!(primeraBandeja -> isFull()) && !(colaMounstro ->isEmpty())){
                    //qDebug() << "Intenta Llenar 1";
                    primeraBandeja ->push(colaMounstro ->pop() ->data);
                }
                while(!(segundaBandeja -> isFull()) && !(colaMounstro ->isEmpty())){
                    //qDebug() << "Intenta Llenar 2";
                    segundaBandeja -> push(colaMounstro -> pop() -> data);
                }

                while(!(terceraBandeja -> isFull()) && !(colaMounstro ->isEmpty())){
                    //qDebug() << "Intenta Llenar 3";
                    terceraBandeja -> push(colaMounstro -> pop() -> data);
                }

                while(!(cuartaBandeja -> isFull()) && !(colaMounstro ->isEmpty())){
                    //qDebug() << "Intenta Llenar 4";
                    cuartaBandeja -> push(colaMounstro -> pop() -> data);
                }
            }

            if ((primeraBandeja -> isFull() && segundaBandeja -> isFull() && terceraBandeja -> isFull() && cuartaBandeja -> isFull())) {
                // Imprime mensaje cuando comienza el horneado
                qDebug() << "Horneado iniciado. Esperando" << this->sleepTime << "segundos.";

                // Pausa para simular el tiempo de horneado
                QThread::sleep(this->sleepTime);  // Espera this->sleepTime antes de empezar a mover mounstros a la colaCalidad

                // Imprime mensaje cuando termina el horneado
                //qDebug() << "Horneado terminado.";

                // Tengo que hornear solo los que no están bloqueados
                if(!(colaCalidad -> isFull())) {
                    while(!(primeraBandeja -> isEmpty()) && !isFirstBlocked) {
                        //qDebug() << "Quita primero";
                        Mounstro* mounstro = primeraBandeja -> pop() -> data;
                        mounstro -> bandejaHorneo = 1;
                        QDateTime currentDateTime = QDateTime::currentDateTime();
                        QDateTime beganOven = currentDateTime.addSecs(this->sleepTime);
                        mounstro ->finalHorneado = currentDateTime;
                        mounstro->inicioHorneado = beganOven;
                        mounstro -> isCooked = true;
                        colaCalidad -> push(mounstro);
                    }

                    while(!(segundaBandeja -> isEmpty()) && !isSecondBlocked) {
                        //qDebug() << "Quita segundo";
                        Mounstro* mounstro = segundaBandeja -> pop() -> data;
                        mounstro -> bandejaHorneo = 2;
                        QDateTime currentDateTime = QDateTime::currentDateTime();
                        QDateTime beganOven = currentDateTime.addSecs(this->sleepTime);
                        mounstro ->finalHorneado = currentDateTime;
                        mounstro->inicioHorneado = beganOven;
                        colaCalidad -> push(mounstro);
                    }

                    while(!(terceraBandeja -> isEmpty()) && !isThirdBlocked && !(colaCalidad->getIsFull())) {
                        //qDebug() << "Quita tercero";
                        Mounstro* mounstro = terceraBandeja -> pop() -> data;
                        mounstro -> bandejaHorneo = 3;
                        QDateTime currentDateTime = QDateTime::currentDateTime();
                        QDateTime beganOven = currentDateTime.addSecs(this->sleepTime);
                        mounstro ->finalHorneado = currentDateTime;
                        mounstro->inicioHorneado = beganOven;
                        colaCalidad -> push(mounstro);
                    }

                    while(!(cuartaBandeja -> isEmpty()) && !isFourthBlocked) {
                        //qDebug() << "Quita cuarto";
                        Mounstro* mounstro = cuartaBandeja -> pop() -> data;
                        mounstro -> bandejaHorneo = 4;
                        QDateTime currentDateTime = QDateTime::currentDateTime();
                        QDateTime beganOven = currentDateTime.addSecs(this->sleepTime);
                        mounstro -> finalHorneado = currentDateTime;
                        mounstro -> inicioHorneado = beganOven;
                        colaCalidad -> push(mounstro);
                    }
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

void Horno::changeFirstBlocked(int val){
    if(val == 0){
        this->isFirstBlocked = false;
    } else {
        this->isFirstBlocked = true;
    }
}

void Horno::changeSecondBlocked(int val){
    if(val == 0){
        this->isSecondBlocked = false;
    } else {
        this->isSecondBlocked = true;
    }
}

void Horno::changeThirdBlocked(int val){
    if(val == 0){
        this->isThirdBlocked = false;
    } else {
        this->isThirdBlocked = true;
    }
}

void Horno::changeFourthBlocked(int val){
    if(val == 0){
        this->isFourthBlocked = false;
    } else {
        this->isFourthBlocked = true;
    }
}





