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
        ranDes =  QRandomGenerator::global()->bounded(1, 4);
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
