#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "contrat.h"
#include <QMainWindow>
#include "fourriere.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:


    void on_pushButton_11_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_33_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_17_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_43_clicked();

    void on_pushButton_chercherP_5_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_42_clicked();

    void on_pushButton_chercherP_4_clicked();

    void on_pushButton_18_clicked();

    void on_pushButton_39_clicked();

    void on_pushButton_clicked();

    void on_pushButton_35_clicked();

private:
    Ui::MainWindow *ui;
    contrat tempcontrat;
    fourriere tempfourriere;
};
#endif // MAINWINDOW_H
