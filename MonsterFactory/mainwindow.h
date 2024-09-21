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

    void on_maldadSpinBox_valueChanged(int arg1);

    void on_materiaSpinBox_valueChanged(int arg1);

    void on_energiaSpinBox_valueChanged(int arg1);

    void on_combinadorSpinBox_valueChanged(int arg1);

    void on_checkBox_stateChanged(int arg1);

    void on_checkBox_2_stateChanged(int arg1);

    void on_checkBox_3_stateChanged(int arg1);

    void on_checkBox_4_stateChanged(int arg1);

    void on_spinBox_valueChanged(int arg1);

    void on_spinBox_2_valueChanged(int arg1);

    void on_spinBox_3_valueChanged(int arg1);


    void on_hornoSpinBox_valueChanged(int arg1);

    void on_bandeja1CheckBox_stateChanged(int arg1);

    void on_bandeja2CheckBox_stateChanged(int arg1);

    void on_bandeja3CheckBox_stateChanged(int arg1);

    void on_bandeja4CheckBox_stateChanged(int arg1);

    void on_bandeja1SpinBox_valueChanged(int arg1);

    void on_bandeja2SpinBox_valueChanged(int arg1);

    void on_bandeja3SpinBox_valueChanged(int arg1);

    void on_bandeja4SpinBox_valueChanged(int arg1);

    void on_calidadSpinBox_valueChanged(int arg1);

    void on_bandeja2CheckBox_2_stateChanged(int arg1);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
