#include "combinador.h"


Combinador::Combinador() {}

Combinador::Combinador(int sleepTime,Cola<Mounstro*>* colaMounstros ,Cola<Energia*>* colaEnergia, Cola<Maldad*>* colaMaldad ,Cola<Materia*>* colaMateria) {
    this->sleepTime = sleepTime;
    this->colaMounstros = colaMounstros;
    this->colaEnergia = colaEnergia;
    this->colaMaldad = colaMaldad;
    this->colaMateria = colaMateria;
    this->running = true;
}

void Combinador::run()
{
    this->running = true;
    while (true) {
        int secondsLeft = this->sleepTime;

        while (secondsLeft > 0) {
            if (!this->running) {
                QThread::sleep(1);
                continue;
            }

            QThread::sleep(1);
            secondsLeft--;

            if (!colaEnergia->isEmpty() && !colaMaldad->isEmpty() && !colaMateria->isEmpty()) {

                QString energia = this->colaEnergia->pop()->data->type;
                QString maldad = this->colaMaldad->pop()->data->type;
                QString materia = this->colaMateria->pop()->data->type;

                Mounstro* mounstro = new Mounstro(energia, materia, maldad);
                this->colaMounstros->push(mounstro);

                qDebug() << "Combinado: " << energia << " " << materia << " " << maldad << " " << mounstro -> type;
            } else {
                qDebug() << "No hay suficientes elementos en las colas para combinar.";
            }
        }
    }
}

