#include "calidad.h"
#include "../ReadingStructures/readtextfiles.h"

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
            readTextFiles* readingStructures = new readTextFiles();
            if(!(colaCalidad ->isEmpty())){

                if(randomVal1 <= probsPrimerInspector ){
                    //qDebug() << "Bota el mounstro";
                    if(!(colaCalidad ->isEmpty())) {
                        Mounstro* mounstro = colaCalidad -> pop() -> data;
                        mounstro -> inspectorRevisor = 1;
                        mounstro -> fueRechazado = true;
                        readingStructures ->appendTextToFile("C:/Users/artur/OneDrive/Escritorio/ITCR/IIS2024/Estructuras de Datos/Proyectos/IC2001-MonsterFactory/MonsterFactory/Historicos/primerInspector.txt",
                                                            mounstro->type + " Consecutivo: " + QString::number(mounstro->Consecutivo) + " Rechazado ");
                        basurero -> incert(mounstro);
                    }

                } else {
                    //qDebug() << "MOSTRO VA PARA SEGUNDO INSPECTOR";
                    // AQUI GUARDAR INFO PRIMER INSPECTOR PARA CUANDO SE APROBO MOSTRO
                    if(!(colaCalidad->isEmpty())){
                        Mounstro* mounstro = colaCalidad -> peck() -> data;
                        readingStructures ->appendTextToFile("C:/Users/artur/OneDrive/Escritorio/ITCR/IIS2024/Estructuras de Datos/Proyectos/IC2001-MonsterFactory/MonsterFactory/Historicos/primerInspector.txt",
                                                            mounstro->type + " Consecutivo: " + QString::number(mounstro->Consecutivo) + " Aceptado ");
                    }

                }

                if(!(randomVal1 <= probsPrimerInspector)) {
                    if(randomVal2 <= probsSegundoInspector){
                        //qDebug() << "bota el mostro segundo inspector";
                        if(!(colaCalidad ->isEmpty())) {
                            Mounstro* mounstro = colaCalidad -> pop() -> data;
                            mounstro -> inspectorRevisor = 2;
                            mounstro -> fueRechazado = true;
                            readingStructures ->appendTextToFile("C:/Users/artur/OneDrive/Escritorio/ITCR/IIS2024/Estructuras de Datos/Proyectos/IC2001-MonsterFactory/MonsterFactory/Historicos/segundoInspector.txt",
                                                                mounstro->type + " Consecutivo: " + QString::number(mounstro->Consecutivo) + " Rechazado ");
                            basurero -> incert(mounstro);
                        }
                    } else {
                        //qDebug() << "ME QUEDO DEFINITIVAMENTE CON EL MOUNSTRO";
                        if(!(colaCalidad->isEmpty())){
                            Mounstro* mounstro = colaCalidad -> peck() -> data;
                            readingStructures ->appendTextToFile("C:/Users/artur/OneDrive/Escritorio/ITCR/IIS2024/Estructuras de Datos/Proyectos/IC2001-MonsterFactory/MonsterFactory/Historicos/segundoInspector.txt",
                                                                mounstro->type + " Consecutivo: " + QString::number(mounstro->Consecutivo) + " Aceptado ");
                        }
                        almacen -> incertAlmacen(colaCalidad -> pop() -> data);

                        // Como para el almacen, en tiempo real la aplicacion tiene que mostrar si esta en el almacen o no
                        // Vamos a... hacer el archivo de almacen cuando se toca el boton.

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
