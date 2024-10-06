#ifndef MALDAD_H
#define MALDAD_H

#include <QList>
#include <QDebug>
#include<QObject>
#include <QRandomGenerator>


class Maldad
{
public:
    QString type;
    int ranDes;
    Maldad(){
        ranDes = QRandomGenerator::global() -> bounded(1, 4); // Esto permite obtener un numero random del 1 al 3 con el que se escogera una maldad arbitraria
        if(ranDes == 1){
            type = "Despiadada";
        } else if (ranDes == 2){
            type = "Astuta";
        } else if (ranDes == 3){
            type = "Caotica";
        }
    }

};




#endif // MALDAD_H
