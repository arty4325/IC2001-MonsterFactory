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

        Materia* materia = new Materia(); // Instancia un objeto de materia
        cola->push(materia); // Pone ese objeto en la cola
    }
}


void MateriaThread::changeTime(int time){
    this-> sleepTime = time;
}


void MateriaThread::stop(int val){
    if(val == 2){
        this->running = false;
    } else {
        this->running = true;
    }
}
