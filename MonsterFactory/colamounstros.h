#ifndef COLAMOUNSTROS_H
#define COLAMOUNSTROS_H

#include <QDialog>
#include "labelthread.h"
#include "DataStructures/cola.h"
#include "MonsterStructures/mounstro.h"

namespace Ui {
class ColaMounstros;
}

class ColaMounstros : public QDialog
{
    Q_OBJECT

public:
    explicit ColaMounstros(QWidget *parent = nullptr, Cola<Mounstro*>* colaMounstros = nullptr);
    ~ColaMounstros();
    void printColaMounstros();

private:
    Ui::ColaMounstros *ui;
    Cola<Mounstro*>* colaMounstros;
};

#endif // COLAMOUNSTROS_H
