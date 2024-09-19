#include "labelthread.h"

LabelThread::LabelThread() {}

LabelThread::LabelThread(int sleepTime, Cola<Energia*>* colaEnergia, Cola<Maldad*>* colaMaldad, Cola<Materia*>* colaMateria) {
    this->sleepTime = sleepTime;
    this->running = true;
    this->colaEnergia = colaEnergia;
    this->colaMaldad = colaMaldad;
    this->colaMateria = colaMateria;
}


void LabelThread::run()
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
        }
        QString maxItemsEnergy = QString::number(colaEnergia->maxCant);
        QString cantItemsEnergy = QString::number(colaEnergia->getCantItems());
        energyLabel -> setText("Size Cola: " + maxItemsEnergy + " - " + "Cant Items Cola: " + cantItemsEnergy);

        QString maxItemsMaldad = QString::number(colaMaldad->maxCant);
        QString cantItemsMaldad = QString::number(colaMaldad->getCantItems());
        maldadLabel -> setText("Size Cola: " + maxItemsMaldad + " - " + "Cant Items Cola: " + cantItemsMaldad);

        QString maxItemsMateria = QString::number(colaMateria->maxCant);
        QString cantItemsMateria = QString::number(colaMateria->getCantItems());
        materiaLabel -> setText("Size Cola: " + maxItemsMateria + " - " + "Cant Items Cola: " + cantItemsMateria);
        //qDebug() << "Deberia de cambiar los label" << colaEnergia ->cantItems << " " << colaEnergia -> maxCant;
        //qDebug() << materia->type;
    }
}

void LabelThread::setEmergyLabel(QLabel* label){
    this->energyLabel = label;
}

void LabelThread::setMaldadLabel(QLabel* label){
    this->maldadLabel = label;
}

void LabelThread::setMateriaLabel(QLabel* label){
    this->materiaLabel = label;
}






