#ifndef FENETRE_H
#define FENETRE_H
#include <QDialog>
#include <QString>
#include <QSqlQueryModel>
#include "certifdeces.h"
#include "permisconstr.h"
#include <QFileDialog>
#include <QTimer>
#include <QTime>
#include <QPainter>
#include <QSound>
#include <QEventTransition>
#include<QPropertyAnimation>
#include<QParallelAnimationGroup>

namespace Ui {
class Fenetre;
}
class QSystemTrayIcon ;
class Fenetre : public QDialog
{
    Q_OBJECT

public:
    explicit Fenetre(QWidget *parent = nullptr);
    ~Fenetre();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_ajouter_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_19_clicked();

    void on_pushButton_20_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_18_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_21_clicked();

    void on_tableView_2_activated(const QModelIndex &index);

    void on_tableView_activated(const QModelIndex &index);

private:
    Ui::Fenetre *ui;
    Certifdeces tempcert;
    permisconstr temppermis;
   
};

#endif // FENETRE_H
