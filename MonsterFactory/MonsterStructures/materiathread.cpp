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
    this -> running = true;
    while(true){
        int secondsLeft = this->sleepTime;
        while(secondsLeft > 0){
            if(!this->running)
            {
                QThread::sleep(1);
                continue;
            }
            QThread::sleep(1);
            Materia* energia = new Materia();
            cola ->push(energia);
            //qDebug() << energia -> type;
        }
    }
}
