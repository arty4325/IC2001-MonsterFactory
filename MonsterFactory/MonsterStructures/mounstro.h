#ifndef MONSTER_H
#define MONSTER_H
#include <QList>
#include <QDebug>
#include<QObject>
#include <QRandomGenerator>
#include <QDateTime>
#include <QDebug>

class Mounstro
{
public:
    QString type;
    QString energia;
    QString material;
    QString maldad;
    bool isCooked;
    int Consecutivo;
    QDateTime Creacion;
    QDateTime inicioHorneado;
    QDateTime finalHorneado;
    int bandejaHorneo;
    int inspectorRevisor;
    bool fueRechazado;
    bool enAlmacen;
    QString cliente;
    QDateTime tiempoEntrega;
    QString pedido;

    Mounstro(){
        type = "";
        energia = "";
        material = "";
        maldad = "";
        isCooked = false;
        Consecutivo = 0;
        inicioHorneado = QDateTime();
        finalHorneado = QDateTime();
        Creacion = QDateTime::currentDateTime();
        bandejaHorneo = -1;
        inspectorRevisor = -1;
        fueRechazado = false;
        enAlmacen = false;
        cliente = "";
        tiempoEntrega = QDateTime();

    }
    Mounstro(QString _energia, QString _material, QString _maldad){ // Se toma la materia creada y se van creando los mounstros
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
