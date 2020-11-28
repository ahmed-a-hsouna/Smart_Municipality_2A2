#include "fenetre.h"
#include "ui_fenetre.h"
#include "certifdeces.h"
#include "permisconstr.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include <QMessageBox>
#include <QPrinter>
#include <QPrintDialog>
#include <QPdfWriter>
#include <QPainter>
#include <QSystemTrayIcon>
#include <QtPrintSupport/QPrinter>
#include <QTextDocument>
#include <QIntValidator>
#include <QValidator>

Fenetre::Fenetre(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Fenetre)
{
    ui->setupUi(this);
  //  QRegularExpression
    QRegExp rx("(|\"|/|\\.,|[A-Z,a-z]){30}");
    ui->lineEdit_10->setValidator(new QRegExpValidator(rx, this));
    ui->lineEdit_cin->setValidator(new QIntValidator(0,99999999,this));
    ui->lineEdit_2->setValidator(new QIntValidator(0,99999999,this));
    ui->lineEdit_11->setValidator(new QIntValidator(0,99999,this));
    ui->tableView->setModel(tempcert.afficher_certif());
    ui->tableView_2->setModel(temppermis.afficher_permis());
    son=new QSound(":/sons/click.wav");
}

Fenetre::~Fenetre()
{
    delete ui;
}

void Fenetre::on_pushButton_clicked() //certificat de deces
{
    son->play();
    ui->stackedWidget->setCurrentIndex(1);
}

void Fenetre::on_pushButton_2_clicked() //permis de construction
{
    son->play();
    ui->stackedWidget->setCurrentIndex(2);

}

void Fenetre::on_pushButton_3_clicked()//Back
{
    son->play();
    ui->stackedWidget->setCurrentIndex(0);

}

void Fenetre::on_pushButton_11_clicked() //Back
{
    son->play();
    ui->stackedWidget->setCurrentIndex(0);

}

void Fenetre::on_pushButton_ajouter_clicked() //ajouter certificat deces
{
    
    int cin=ui->lineEdit_cin->text().toInt();
    QString nom=ui->lineEdit_nom->text();
    QString prenom=ui->lineEdit_prenom->text();
    QString datedeces=ui->dateEdit->date().toString();
    QString lieu=ui->lineEdit_lieu->text();
    QString statut=" ";
        if (ui->radioButton_celibataire->isChecked())
        {
            statut="Celibataire";
            statut=ui->radioButton_celibataire->text();
        }
        else if (ui->radioButton_divorce->isChecked())
        {
            statut="Divorce";
            statut=ui->radioButton_divorce->text();
        }
        else if (ui->radioButton_marie->isChecked())
        {
            statut="Marie";
            statut=ui->radioButton_marie->text();
        }
        else
        {
            statut="Voeuf";
            statut=ui->radioButton_voeuf->text();
        }

        Certifdeces c(cin,nom,prenom,datedeces,lieu,statut);
        bool test=c.ajouter_certif();
        if(test)
        {    
            ui->tableView->setModel(tempcert.afficher_certif());
            QMessageBox::information(nullptr, QObject::tr("Ajout"),
                        QObject::tr("Ajout avec succés.\n" "Click Cancel to exit."), QMessageBox::Cancel);

        }
         else
        {
          
            QMessageBox::critical(nullptr, QObject::tr("Ajout"),
                        QObject::tr("Ajout échoué.\n""Click Cancel to exit."), QMessageBox::Cancel);
        }



    //int cin=ui->cx_idf->text().toInt();

}

void Fenetre::on_pushButton_9_clicked() //supprimer certificat deces
{ 
    int id=ui->lineEdit_cin->text().toUInt();
        bool test=tempcert.supprimer_certif(id);
        if(test)
        { 
            ui->tableView->setModel(tempcert.afficher_certif());
            QMessageBox::information(nullptr, QObject::tr("Supprimer"),
            QObject::tr("Suppression avec succée"), QMessageBox::Ok);
           // hide();
        }
        else
        {
        
            QMessageBox::critical(nullptr, QObject::tr("Supprimer"),
            QObject::tr("Suppression echoués"), QMessageBox::Ok);
        }
}

void Fenetre::on_pushButton_14_clicked() //ajouter permis
{   
    int cin=ui->lineEdit_2->text().toInt();
    QString lieu=ui->lineEdit_10->text();
    int codepostale=ui->lineEdit_11->text().toInt();

        permisconstr p(cin,lieu,codepostale);
        bool test=p.ajouter_permis();
        if(test)
        {
           ui->tableView_2->setModel(temppermis.afficher_permis());
            QMessageBox::information(nullptr, QObject::tr("Ajout"),
                        QObject::tr("Ajout avec succés.\n" "Click Cancel to exit."), QMessageBox::Cancel);

        }
         else
        {
            
            QMessageBox::critical(nullptr, QObject::tr("Ajout"),
                        QObject::tr("Ajout échoué.\n""Click Cancel to exit."), QMessageBox::Cancel);
        }

}


