#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QTextEdit>
#include<QSqlQueryModel>
#include <QSqlQuery>
#include <QMessageBox>
#include <QDebug>
#include <QSqlError>
#include "ui_mainwindow.h"
#include <QMessageBox>
#include "employer.h"
#include "departement.h"
#include <QTableView>
#include<QtPrintSupport/QPrinter>
#include<QPrinter>
#include<QPainter>
#include <QPdfWriter>
#include <QTextStream>
#include <QFileDialog>
#include <QTextDocument>
#include <QPrintDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)

{
ui->setupUi(this);
ui->tableView_employes->setModel(z.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_ajouteremploye_clicked()
{
    int CIN = ui->lineEdit_CIN->text().toInt();

        QString nom=ui->lineEdit_nom->text();
        QString prenom = ui->lineEdit_prenom->text();
        int num = ui->lineEdit_numero->text().toInt();
        QString adresse = ui->lineEdit_adresse->text();

        employe z (CIN,nom,prenom,num,adresse);
        bool test = z.ajouter();
        if(test)
        {
            ui->tableView_employes->setModel(z.afficher());

        QMessageBox::information(nullptr,QObject::tr("ajouter un employé"),QObject::tr("employé ajouté. \n ""click cancel to exit."),QMessageBox::Cancel);
        }
        ui->lineEdit_CIN->clear();
        ui->lineEdit_nom->clear();
        ui->lineEdit_prenom->clear();
        ui->lineEdit_numero->clear();
        ui->lineEdit_adresse->clear();




    }

int MainWindow::getselectedEmploye()
{
int s=ui->tableView_employes->selectionModel()->currentIndex().row();
QModelIndex index =ui->tableView_employes->model()->index(s, 0,QModelIndex());
int aff=ui->tableView_employes->model()->data(index).toString().toInt();
return aff;
}
int MainWindow::getselectedDepartement()
{
int s=ui->tableView_depart->selectionModel()->currentIndex().row();
QModelIndex index =ui->tableView_depart->model()->index(s, 0,QModelIndex());
int aff=ui->tableView_depart->model()->data(index).toString().toInt();
return aff;
}
void MainWindow::on_pushButton_24_clicked()
{
    int k=getselectedEmploye();
    //int CIN= ui->lineEdit_supprimer->text().toInt();
    bool test=z.supprimer(k);

        if(test){
           ui->tableView_employes->setModel(z.afficher());
           QMessageBox::information(nullptr, QObject::tr("tout a ete supprimé avec succés"),
                       QObject::tr("employe a ete supprimé avec succés.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);


         }
         else
             QMessageBox::critical(nullptr, QObject::tr("problem supprimer"),
                         QObject::tr("connection failed.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);

     }




/*void MainWindow::on_pushButton_ajouteremploye_3_clicked()
{
}
void MainWindow::on_pushButton_ajouteremploye_2_clicked()
{

}
*/

void MainWindow::on_pushButton_10_clicked()
{
    employe c(ui->lineEdit_CIN->text().toInt(),ui->lineEdit_nom->text(),ui->lineEdit_prenom->text(),ui->lineEdit_numero->text().toInt(),ui->lineEdit_adresse->text());
        c.modifier(getselectedEmploye());
         ui->tableView_employes->setModel(z.afficher());
        ui->lineEdit_CIN->setText("");
         ui->lineEdit_nom->setText("");
         ui->lineEdit_prenom->setText("");
         ui->lineEdit_numero->setText("");
         ui->lineEdit_adresse->setText("");

}

void MainWindow::on_pushButton_22_clicked()
{
    int id = ui->id_dep_2->text().toInt();
     int nbre = ui->lineEdit_nbrdesemployes_2->text().toInt();
      int bud = ui->lineEdit_budget_2->text().toInt();
        QString nomd=ui->lineEdit_nomdep_2->text();




        departement d (id ,nomd,nbre,bud);
        bool test = d.ajouter();
        if(test)
        {
            ui->tableView_depart->setModel(d.afficher());

        QMessageBox::information(nullptr,QObject::tr("ajouter un departement"),QObject::tr("departement ajouté. \n ""click cancel to exit."),QMessageBox::Cancel);
        }
        ui->id_dep_2->clear();
        ui->lineEdit_nbrdesemployes_2->clear();
        ui->lineEdit_budget_2->clear();
        ui->lineEdit_nomdep_2->clear();


}

void MainWindow::on_pushButton_26_clicked()
{
    //int k=getselectedDepartement();
    int id_dep= ui->id_dep_2->text().toInt();
    bool test=d.supprimer(id_dep);

        if(test){
           ui->tableView_depart->setModel(d.afficher());
           QMessageBox::information(nullptr, QObject::tr("tout a ete supprimé avec succés"),
                       QObject::tr("departement a ete supprimé avec succés.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);


         }
         else
             QMessageBox::critical(nullptr, QObject::tr("problem supprimer"),
                         QObject::tr("connection failed.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_pushButton_30_clicked()
{departement d(ui->id_dep_2->text().toInt(),ui->lineEdit_nomdep_2->text(),ui->lineEdit_nbrdesemployes_2->text().toInt(),ui->lineEdit_budget_2->text().toInt());
    d.modifier();
     ui->tableView_depart->setModel(d.afficher());
    ui->id_dep_2->setText("");
     ui->lineEdit_nomdep_2->setText("");
     ui->lineEdit_nbrdesemployes_2->setText("");
     ui->lineEdit_budget_2->setText("");


}

void MainWindow::on_pushButton_2_clicked()
{
    bool test=d.supprimerTout();

    QMessageBox::StandardButton reply =QMessageBox::information(this,"supprimer la liste","Etes-vous sur?",QMessageBox::Yes|QMessageBox::No);

        if(reply == QMessageBox::Yes){
    if(test){
         ui->tableView_depart->setModel(d.afficher());
        QMessageBox::information(nullptr, QObject::tr("tout a ete supprimé avec succés"),
                    QObject::tr("tout a ete supprimé avec succés.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("problem supprimer"),
                    QObject::tr("connection failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

   }

}

void MainWindow::on_pushButton_3_clicked()
{
    QString filename="fichier.pdf";
         //Settings
         QPrinter printer;
         printer.setOrientation(QPrinter::Landscape);


          printer.setOutputFileName("D:/amine/Desktop/PDF/fichier.pdf");
         printer.setPaperSize(QPrinter::A4);
         printer.setOutputFormat(QPrinter::PdfFormat);

         QPainter painter(&printer);
         painter.setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing | QPainter::SmoothPixmapTransform);
         ui->tableView_depart->render(&painter );

         painter.end();
         QMessageBox::information(this,tr("Exported!"),tr("Equipements list is now availble in pdf format "));
}

void MainWindow::on_pushButton_5_clicked()
{ bool test=z.supprimerTout();

    QMessageBox::StandardButton reply =QMessageBox::information(this,"supprimer la liste","Etes-vous sur?",QMessageBox::Yes|QMessageBox::No);

        if(reply == QMessageBox::Yes){
    if(test){
         ui->tableView_employes->setModel(z.afficher());
        QMessageBox::information(nullptr, QObject::tr("tout a ete supprimé avec succés"),
                    QObject::tr("tout a ete supprimé avec succés.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("problem supprimer"),
                    QObject::tr("connection failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

   }

}

void MainWindow::on_pushButton_4_clicked()
{
    /*QString filename="fichier.pdf";
         //Settings
         QPrinter printer;
         printer.setOrientation(QPrinter::Landscape);


          printer.setOutputFileName("D:/amine/Desktop/PDF/emp/fichier.pdf");
         printer.setPaperSize(QPrinter::A4);
         printer.setOutputFormat(QPrinter::PdfFormat);

         QPainter painter(&printer);
         painter.setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing | QPainter::SmoothPixmapTransform);
         ui->tableView_employes->render(&painter );

         painter.end();
         QMessageBox::information(this,tr("Exported!"),tr("Equipements list is now availble in pdf format "));*/
/*QPrinter printer;


    QString filename="fichier.pdf";

    printer.setOrientation(QPrinter::Landscape);


     printer.setOutputFileName("D:/amine/Desktop/PDF/emp/fichier.pdf");
    printer.setPaperSize(QPrinter::A4);
    printer.setOutputFormat(QPrinter::PdfFormat);*/

                    int CIN= ui ->lineEdit_CIN->text().toInt() ;
                    QString nom= ui ->lineEdit_nom->text() ;
                    QString prenom= ui ->lineEdit_prenom->text() ;
                    int num= ui->lineEdit_numero->text().toInt();
                    QString adresse=ui->lineEdit_adresse->text();

                    QString CINs=QString::number(CIN);
                    QString nums=QString::number(num);

                    QString pdf_name= "employe_"+nom+"_"+prenom+".pdf";
                    QPdfWriter pdf(pdf_name);
                    QPainter painter(&pdf);

                    painter.drawPixmap(QRect(7600,70,2000,2600),QPixmap("D:/amine/Desktop/Ra7/Ra7.png"));
                                          painter.drawRect(0,3000,9600,500);

                    painter.setPen(Qt::blue);
                    painter.drawText(3000,1500,"DEV SPACE");

                    painter.setPen(Qt::black);
                    painter.drawText(100,2600,"CIN : ");
                    painter.setPen(Qt::black);
                    painter.drawText(2000,2600,CINs);
                    painter.setPen(Qt::blue);
                    painter.drawText(100,2300,"Nom : ");
                    painter.setPen(Qt::black);
                    painter.drawText(2000,2300,nom);
                    painter.drawText(100,2900,"Prenom : ");
                    painter.setPen(Qt::black);
                    painter.drawText(2000,2900,prenom);
                    painter.setPen(Qt::blue);

                    painter.setPen(Qt::blue);
                    painter.drawText(100,3200,"numero : ");
                    painter.setPen(Qt::black);
                    painter.drawText(2000,3200,nums);
                    painter.setPen(Qt::blue);
                    painter.drawText(100,3500,"Adresse : ");
                    painter.setPen(Qt::black);
                    painter.drawText(2000,3500,adresse);


                    painter.end();

}

void MainWindow::on_pushButton_6_clicked()
{
  /* employe v;

            v.rechercher(ui->rec->text(),ui->tableView_employes);;

    ui->rec->setText("");*/

       int  CIN = ui->lineEdit_CIN->text().toInt();
        QString nom = ui->lineEdit_nom->text();
        QString prenom = ui->lineEdit_prenom->text();
        int num = ui->lineEdit_numero->text().toInt();
        QString adresse = ui->lineEdit_adresse->text();
            if(nom==""&&prenom==""&&adresse==""&&num==0){
            QString txt=ui->lineEdit_CIN->text();
            ui->tableView_employes->setModel(z.recherche_CIN_employe(txt));
            }
            else    if(CIN==0&&prenom==""&&adresse==""&&num==0){
                QString txt=ui->lineEdit_nom->text();
               ui->tableView_employes->setModel(z.recherche_nom_employe(txt));}
            else    if(CIN==0&&nom==""&&adresse==""&&num==0){
                QString txt=ui->lineEdit_prenom->text();
               ui->tableView_employes->setModel(z.recherche_prenom_employe(txt));}
            else    if(CIN==0&&nom==""&&prenom==""&&num==0){
                QString txt=ui->lineEdit_adresse->text();
               ui->tableView_employes->setModel(z.recherche_adresse_employe(txt));}



}



void MainWindow::on_pushButton_8_clicked()
{
    ui->tableView_depart->setModel(d.afficherTriNOM());
}

void MainWindow::on_pushButton_9_clicked()
{
    //ui->tableView_employes->setModel(z.afficherTriNOM());

        QString tri=ui->comboBox->currentText();

            if(tri=="CIN")
          ui->tableView_employes->setModel(z.ordre_CIN_employe());
            else if(tri=="Nom")
                ui->tableView_employes->setModel(z.ordre_nom_employe());
            else if(tri=="Prenom")
     ui->tableView_employes->setModel(z.ordre_prenom_employe());}








