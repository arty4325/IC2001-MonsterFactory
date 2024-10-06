#include "horno.h"
#include <QDateTime>
#include <QDebug>
#include "../ReadingStructures/readtextfiles.h"

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
            if((!(primeraBandeja -> isFull()) || !(segundaBandeja -> isFull()) || !(terceraBandeja ->isFull()) || !(cuartaBandeja->isFull()))){
                // Se ejecuta mientras se tienen que ir llenando las bandejas
                while(!(primeraBandeja -> isFull()) && !(colaMounstro ->isEmpty())){ // Mientras la primera bandeja no este llena
                    primeraBandeja ->push(colaMounstro ->pop() ->data); // Entonces procede a llenar la primera bandeja
                }
                while(!(segundaBandeja -> isFull()) && !(colaMounstro ->isEmpty())){ // Mientras la segunda bandeja no este llena
                    segundaBandeja -> push(colaMounstro -> pop() -> data); // Procede a llenar la segunda bandeja
                }

                while(!(terceraBandeja -> isFull()) && !(colaMounstro ->isEmpty())){ // Mientras la tercera bandeja no este llena
                    terceraBandeja -> push(colaMounstro -> pop() -> data); // Procede a llenar la tercera bandeja
                }

                while(!(cuartaBandeja -> isFull()) && !(colaMounstro ->isEmpty())){ // Mientras la cuarta bandeja no este llena
                    cuartaBandeja -> push(colaMounstro -> pop() -> data); // Procede a llenar la cuarta bandeja
                }
            }

            if ((primeraBandeja -> isFull() && segundaBandeja -> isFull() && terceraBandeja -> isFull() && cuartaBandeja -> isFull())) {
                // En el caso en que todas las bandejas esten llenas
                // Se comienza el horneo

                // Pausa para simular el tiempo de horneado
                QThread::sleep(this->sleepTime);  // Espera this->sleepTime antes de empezar a mover mounstros a la colaCalidad
                readTextFiles* readingStructures = new readTextFiles(); // Se llama a la estructura que permite manejar archivos ya que ocupo registrar esto en el itinerario
                if(!(colaCalidad -> isFull())) { // Mientras la ocla de calidad no este llena (Ya que los mounstros iran ahi)
                    while(!(primeraBandeja -> isEmpty()) && !isFirstBlocked) { // Mientras el primer bandeja no este lleno
                        //Quita el primer mounstro de la primera bandeja
                        Mounstro* mounstro = primeraBandeja -> pop() -> data;
                        mounstro -> bandejaHorneo = 1; // Se indica que se horneo en la primera bandeja
                        QDateTime currentDateTime = QDateTime::currentDateTime(); // Se obtiene el momento en el que se horneo
                        QDateTime beganOven = currentDateTime.addSecs(this->sleepTime); // Se le agregan los segundos que se supone se mantuvo horneandose
                        mounstro ->finalHorneado = currentDateTime; // Guarda cuando se termino de hornear
                        mounstro->inicioHorneado = beganOven; // guarda cuando se comenzo a hornear
                        mounstro -> isCooked = true; // marca en la casilla de que esta cocinado, que esta cocinado

                        readingStructures->appendTextToFile(
                            "C:/Users/artur/OneDrive/Escritorio/ITCR/IIS2024/Estructuras de Datos/Proyectos/IC2001-MonsterFactory/MonsterFactory/Historicos/hornoBitacora.txt",
                            mounstro->type +
                                " Consecutivo: " + QString::number(mounstro->Consecutivo) +
                                " Inicio: " + beganOven.toString("yyyy-MM-dd hh:mm:ss")  +
                                " Fin: " + currentDateTime.toString("yyyy-MM-dd hh:mm:ss") +
                                " Bandeja 1 "
                            ); // Se guarda toda la informacion pertinente al mounstro

                        colaCalidad -> push(mounstro); // Se adjunta esa informacion en la cola de calidad
                    }

                    // El proceso es totalmente analogo para el resto de bandejas
                    while(!(segundaBandeja -> isEmpty()) && !isSecondBlocked) {
                        Mounstro* mounstro = segundaBandeja -> pop() -> data;
                        mounstro -> bandejaHorneo = 2;
                        QDateTime currentDateTime = QDateTime::currentDateTime();
                        QDateTime beganOven = currentDateTime.addSecs(this->sleepTime);
                        mounstro ->finalHorneado = currentDateTime;
                        mounstro->inicioHorneado = beganOven;

                        readingStructures->appendTextToFile(
                            "C:/Users/artur/OneDrive/Escritorio/ITCR/IIS2024/Estructuras de Datos/Proyectos/IC2001-MonsterFactory/MonsterFactory/Historicos/hornoBitacora.txt",
                            mounstro->type +
                                " Consecutivo: " + QString::number(mounstro->Consecutivo) +
                                " Inicio: " + beganOven.toString("yyyy-MM-dd hh:mm:ss")  +
                                " Fin: " + currentDateTime.toString("yyyy-MM-dd hh:mm:ss") +
                                " Bandeja 2 "
                            );


                        colaCalidad -> push(mounstro);
                    }

                    while(!(terceraBandeja -> isEmpty()) && !isThirdBlocked && !(colaCalidad->getIsFull())) {
                        Mounstro* mounstro = terceraBandeja -> pop() -> data;
                        mounstro -> bandejaHorneo = 3;
                        QDateTime currentDateTime = QDateTime::currentDateTime();
                        QDateTime beganOven = currentDateTime.addSecs(this->sleepTime);
                        mounstro ->finalHorneado = currentDateTime;
                        mounstro->inicioHorneado = beganOven;

                        readingStructures->appendTextToFile(
                            "C:/Users/artur/OneDrive/Escritorio/ITCR/IIS2024/Estructuras de Datos/Proyectos/IC2001-MonsterFactory/MonsterFactory/Historicos/hornoBitacora.txt",
                            mounstro->type +
                                " Consecutivo: " + QString::number(mounstro->Consecutivo) +
                                " Inicio: " + beganOven.toString("yyyy-MM-dd hh:mm:ss")  +
                                " Fin: " + currentDateTime.toString("yyyy-MM-dd hh:mm:ss") +
                                " Bandeja 3 "
                            );


                        colaCalidad -> push(mounstro);
                    }

                    while(!(cuartaBandeja -> isEmpty()) && !isFourthBlocked) {
                        Mounstro* mounstro = cuartaBandeja -> pop() -> data;
                        mounstro -> bandejaHorneo = 4;
                        QDateTime currentDateTime = QDateTime::currentDateTime();
                        QDateTime beganOven = currentDateTime.addSecs(this->sleepTime);
                        mounstro -> finalHorneado = currentDateTime;
                        mounstro -> inicioHorneado = beganOven;

                        readingStructures->appendTextToFile(
                            "C:/Users/artur/OneDrive/Escritorio/ITCR/IIS2024/Estructuras de Datos/Proyectos/IC2001-MonsterFactory/MonsterFactory/Historicos/hornoBitacora.txt",
                            mounstro->type +
                                " Consecutivo: " + QString::number(mounstro->Consecutivo) +
                                " Inicio: " + beganOven.toString("yyyy-MM-dd hh:mm:ss")  +
                                " Fin: " + currentDateTime.toString("yyyy-MM-dd hh:mm:ss") +
                                " Bandeja 4 "
                            );


                        colaCalidad -> push(mounstro);
                    }
                }
            }

        }

    }
}

void Horno::changeTime(int time){ // Funcion permite cambiar el tiempo de horneado
    this-> sleepTime = time;
}

void Horno::changeMaxPrimeraBandeja(int time){ // Funcion permite cambiar la cantidad de mounstros que caben en la primera bandeja
    this -> primeraBandeja -> changeMax(time);
}

void Horno::changeMaxSegundaBandeja(int time){ // Funcion permite cambiar la cantidad de mounstros que caben en la segunda bandeja
    this -> segundaBandeja -> changeMax(time);
}

void Horno::changeMaxTerceraBandeja(int time){ // Funcion permite cambiar la cantidad de mounstros qeu caben en la tercera bandeja
    this -> terceraBandeja -> changeMax(time);
}

void Horno::changeMaxCuartaBandeja(int time){ // Funcion permite cambiar la cantidad de mounstros que caben en la cuarta bandeja
    this -> cuartaBandeja -> changeMax(time);
}

// Funciones para pausar bandejas
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

void Horno::stop(int val){ // Esto permite parar la aplicacion
    if(val == 2){
        // Se tiene que parar el combinador
        this->running = false;
    } else {
        // Se reanuda el combinador
        this->running = true;
    }
}





