#include "showhistory.h"
#include "ui_showhistory.h"

ShowHistory::ShowHistory(QWidget *parent) // permite ver los hitoriales
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
    ui->historyLabel->setText(var); // Toma un strign y lo muestra
}
