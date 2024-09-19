#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_button_test_clicked();

    void on_pushButton_clicked();

    void on_maldadSpinBox_valueChanged(double arg1);

    void on_maldadSpinBox_valueChanged(int arg1);

    void on_materiaSpinBox_valueChanged(int arg1);

    void on_energiaSpinBox_valueChanged(int arg1);

    void on_materiaSpinBox_2_valueChanged(int arg1);

    void on_combinadorSpinBox_valueChanged(int arg1);

    void on_checkBox_stateChanged(int arg1);

    void on_checkBox_2_stateChanged(int arg1);

    void on_checkBox_3_stateChanged(int arg1);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
