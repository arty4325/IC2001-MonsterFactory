#include "materiathread.h"
#include "materia.h"


MateriaThread::MateriaThread() {}

MateriaThread::MateriaThread(int sleepTime, Cola<Materia*>* cola) {
    this->sleepTime = sleepTime;
    this->cola = cola;
    this->running = true;
}


void MateriaThread::run()
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

        Materia* materia = new Materia();
        cola->push(materia);
        //qDebug() << materia->type;
    }
}


void MateriaThread::changeTime(int time){
    this-> sleepTime = time;
}
