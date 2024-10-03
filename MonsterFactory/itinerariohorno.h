#ifndef ITINERARIOHORNO_H
#define ITINERARIOHORNO_H

#include <QDialog>
#include <QDialog>
#include "labelthread.h"
#include "DataStructures/cola.h"
#include "MonsterStructures/mounstro.h"


namespace Ui {
class ItinerarioHorno;
}

class ItinerarioHorno : public QDialog
{
    Q_OBJECT

public:
    explicit ItinerarioHorno(QWidget *parent = nullptr, Cola<Mounstro*>* primeraBandeja = nullptr, Cola<Mounstro*>* segundaBandeja = nullptr
                             , Cola<Mounstro*>* terceraBandeja = nullptr, Cola<Mounstro*>* cuartaBandeja = nullptr);
    ~ItinerarioHorno();
    void printHorno();

private:
    Ui::ItinerarioHorno *ui;
    Cola<Mounstro*>* primeraBandeja;
    Cola<Mounstro*>* segundaBandeja;
    Cola<Mounstro*>* terceraBandeja;
    Cola<Mounstro*>* cuartaBandeja;
};

#endif // ITINERARIOHORNO_H
