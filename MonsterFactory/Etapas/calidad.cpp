#include "calidad.h"

Calidad::Calidad() {}

Calidad::Calidad(int sleepTime) {
    this->sleepTime = sleepTime;
    this->running = true;
    this->probsPrimerInspector = 20;
    this->probsSegundoInspector = 20;
    //this->queueLabel;
}

void Calidad::run()
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
            qDebug() << "Debo de ver calidad";
            int randomVal1;
            int randomVal2;
            randomVal1 =  QRandomGenerator::global()->bounded(1, 100);
            randomVal2 =  QRandomGenerator::global()->bounded(1, 100);


            if(randomVal1 <= probsPrimerInspector ){
                qDebug() << "Bota el mounstro";
            } else {
                qDebug() << "Me quedo el mostro";
            }

            if(randomVal2 <= probsSegundoInspector){
                qDebug() << "bota el mostro segundo inspector";
            } else {
                qDebug() << "me quedo el mostro segundo inspector";
            }
        }

    }
}

void Calidad::changeFirstProbability(int val){
    this->probsPrimerInspector = val;
}

void Calidad::changeSecondProbability(int val){
    this->probsSegundoInspector = val;
}

void Calidad::stop(int val){
    if(val == 2){
        qDebug() << "Tengo que parar esta vara";
        this->running = false;
    } else {
        qDebug() << "La tengo que reanudar";
        this->running = true;
    }
}
