#include "mainwindow.h"
/*#include <citoyent.h>
#include <commerciale.h> */
#include "ui_mainwindow.h"
/*#include "QPushButton"
#include <QMessageBox>
#include <QPainter>
#include <QPrinter>
#include <QPrintDialog>
#include <QtPrintSupport/QPrinter>
#include<QFileDialog>
#include <QTextDocument>   */


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
   /* ui->setupUi(this);
    ui->tab_citoyent->setModel(temcitoyent.afficher_citoyent());
    ui->afficher_commerciale_1->setModel(tempcommerciale.afficher_commerciale()); */
}


MainWindow::~MainWindow()
{
    delete ui;
}




/*void MainWindow::on_pushButton_11_clicked() //commerciale
{


    ui->stackedWidget->setCurrentIndex(4);

}

void MainWindow::on_pushButton_12_clicked() //client
{

     ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_4_clicked() //ajout client
{

ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_pushButton_3_clicked() //afficher client
{

    ui->stackedWidget->setCurrentIndex(3);
}


void MainWindow::on_pushButton_5_clicked() //back_client
{

    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_pushButton_2_clicked() //back ajout client
{

    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_21_clicked()//back affiche client
{

    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_pushButton_33_clicked()//back  commerc
{

    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_clicked() //bouton ajouter citoyent
{

    int cin=ui->cx_idf->text().toInt();
    QString nom=ui->lineEdit_nom->text();
    QString prenom=ui->lineEdit_prenom->text();
    QString lieu=ui->lineEdit_lieu->text();
    int num_tlph=ui->lineEdit_telph->text().toInt();
    QString email=ui->lineEdit_mail->text();
    QString ville=ui->lineEdit_ville->text();
    QString adresse=ui->lineEdit_adresse->text();
    QString profession=ui->lineEdit_profession->text();
    int code_postale=ui->lineEdit_codepostale->text().toInt();
    QString date = ui->dateEdit->date().toString();
    QString statut=" ";
    if (ui->femme->isChecked())
    {
        statut="femme";
        statut=ui->femme->text();
    }
    else
    {
        statut="homme";
        statut=ui->homme->text();
    }
    int age=ui->age->text().toInt();

    citoyent c(cin,age,num_tlph,code_postale,nom,prenom,date,lieu,statut,email,profession,ville,adresse);
    bool test=c.ajouter_citoyent();
    if (test)
    {
        ui->tab_citoyent->setModel(temcitoyent.afficher_citoyent());
        QMessageBox::information(nullptr, QObject::tr("Ajout"),
        QObject::tr("Ajout avec succée"), QMessageBox::Ok);
       // hide();
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Ajout"),
        QObject::tr("Ajout echoués"), QMessageBox::Ok);
    }


}

void MainWindow::on_pushButton_40_clicked() // bouton supprimer citoyent
{

    int id=ui->lineEdit_ref_2->text().toUInt();
    bool test=temcitoyent.supprimer_citoyent(id);
    if(test)
    {
        ui->tab_citoyent->setModel(temcitoyent.afficher_citoyent());
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

void MainWindow::on_pushButton_43_clicked() //Ajouter licence commercaile
{

    int cin=ui->lineEdit_1->text().toInt();
    int cnss=ui->lineEdit_2->text().toInt();
    QString fiscale=ui->lineEdit_3->text();
    QString secteur=ui->lineEdit_4->text();


    commerciale c(cin,cnss,fiscale,secteur);
    bool test=c.ajouter_commerciale();
    if (test)
    {
        ui->afficher_commerciale_1->setModel(tempcommerciale.afficher_commerciale());
        QMessageBox::information(nullptr, QObject::tr("Ajout"),
        QObject::tr("Ajout avec succée"), QMessageBox::Ok);
       // hide();
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Ajout"),
        QObject::tr("Ajout echoués"), QMessageBox::Ok);
    }

}


void MainWindow::on_pushButton_42_clicked() //supprimer licence commerciale
{

    int id=ui->lineEdit_1->text().toUInt();
    bool test=tempcommerciale.supprimer_commerciale(id);
    if(test)
    {
        ui->afficher_commerciale_1->setModel(tempcommerciale.afficher_commerciale());
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

void MainWindow::on_pushButton_44_clicked() //modifier licence commerciale
{
    int id = ui->lineEdit_1->text().toInt();
    int cnss = ui->lineEdit_2->text().toInt();
     QString fiscale= ui->lineEdit_3->text();
     QString secteur= ui->lineEdit_4->text();


      commerciale a(id,cnss,fiscale,secteur);
      bool test=a.modifier_commerciale(id);
      if(test)
    {

          ui->afficher_commerciale_1->setModel(tempcommerciale.afficher_commerciale());//refresh
    QMessageBox::information(nullptr, QObject::tr("Modifier"),
                      QObject::tr("Modification avec succees.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);

    }
      else
          QMessageBox::critical(nullptr, QObject::tr("Modifier"),
                      QObject::tr("Erreur !.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_pushButton_chercherP_2_clicked() //modifier citoyent
{
    int cin=ui->lineEdit_ref_2->text().toInt();
    QString nom=ui->lineEdit_nomP_2->text();
    QString prenom=ui->lineEdit_nb_2->text();
    QString lieu=ui->lineEdit_nb_3->text();
    int num_tlph=ui->lineEdit_nb_4->text().toInt();
    QString email=ui->lineEdit_mail->text();
    QString ville=ui->lineEdit_ville->text();
    QString adresse=ui->lineEdit_nb_6->text();
    QString profession=ui->lineEdit_nb_5->text();
    int code_postale=ui->lineEdit_nb_7->text().toInt();
    QString date = ui->dateEdit->date().toString();
    QString statut=" ";
    if (ui->femme->isChecked())
    {
        statut="femme";
        statut=ui->femme->text();
    }
    else
    {
        statut="homme";
        statut=ui->homme->text();
    }
    int age=ui->age->text().toInt();

      citoyent a(cin,age,num_tlph,code_postale,nom,prenom,date,lieu,statut,email,profession,ville,adresse);
      bool test=a.modifier_citoyent(cin);
      if(test)
    {

         ui->tab_citoyent->setModel(temcitoyent.afficher_citoyent());//refresh
    QMessageBox::information(nullptr, QObject::tr("Modifier"),
                      QObject::tr("Modification avec succees.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);

    }
      else
          QMessageBox::critical(nullptr, QObject::tr("Modifier"),
                      QObject::tr("Erreur !.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pushButton_35_clicked() //  imprimer
{
    QPrinter rd;
        QPrintDialog d(&rd,this);
        d.setWindowTitle("Print Livre");
        d.addEnabledOption(QAbstractPrintDialog::PrintSelection);
        if (d.exec() != QDialog::Accepted)
            return ;
}

void MainWindow::on_pushButton_23_clicked() //imprimer
{
    QPrinter rd;
        QPrintDialog d(&rd,this);
        d.setWindowTitle("Print Livre");
        d.addEnabledOption(QAbstractPrintDialog::PrintSelection);
        if (d.exec() != QDialog::Accepted)
            return ;
}

void MainWindow::on_pushButton_24_clicked() //pdf CLIENT
{

}

void MainWindow::on_pushButton_36_clicked() // PDF COMMERCIALE
{
    QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Export PDF", QString(), "*.pdf");
        if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }

        QPrinter printer(QPrinter::PrinterResolution);
        printer.setOutputFormat(QPrinter::PdfFormat);
        printer.setPaperSize(QPrinter::A4);
        printer.setOutputFileName(fileName);

        QTextDocument doc;
        QSqlQuery q;
        q.prepare("SELECT * FROM COMMERCIALE ");
        q.exec();
        QString pdf="<br> <h1  style='color:red'>  LISTE DES LICENCES COMMERCIALES  <br></h1>\n <br> <table>  <tr>  <th>CIN </th> <th>CNSS </th> <th>FISCALE</th> <th> SECTEUR D ACTIVITE </th>    </tr>" ;


        while ( q.next()) {

            pdf= pdf+ " <br> <tr> <td>"+ q.value(0).toString()+" " + q.value(1).toString() +"</td>   <td>" +q.value(2).toString() +"  "" " "</td>   <td>"+q.value(3).toString()+"</td>  " ;

        }
        doc.setHtml(pdf);
        doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
        doc.print(&printer);
}

void MainWindow::on_pushButton_34_clicked()
{
    QString cin =ui->cx_nomf_13->text();
        ui->afficher_commerciale_1->setModel(tempcommerciale.Recherche(cin));
}

void MainWindow::on_afficher_commerciale_1_activated(const QModelIndex &index)
{
    QString cin=ui->afficher_commerciale_1->model()->data(index).toString();
      QSqlQuery query;
      query.prepare("select * from COMMERCIALE where Cin LIKE '"+cin+"%' or CNSS LIKE '"+cin+"%' or fiscale LIKE '"+cin+"%' or secteur_dactivite LIKE '"+cin+"%'");
      if(query.exec())
      {
        while(query.next())
        {
            ui->lineEdit_1->setText(query.value(0).toString());
            ui->lineEdit_2->setText(query.value(1).toString());
            ui->lineEdit_3->setText(query.value(2).toString());
            ui->lineEdit_4->setText(query.value(3).toString());

        }
      }
        else
        {

          QMessageBox::critical(nullptr, QObject::tr("error"),
                      QObject::tr("error.\n""Click Cancel to exit."), QMessageBox::Cancel);
      }


}

void MainWindow::on_pushButton_6_clicked()
{


}

void MainWindow::on_radioButton_11_clicked()//trie mil kbirr li s5irr
{
     ui->afficher_commerciale_1->setModel(tempcommerciale.trierA());
}

void MainWindow::on_radioButton_13_clicked()
{
    ui->afficher_commerciale_1->setModel(tempcommerciale.trierB());
} */
/*void MainWindow::showTime()
{
    QTime time=QTime::currentTime();
    QString time_text=time.toString("hh:mm:ss");
    ui->label_13->setText(time_text);

} */

/*void MainWindow::showTime()
{
    QTime time=QTime::currentTime();
    QString time_text=time.toString("hh:mm:ss");
    ui->showTime->setText(time_text);

}*/
