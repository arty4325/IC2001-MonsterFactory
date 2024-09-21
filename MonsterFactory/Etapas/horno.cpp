#include "horno.h"


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

            if ((primeraBandeja -> isFull() && segundaBandeja -> isFull() && terceraBandeja -> isFull() && cuartaBandeja -> isFull())){
                qDebug() << "Horneo lets fucking go";
                qDebug() << "info" << primeraBandeja -> isFull() << segundaBandeja -> isFull() << terceraBandeja -> isFull() << cuartaBandeja -> isFull() << colaCalidad -> isFull();
                // Tengo que hornear solo los que no esta bloqueado PARA CUANDO LLEGA A ESTE PUNTO
                // Puedo hacer una estructura bastante similar a la que tenia cuando estaba armando las colas
                if(!(colaCalidad -> isFull())){
                    while(!(primeraBandeja -> isEmpty()) && !isFirstBlocked){
                        qDebug() << "Quita primero";
                        Mounstro* mounstro = primeraBandeja -> pop() -> data;
                        mounstro -> isCooked = true;
                        colaCalidad -> push(mounstro);
                    }

                    while(!(segundaBandeja -> isEmpty()) && !isSecondBlocked){
                        qDebug() << "Quita segundo";
                        Mounstro* mounstro = segundaBandeja -> pop() -> data;
                        mounstro -> isCooked = true;
                        colaCalidad -> push(mounstro);
                    }

                    while(!(terceraBandeja -> isEmpty()) && !isThirdBlocked && !(colaCalidad->getIsFull())){
                        qDebug() << "Quita tercero";
                        Mounstro* mounstro = terceraBandeja -> pop() -> data;
                        mounstro -> isCooked = true;
                        colaCalidad -> push(mounstro);
                    }

                    while(!(cuartaBandeja -> isEmpty()) && !isFourthBlocked){
                        qDebug() << "Quita cuarto";
                        Mounstro* mounstro = cuartaBandeja -> pop() -> data;
                        mounstro -> isCooked = true;
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





