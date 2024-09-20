#ifndef MONSTER_H
#define MONSTER_H
#include <QList>
#include <QDebug>
#include<QObject>
#include <QRandomGenerator>

class Mounstro
{
public:
    QString type;
    QString energia;
    QString material;
    QString maldad;
    bool isCooked;
    Mounstro(){
        type = "";
        energia = "";
        material = "";
        maldad = "";
        isCooked = false;
    }
    Mounstro(QString _energia, QString _material, QString _maldad){
        energia = _energia;
        material = _material;
        maldad = _maldad;
        if(energia == "Cosmica" && material == "Organico" && maldad == "Astuta"){
            type = "Inteligencia";
        } else if (energia == "Elemental" && material == "Radioactivo" && maldad == "Caotica"){
            type = "Destruccion";
        } else if (energia == "Oscura" && material == "Organico" && maldad == "Despiadada"){
            type = "Regeneracion";
        } else if (energia == "Elemental" && material == "Metalico" && maldad == "Despiadada"){
            type = "Fuerza";
        } else if (energia == "Oscura" && material == "Metalico" && maldad == "Astuta"){
            type = "Maldad";
        } else if (energia == "Oscura" && material == "Radioactivo" && maldad == "Despiadada"){
            type = "Veneno";
        } else if (energia == "Cosmica" && material == "Radioactivo" && maldad == "Caotica"){
            type = "Locura";
        } else if (energia == "Cosmica" && material == "Metalico" && maldad == "Astuta"){
            type = "Tecnologia";
        } else if (energia == "Elemental" && material == "Organico" && maldad == "Caotica"){
            type = "Velocidad";
        } else {
            type = "Bueno";
        }
    }
};

#endif // MONSTER_H
