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
        _Consecutivo += 1;
        QThread::sleep(this->sleepTime);
        if (!colaEnergia->isEmpty() && !colaMaldad->isEmpty() && !colaMateria->isEmpty() && !(colaMounstros->isFull())) {
            QString energia = this->colaEnergia->pop()->data->type;
            QString maldad = this->colaMaldad->pop()->data->type;
            QString materia = this->colaMateria->pop()->data->type;
            Mounstro* mounstro = new Mounstro(energia, materia, maldad);
            mounstro -> Creacion =  QDateTime::currentDateTime();
            //qDebug() << Consecutivo;
            mounstro->Consecutivo = _Consecutivo;
            if(mounstro->type != "Bueno"){
                this->colaMounstros->push(mounstro);
                readTextFiles* readingStructures = new readTextFiles();
                readingStructures->appendTextToFile("C:/Users/artur/OneDrive/Escritorio/ITCR/IIS2024/Estructuras de Datos/Proyectos/IC2001-MonsterFactory/MonsterFactory/Historicos/colaMounstros.txt",
                                                    mounstro->type + " Consecutivo: " + QString::number(mounstro->Consecutivo) + " Capacidad: " + QString::number(colaMounstros->maxCant)
                                                        + " Cantidad " + QString::number(colaMounstros ->cantItems));
            } else {
                // Va para el basurero
                this->basurero->incert(mounstro);
                //readTextFiles* readingStructures = new readTextFiles();
                //readingStructures->appendTextToFile("C:/Users/artur/OneDrive/Escritorio/ITCR/IIS2024/Estructuras de Datos/Proyectos/IC2001-MonsterFactory/MonsterFactory/Historicos/colaMounstros.txt", mounstro->type);

                //qDebug() << "Items en basurero: " <<basurero ->cantItems;
            }

            //qDebug() << "Combinado: " << energia << " " << materia << " " << maldad << " " << mounstro->type << " " << colaMounstros->getIsFull();
        } else {
            //qDebug() << "No hay suficientes elementos en las colas para combinar.";
        }
    }
}


void Combinador::changeTime(int time){
    this-> sleepTime = time;
}

void Combinador::stop(int val){
    if(val == 2){
        qDebug() << "Tengo que parar esta vara";
        this->running = false;
    } else {
        qDebug() << "La tengo que reanudar";
        this->running = true;
    }
}
