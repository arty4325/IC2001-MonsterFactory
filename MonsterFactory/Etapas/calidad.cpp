#include "calidad.h"
#include "../ReadingStructures/readtextfiles.h"

Calidad::Calidad() {}

Calidad::Calidad(int sleepTime, Cola<Mounstro*>* colaCalidad, ListaOrdenada<Mounstro*>* basurero, Almacen* almacen) {
    this->sleepTime = sleepTime; // Constructor de calidad
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
    this->running = true; // Variable que permite que calidad este corriendo o no
    while(true) {
        int secondsLeft = this->sleepTime;
        while (secondsLeft > 0) {
            if (!this->running) {
                QThread::sleep(1);
                continue;
            }
            QThread::sleep(1);
            secondsLeft--;
            int randomVal1; // Se declaran dos variables que son las que van a tomar valores arbitrarios
            int randomVal2;
            randomVal1 =  QRandomGenerator::global()->bounded(1, 100); // Se utiliza la funcion QRandomGenerator para poder darle valores a esas funciones
            randomVal2 =  QRandomGenerator::global()->bounded(1, 100);
            readTextFiles* readingStructures = new readTextFiles(); // Se instancia el administrador de archivos por que se quiere posteriormente guardar la informacion de los inspectores
            if(!(colaCalidad ->isEmpty())){ // Solamente si hay elementos en la cola de calidad
                if(randomVal1 <= probsPrimerInspector ){ // Se ve si el valor arbitrario es menor al valor del inspector
                    if(!(colaCalidad ->isEmpty())) {
                        Mounstro* mounstro = colaCalidad -> pop() -> data;// Se obtiene el primer mounstro que esta en la cola de calidad
                        mounstro -> inspectorRevisor = 1; // Se le dice a este mounstro que esta siendo revisado por el primer inspector
                        mounstro -> fueRechazado = true; // Y como en este caso fue rechazado, se indica en la variable
                        readingStructures ->appendTextToFile("C:/Users/artur/OneDrive/Escritorio/ITCR/IIS2024/Estructuras de Datos/Proyectos/IC2001-MonsterFactory/MonsterFactory/Historicos/primerInspector.txt",
                                                            mounstro->type + " Consecutivo: " + QString::number(mounstro->Consecutivo) + " Rechazado ");
                        // En el administrador de textos se guarda la informacion del itinerario de este inspector
                        basurero -> incert(mounstro); // Y este mounstro se va para el basurero ya que fue rechazado por este inspector
                    }

                } else {
                    // Si llega a este punto es que el mounstro fue aceptado por el primer inspector, y debe de ir al segundo
                    if(!(colaCalidad->isEmpty())){
                        Mounstro* mounstro = colaCalidad -> peck() -> data;
                        readingStructures ->appendTextToFile("C:/Users/artur/OneDrive/Escritorio/ITCR/IIS2024/Estructuras de Datos/Proyectos/IC2001-MonsterFactory/MonsterFactory/Historicos/primerInspector.txt",
                                                            mounstro->type + " Consecutivo: " + QString::number(mounstro->Consecutivo) + " Aceptado ");
                    }
                    // Lo mencionado anteriormente debe de ser guardado en el archivo de itinerario

                }

                if(!(randomVal1 <= probsPrimerInspector)) {
                    if(randomVal2 <= probsSegundoInspector){
                        // Si se llega aqui quiere decir que el segundo inspector rechazo el pedido
                        if(!(colaCalidad ->isEmpty())) { // Si hay elementos en la cola de calidad
                            Mounstro* mounstro = colaCalidad -> pop() -> data; // Se obtiene el mounstro que esta encolado
                            mounstro -> inspectorRevisor = 2; // Se le indica al sistema que el segundo inspector reviso a este mounstro
                            mounstro -> fueRechazado = true; // Y se indica que este mounstro fue rechazado
                            readingStructures ->appendTextToFile("C:/Users/artur/OneDrive/Escritorio/ITCR/IIS2024/Estructuras de Datos/Proyectos/IC2001-MonsterFactory/MonsterFactory/Historicos/segundoInspector.txt",
                                                                mounstro->type + " Consecutivo: " + QString::number(mounstro->Consecutivo) + " Rechazado ");
                            // El evento tiene que ser guardado en el itinerario
                            basurero -> incert(mounstro); // En el basurero se guarda el mounstro
                        }
                    } else {
                        // Si se llega a este punto quiere decir que me quede definitivamente con el mounstro y este continua el proceso de fabricacion
                        if(!(colaCalidad->isEmpty())){
                            Mounstro* mounstro = colaCalidad -> peck() -> data; // Se saca de la cola
                            readingStructures ->appendTextToFile("C:/Users/artur/OneDrive/Escritorio/ITCR/IIS2024/Estructuras de Datos/Proyectos/IC2001-MonsterFactory/MonsterFactory/Historicos/segundoInspector.txt",
                                                                mounstro->type + " Consecutivo: " + QString::number(mounstro->Consecutivo) + " Aceptado ");
                        }
                        // Se escribe este evento en el archivo de itinerario
                        almacen -> incertAlmacen(colaCalidad -> pop() -> data); // Y este mounstro tiene que ir ahora al almacen

                    }
                }
            }
        }

    }
}

void Calidad::changeFirstProbability(int val){ // Esto permite cambiar en tiempo real la probabilidad de rechazo del primer inspector
    this->probsPrimerInspector = val;
}

void Calidad::changeSecondProbability(int val){ // Permite cambiar en tiempo real la probabilidad de rechazo del segundo inspector
    this->probsSegundoInspector = val;
}

void Calidad::stop(int val){
    if(val == 2){
        // Se para el programa
        this->running = false;
    } else {
        // Se reanunda el programa
        this->running = true;
    }
}
