#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "contrat.h"
#include "QMessageBox"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QTextDocument>
#include <QtPrintSupport/QPrinter>
#include <QMessageBox>
#include <QPrinter>
#include <QPrintDialog>
#include <QTextStream>
#include <QPainter>
#include <QTextStream>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->afficher_client_4->setModel(tempcontrat.afficherContrat());
     ui->tableView->setModel(tempfourriere.afficherfourriere());
     ui->afficher_client_3->setModel(tempfourriere.afficherfourriere());
       ui->tab_afficher->setModel(tempcontrat.afficherContrat());
}


MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_pushButton_11_clicked() //commerciale
{
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_pushButton_6_clicked() //ajout commer
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_pushButton_7_clicked() //afficher comerc
{
    ui->stackedWidget->setCurrentIndex(3);
}


void MainWindow::on_pushButton_9_clicked() //back comerc
{
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_pushButton_10_clicked() //back ajout commerc
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_33_clicked()//back affich commerc
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_12_clicked()
{
     ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_pushButton_13_clicked()
{
     ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_pushButton_14_clicked()
{
     ui->stackedWidget->setCurrentIndex(6);
}

void MainWindow::on_pushButton_16_clicked()
{
     ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_pushButton_17_clicked()
{
         ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_pushButton_15_clicked()
{
    QString metierm=ui->lineEdit_metierm->text();
        QString metierp=ui->lineEdit_metierp->text();
        QString nomm=ui->lineEdit_nomm->text();
        QString nomp=ui->lineEdit_nomp->text();
        QString date=ui->lineEdit_date->text();
        int cinp=ui->lineEdit_cinp->text().toInt();
        int cinm=ui->lineEdit_cinm->text().toInt();
        contrat c(nomp,nomm,metierp,metierm,date,cinm,cinp);
        bool test ;
        test=c.ajouterContrat();

        if(test)
     {
            ui->tab_afficher->setModel(tempcontrat.afficherContrat());
             ui->afficher_client_4->setModel(tempcontrat.afficherContrat());
            QMessageBox::information(nullptr, QObject::tr("Ajout contrat"),
                        QObject::tr("Ajout avec succés.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
     }
     else
            QMessageBox::critical(nullptr, QObject::tr("Ajout contrat"),
                        QObject::tr("Ajout impossible.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);





    }



void MainWindow::on_pushButton_43_clicked()

    {
         int cinm=ui->lineEdit_8->text().toInt();
        bool test;
        test=tempcontrat.supprimerContrat(cinm);
        if(test)
        {
         ui->tab_afficher->setModel(tempcontrat.afficherContrat());
          ui->afficher_client_4->setModel(tempcontrat.afficherContrat());
            QMessageBox::information(nullptr, QObject::tr("supprimer contrat"),
                        QObject::tr("supprission avec succés.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
        }
        else
            QMessageBox::critical(nullptr, QObject::tr("supprimer contrat"),
                        QObject::tr("supprision échoué.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

    }


void MainWindow::on_pushButton_chercherP_5_clicked()
{

    QString nomp=ui->lineEdit_1->text();
    QString date=ui->lineEdit_date1->text();
    QString metierp=ui->lineEdit_metierp_1->text();
    QString metierm=ui->lineEdit_metierm1->text();
    QString nomm=ui->lineEdit_nomm1->text();
int cinp=ui->lineEdit_cinp1->text().toInt();
    int cinm=ui->lineEdit_cinm1->text().toInt();
    contrat c(nomp,nomm,metierp,metierm,date,cinm,cinp);
    bool test ;
    test=c.modifierContrat(cinm);

    if(test)
 {
        ui->tab_afficher->setModel(tempcontrat.afficherContrat());
         ui->afficher_client_4->setModel(tempcontrat.afficherContrat());
        QMessageBox::information(nullptr, QObject::tr("modifier contrat"),
                    QObject::tr("modifier avec succés.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
 }
 else
        QMessageBox::critical(nullptr, QObject::tr("modifier contrat"),
                    QObject::tr("modifier impossible.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);




}


void MainWindow::on_pushButton_8_clicked()
{
    QString matricule=ui->lineEdit_matricule->text();
        QString type=ui->lineEdit_type->text();
        QString couleur=ui->lineEdit_couleur->text();
        fourriere f (matricule,type,couleur);
        bool test ;
        test=f.ajouterfourriere();

        if(test)
     {
            ui->tableView->setModel(tempfourriere.afficherfourriere());
             ui->afficher_client_3->setModel(tempfourriere.afficherfourriere());
            QMessageBox::information(nullptr, QObject::tr("Ajout fourriere"),
                        QObject::tr("Ajout avec succés.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
     }
     else
            QMessageBox::critical(nullptr, QObject::tr("Ajout fourriere"),
                        QObject::tr("Ajout impossible.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);




}

void MainWindow::on_pushButton_42_clicked()
{
    QString matricule=ui->cx_nomf_13->text();
    bool test;
    test=tempfourriere.supprimerfourriere(matricule);
    if(test)
    {
        ui->tableView->setModel(tempfourriere.afficherfourriere());
         ui->afficher_client_3->setModel(tempfourriere.afficherfourriere());
        QMessageBox::information(nullptr, QObject::tr("supprimer fourriere"),
                    QObject::tr("supprission avec succés.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("supprimer fourriere"),
                    QObject::tr("supprision échoué.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}


void MainWindow::on_pushButton_chercherP_4_clicked()
{

    QString matricule=ui->lineEdit_ref_4->text();
    QString type=ui->lineEdit_nomP_4->text();
    QString couleur=ui->lineEdit_nb_14->text();

       fourriere f(matricule,type,couleur);
    bool test ;
    test=f.modifierfourriere();

    if(test)
 {
        ui->tableView->setModel(tempfourriere.afficherfourriere());
         ui->afficher_client_3->setModel(tempfourriere.afficherfourriere());
        QMessageBox::information(nullptr, QObject::tr("modifier fourrier"),
                    QObject::tr("modifier avec succés.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
 }
 else
        QMessageBox::critical(nullptr, QObject::tr("modifier fourriere"),
                    QObject::tr("modifier impossible.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);




}

void MainWindow::on_pushButton_18_clicked()
{
       ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_39_clicked()
{
    int cinm=ui->lineEdit->text().toInt();
            ui->afficher_client_4->setModel(tempcontrat.chercherContrat(cinm));

            QMessageBox::information(nullptr, QObject::tr("chercher"),
                        QObject::tr("ok"), QMessageBox::Cancel);
}

void MainWindow::on_pushButton_clicked()
{
    QSqlDatabase db;
                    QTableView table_commande;
                    QSqlQueryModel * Modal=new  QSqlQueryModel();

                    QSqlQuery qry;
                     qry.prepare("SELECT * FROM TABLE1 ");
                     qry.exec();
                     Modal->setQuery(qry);
                     table_commande.setModel(Modal);



                     db.close();


                     QString strStream;
                     QTextStream out(&strStream);

                     const int rowCount = table_commande.model()->rowCount();
                     const int columnCount =  table_commande.model()->columnCount();


                     const QString strTitle ="Document";


                     out <<  "<html>\n"
                         "<head>\n"
                             "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                         <<  QString("<title>%1</title>\n").arg(strTitle)
                         <<  "</head>\n"
                         "<body bgcolor=#ffffff link=#5000A0>\n"
                        << QString("<h3 style=\" font-size: 32px; font-family: Arial, Helvetica, sans-serif; color: #FF9933; font-weight: lighter; text-align: center;\">%1</h3>\n").arg("Liste des commandes")
                        <<"<br>"
                         <<"<table border=1 cellspacing=0 cellpadding=2>\n";

                     out << "<thead><tr bgcolor=#f0f0f0>";
                     for (int column = 0; column < columnCount; column++)
                         if (!table_commande.isColumnHidden(column))
                             out << QString("<th>%1</th>").arg(table_commande.model()->headerData(column, Qt::Horizontal).toString());
                     out << "</tr></thead>\n";

                     for (int row = 0; row < rowCount; row++) {
                         out << "<tr>";
                         for (int column = 0; column < columnCount; column++) {
                             if (!table_commande.isColumnHidden(column)) {
                                 QString data = table_commande.model()->data(table_commande.model()->index(row, column)).toString().simplified();
                                 out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                             }
                         }
                         out << "</tr>\n";
                     }
                     out <<  "</table>\n"
                             "<br><br>"
                             //<< QString("<p><img src=":/img/aze.png"; width="200"; height="200";\">%1</p>\n")
                             <<"<br>"
                             <<"<table border=1 cellspacing=0 cellpadding=2>\n";


                         out << "<thead><tr bgcolor=#f0f0f0>";

                             out <<  "</table>\n"

                         "</body>\n"
                         "</html>\n";

                     QTextDocument *document = new QTextDocument();
                     document->setHtml(strStream);

                     QPrinter printer;
                     QPrintDialog *dialog = new QPrintDialog(&printer, NULL);
                     if (dialog->exec() == QDialog::Accepted) {

                         QLabel lab;
                          QPixmap pixmap(":/img/aze.png");
                         lab.setPixmap(pixmap);
                         QPainter painter(&lab);
                         //QPrinter printer(QPrinter::PrinterResolution);

                         //pixmap.load("aze.png");
                         //painter.drawPixmap(0,0,this->width(),this->height(),pixmap);
                         //painter.drawPixmap(10,10,50,50, pixmap);

                         document->print(&printer);
                     }

                     printer.setOutputFormat(QPrinter::PdfFormat);
                     printer.setPaperSize(QPrinter::A4);
                     printer.setOutputFileName("/tmp/rendezvous.pdf");
                     printer.setPageMargins(QMarginsF(15, 15, 15, 15));



                     delete document;
}

void MainWindow::on_pushButton_35_clicked()
{
    QSqlDatabase db;
                    QTableView table_commande;
                    QSqlQueryModel * Modal=new  QSqlQueryModel();

                    QSqlQuery qry;
                     qry.prepare("SELECT * FROM TABLE2 ");
                     qry.exec();
                     Modal->setQuery(qry);
                     table_commande.setModel(Modal);



                     db.close();


                     QString strStream;
                     QTextStream out(&strStream);

                     const int rowCount = table_commande.model()->rowCount();
                     const int columnCount =  table_commande.model()->columnCount();


                     const QString strTitle ="Document";


                     out <<  "<html>\n"
                         "<head>\n"
                             "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                         <<  QString("<title>%1</title>\n").arg(strTitle)
                         <<  "</head>\n"
                         "<body bgcolor=#ffffff link=#5000A0>\n"
                        << QString("<h3 style=\" font-size: 32px; font-family: Arial, Helvetica, sans-serif; color: #FF9933; font-weight: lighter; text-align: center;\">%1</h3>\n").arg("Liste des commandes")
                        <<"<br>"
                         <<"<table border=1 cellspacing=0 cellpadding=2>\n";

                     out << "<thead><tr bgcolor=#f0f0f0>";
                     for (int column = 0; column < columnCount; column++)
                         if (!table_commande.isColumnHidden(column))
                             out << QString("<th>%1</th>").arg(table_commande.model()->headerData(column, Qt::Horizontal).toString());
                     out << "</tr></thead>\n";

                     for (int row = 0; row < rowCount; row++) {
                         out << "<tr>";
                         for (int column = 0; column < columnCount; column++) {
                             if (!table_commande.isColumnHidden(column)) {
                                 QString data = table_commande.model()->data(table_commande.model()->index(row, column)).toString().simplified();
                                 out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                             }
                         }
                         out << "</tr>\n";
                     }
                     out <<  "</table>\n"
                             "<br><br>"
                             //<< QString("<p><img src=":/img/aze.png"; width="200"; height="200";\">%1</p>\n")
                             <<"<br>"
                             <<"<table border=1 cellspacing=0 cellpadding=2>\n";


                         out << "<thead><tr bgcolor=#f0f0f0>";

                             out <<  "</table>\n"

                         "</body>\n"
                         "</html>\n";

                     QTextDocument *document = new QTextDocument();
                     document->setHtml(strStream);

                     QPrinter printer;
                     QPrintDialog *dialog = new QPrintDialog(&printer, NULL);
                     if (dialog->exec() == QDialog::Accepted) {

                         QLabel lab;
                          QPixmap pixmap(":/img/aze.png");
                         lab.setPixmap(pixmap);
                         QPainter painter(&lab);
                         //QPrinter printer(QPrinter::PrinterResolution);

                         //pixmap.load("aze.png");
                         //painter.drawPixmap(0,0,this->width(),this->height(),pixmap);
                         //painter.drawPixmap(10,10,50,50, pixmap);

                         document->print(&printer);
                     }

                     printer.setOutputFormat(QPrinter::PdfFormat);
                     printer.setPaperSize(QPrinter::A4);
                     printer.setOutputFileName("/tmp/rendezvous.pdf");
                     printer.setPageMargins(QMarginsF(15, 15, 15, 15));



                     delete document;
}
