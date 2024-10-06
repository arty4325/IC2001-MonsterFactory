#ifndef MATERIA_H
#define MATERIA_H
#include <QList>
#include <QDebug>
#include<QObject>
#include <QRandomGenerator>


class Materia
{
public:
    QString type;
    int ranDes;
    Materia(){
        ranDes =  QRandomGenerator::global()->bounded(1, 4); // Esto permite obtener un numero random del 1 al 3 con el que se escogera una materia arbitraria
        if(ranDes == 1){
            type = "Organico";
        } else if (ranDes == 2){
            type = "Metalico";
        } else if (ranDes == 3){
            type = "Radioactivo";
        }
    }
};


#endif // MATERIA_H
