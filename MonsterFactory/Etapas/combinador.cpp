#include "combinador.h"


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
            //qDebug() << Consecutivo;
            mounstro->Consecutivo = _Consecutivo;
            if(mounstro->type != "Bueno"){
                this->colaMounstros->push(mounstro);
            } else {
                // Va para el basurero
                this->basurero->incert(mounstro);
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
