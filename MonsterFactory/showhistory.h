#ifndef SHOWHISTORY_H
#define SHOWHISTORY_H

#include <QDialog>

namespace Ui {
class ShowHistory;
}

class ShowHistory : public QDialog
{
    Q_OBJECT

public:
    explicit ShowHistory(QWidget *parent = nullptr);
    ~ShowHistory();
    void printData(QString var);

private:
    Ui::ShowHistory *ui;
};

#endif // SHOWHISTORY_H
