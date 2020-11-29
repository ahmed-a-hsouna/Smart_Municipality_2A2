#ifndef MAINWINDOW_H
#define MAINWINDOW_H
/*#include<citoyent.h>
#include<commerciale.h>
*/

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();



/*private slots:


    void on_pushButton_11_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_21_clicked();

    void on_pushButton_33_clicked();

    void on_pushButton_clicked();

    void on_pushButton_40_clicked();

    void on_pushButton_43_clicked();

    void on_pushButton_42_clicked();

    void on_pushButton_44_clicked();

    void on_pushButton_chercherP_2_clicked();

    void on_pushButton_35_clicked();

    void on_pushButton_23_clicked();

    void on_pushButton_24_clicked();

    void on_pushButton_36_clicked();

    void on_pushButton_34_clicked();

    void on_afficher_commerciale_1_activated(const QModelIndex &index);

    void on_pushButton_6_clicked();

    void on_radioButton_11_clicked();

    void on_radioButton_13_clicked();

    void showTime(); */

private:
    Ui::MainWindow *ui;
    //citoyent temcitoyent;
    //commerciale tempcommerciale;
};
#endif // MAINWINDOW_H
