#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "employer.h"
#include <QMainWindow>
#include "departement.h"
#include <QPushButton>
#include <QSound>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
int  getselectedEmploye();
int getselectedDepartement();
employe z;
departement d;
private slots:


    void on_pushButton_ajouteremploye_clicked();

    void on_pushButton_24_clicked();

    void on_pushButton_ajouteremploye_3_clicked();

    /*void on_pushButton_ajouteremploye_2_clicked();*/

    /*void on_radioButton_clicked();*/

    void on_pushButton_clicked();

    void on_pushButton_21_clicked();

    void on_pushButton_26_clicked();

    void on_pushButton_30_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_22_clicked();

private:
    Ui::MainWindow *ui;
    QSound *son;
};
#endif // MAINWINDOW_H
