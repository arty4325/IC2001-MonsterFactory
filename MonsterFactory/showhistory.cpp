#include "showhistory.h"
#include "ui_showhistory.h"

ShowHistory::ShowHistory(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ShowHistory)
{
    ui->setupUi(this);
}

ShowHistory::~ShowHistory()
{
    delete ui;
}


void ShowHistory::printData(QString var){
    ui->historyLabel->setText(var);
}


/**
void ColaMounstros::printColaMounstros(){
    QString var = "";
    for(int i = 0; i < colaMounstros->getCantItems(); i++ ){
        var += colaMounstros->getElementoEnIndice(i)->type + "\n";
    }
    ui->infoColaMounstros->setText(var);
}
**/
