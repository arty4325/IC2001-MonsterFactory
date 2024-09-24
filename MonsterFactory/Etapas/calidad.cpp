#include "calidad.h"

Calidad::Calidad() {}

Calidad::Calidad(int sleepTime, Cola<Mounstro*>* colaCalidad, ListaOrdenada<Mounstro*>* basurero, Almacen* almacen) {
    this->sleepTime = sleepTime;
    this->running = true;
    this->probsPrimerInspector = 20;
    this->probsSegundoInspector = 20;
    this->colaCalidad = colaCalidad;
    this->basurero = basurero;
    this->almacen = almacen;
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
            //() << "Debo de ver calidad";
            int randomVal1;
            int randomVal2;
            randomVal1 =  QRandomGenerator::global()->bounded(1, 100);
            randomVal2 =  QRandomGenerator::global()->bounded(1, 100);

            if(!(colaCalidad ->isEmpty())){

                if(randomVal1 <= probsPrimerInspector ){
                    //qDebug() << "Bota el mounstro";
                    if(!(colaCalidad ->isEmpty())) {
                        Mounstro* mounstro = colaCalidad -> pop() -> data;
                        basurero -> incert(mounstro);
                    }

                } else {
                    //qDebug() << "MOSTRO VA PARA SEGUNDO INSPECTOR";
                }

                if(!(randomVal1 <= probsPrimerInspector)) {
                    if(randomVal2 <= probsSegundoInspector){
                        //qDebug() << "bota el mostro segundo inspector";
                        if(!(colaCalidad ->isEmpty())) {
                            Mounstro* mounstro = colaCalidad -> pop() -> data;
                            basurero -> incert(mounstro);
                        }
                    } else {
                        //qDebug() << "ME QUEDO DEFINITIVAMENTE CON EL MOUNSTRO";
                        almacen -> incertAlmacen(colaCalidad -> pop() -> data);
                    }
                }
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
        //qDebug() << "Tengo que parar esta vara";
        this->running = false;
    } else {
        //qDebug() << "La tengo que reanudar";
        this->running = true;
    }
}
