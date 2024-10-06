#ifndef ENERGIA_H
#define ENERGIA_H

#include <QList>
#include <QDebug>
#include<QObject>
#include <QRandomGenerator>

class Energia
{
public:
    QString type;
    int ranDes;
    Energia(){
        ranDes =  QRandomGenerator::global()->bounded(1, 4); // Esto permite obtener un numero random del 1 al 3 con el que se escogera una energia arbitraria
        if(ranDes == 1){
            type = "Oscura";
        } else if (ranDes == 2){
            type = "Cosmica";
        } else if (ranDes == 3){
            type = "Elemental";
        }
    }
};

#endif // ENERGIA_H
