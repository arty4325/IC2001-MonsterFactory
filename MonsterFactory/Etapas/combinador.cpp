#include "combinador.h"
#include "../ReadingStructures/readtextfiles.h"


Combinador::Combinador() {}

Combinador::Combinador(int sleepTime,Cola<Mounstro*>* colaMounstros, ListaOrdenada<Mounstro*>* basurero ,Cola<Energia*>* colaEnergia, Cola<Maldad*>* colaMaldad ,Cola<Materia*>* colaMateria) {
    this->sleepTime = sleepTime;
    this->colaMounstros = colaMounstros;
    this->basurero = basurero;
    this->colaEnergia = colaEnergia;
    this->colaMaldad = colaMaldad;
    this->colaMateria = colaMateria;
    this->running = true;
}

void Combinador::run()
{
    this->running = true;

    while (true) {
        if (!this->running) {
            QThread::sleep(1);
            continue;
        }
        _Consecutivo += 1; // Se tiene una variable acumulada que funge como el consecutivo del mounstro
        QThread::sleep(this->sleepTime);
        if (!colaEnergia->isEmpty() && !colaMaldad->isEmpty() && !colaMateria->isEmpty() && !(colaMounstros->isFull())) {
            // En el caso de que haya elementos de energia, maldad, materia y que haya espacio para poner mas mounstros
            QString energia = this->colaEnergia->pop()->data->type; // Se toma el primer elemento en la cola de energia
            QString maldad = this->colaMaldad->pop()->data->type; // Se toma el primer elemento en la cola de maldad
            QString materia = this->colaMateria->pop()->data->type; // Se toma el primer elemento en la cola de materia
            Mounstro* mounstro = new Mounstro(energia, materia, maldad); // Y se le pasan como parametro al mounstro para poder crearlo
            mounstro -> Creacion =  QDateTime::currentDateTime(); // Para efectos de bitacora se toma el tiempo del sistema
            mounstro->Consecutivo = _Consecutivo; // Se le asigna el valor acumulado mencionado anteriormente al mounstro
            if(mounstro->type != "Bueno"){ // Si el mounstro no es bueno (Osea que debe de tramitarse)
                this->colaMounstros->push(mounstro); // Se coloca en una cola llamada cola mounstros
                readTextFiles* readingStructures = new readTextFiles(); // Se instancia el manejador de archivos para procesar esto
                readingStructures->appendTextToFile("C:/Users/artur/OneDrive/Escritorio/ITCR/IIS2024/Estructuras de Datos/Proyectos/IC2001-MonsterFactory/MonsterFactory/Historicos/colaMounstros.txt",
                                                    mounstro->type + " Consecutivo: " + QString::number(mounstro->Consecutivo) + " Capacidad: " + QString::number(colaMounstros->maxCant)
                                                        + " Cantidad " + QString::number(colaMounstros ->cantItems));
                // Se guarda la informacion pertinente a este mounstro
            } else {
                // Si se llega a este punto va para el basurero
                this->basurero->incert(mounstro);
                mounstro ->enBasurero = QDateTime::currentDateTime();
                // Hay una lista basurero en la que todos estos elementos son incertados
            }

        } else {
            // Cuando no hay suficientes elementos para poder generar un munstro, no se hace nada
        }
    }
}


void Combinador::changeTime(int time){ // Esto permite cambiar la cantidad de tiempo que toma generar cada mounstro
    this-> sleepTime = time;
}

void Combinador::stop(int val){ // Esto permite parar la aplicacion
    if(val == 2){
        // Se tiene que parar el combinador
        this->running = false;
    } else {
        // Se reanuda el combinador
        this->running = true;
    }
}