void Fenetre::on_pushButton_16_clicked() //supprimer permis
{   
    int id=ui->lineEdit_2->text().toUInt();
        bool test=temppermis.supprimer_permis(id);
        if(test)
        {  
            ui->tableView_2->setModel(temppermis.afficher_permis());
            QMessageBox::information(nullptr, QObject::tr("Supprimer"),
            QObject::tr("Suppression avec succée"), QMessageBox::Ok);
           // hide();
        }
        else
        {
            
            QMessageBox::critical(nullptr, QObject::tr("Supprimer"),
            QObject::tr("Suppression echoués"), QMessageBox::Ok);
        }
}

void Fenetre::on_pushButton_8_clicked() //modifier certificat
{   
    int cin=ui->lineEdit_cin->text().toInt();
    QString nom=ui->lineEdit_nom->text();
    QString prenom=ui->lineEdit_prenom->text();
    QString datedeces=ui->dateEdit->date().toString();
    QString lieu=ui->lineEdit_lieu->text();
    QString statut=" ";
        if (ui->radioButton_celibataire->isChecked())
        {
            statut="Celibataire";
            statut=ui->radioButton_celibataire->text();
        }
        else if (ui->radioButton_divorce->isChecked())
        {
            statut="Divorce";
            statut=ui->radioButton_divorce->text();
        }
        else if (ui->radioButton_marie->isChecked())
        {
            statut="Marie";
            statut=ui->radioButton_marie->text();
        }
        else
        {
            statut="Voeuf";
            statut=ui->radioButton_voeuf->text();
        }

        Certifdeces c(cin,nom,prenom,datedeces,lieu,statut);
        bool test=c.modifier_certif(cin);
        if(test)
        {   
            ui->tableView->setModel(tempcert.afficher_certif());
            QMessageBox::information(nullptr, QObject::tr("Modification"),
                        QObject::tr("Ajout avec succés.\n" "Click Cancel to exit."), QMessageBox::Cancel);

        }
         else
        {
            
            QMessageBox::critical(nullptr, QObject::tr("Modification"),
                        QObject::tr("Ajout échoué.\n""Click Cancel to exit."), QMessageBox::Cancel);
}
}

void Fenetre::on_pushButton_15_clicked() //modifier permis
{ 
    int cin=ui->lineEdit_2->text().toInt();
    QString lieu=ui->lineEdit_10->text();
    int codepostale=ui->lineEdit_11->text().toInt();

        permisconstr p(cin,lieu,codepostale);
        bool test=p.modifier_permis(cin);
        if(test)
        {  
           ui->tableView_2->setModel(temppermis.afficher_permis());
            QMessageBox::information(nullptr, QObject::tr("Modification"),
                        QObject::tr("Ajout avec succés.\n" "Click Cancel to exit."), QMessageBox::Cancel);

        }
         else
        {
           
            QMessageBox::critical(nullptr, QObject::tr("Modification"),
                        QObject::tr("Ajout échoué.\n""Click Cancel to exit."), QMessageBox::Cancel);
        }
}

void Fenetre::on_pushButton_13_clicked()
{
       QPrinter rd;
       QPrintDialog d(&rd,this);
       d.setWindowTitle("PRINT PERMIS DE CONSTRUCTION");
       d.addEnabledOption(QAbstractPrintDialog::PrintSelection);
       if (d.exec() != QDialog::Accepted)
           return ;
}

void Fenetre::on_pushButton_5_clicked()
{
       QPrinter rd;
       QPrintDialog d(&rd,this);
       d.setWindowTitle("PRINT CERTIFICAT DE DECES");
       d.addEnabledOption(QAbstractPrintDialog::PrintSelection);
       if (d.exec() != QDialog::Accepted)
           return ;
}

void Fenetre::on_pushButton_6_clicked()
{
    QString cin =ui->lineEdit_6->text();
    ui->tableView->setModel(tempcert.recherche(cin));
}

void Fenetre::on_pushButton_10_clicked()
{
    QString cin =ui->lineEdit_6->text();
    ui->tableView_2->setModel(temppermis.recherche(cin));
}

void Fenetre::on_pushButton_19_clicked()
{
    ui->tableView_2->setModel(temppermis.triercroi());
}

void Fenetre::on_pushButton_20_clicked()
{
    ui->tableView_2->setModel(temppermis.trierdec());
}

void Fenetre::on_pushButton_7_clicked()
{
    ui->tableView->setModel(tempcert.triercroi());
}

void Fenetre::on_pushButton_18_clicked()
{
    ui->tableView->setModel(tempcert.trierdec());
}

void Fenetre::on_pushButton_4_clicked()//PDF certificat deces
{
    son->play();
    Certifdeces c;
    c.CREATION_PDF();
}

void Fenetre::on_pushButton_12_clicked() //PDF construction
{
    son->play();
    permisconstr p;
    p.CREATION_PDF();
}

