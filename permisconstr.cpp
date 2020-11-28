#include "permisconstr.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include <QPrinter>
#include <QFileDialog>
#include <QTextDocument>


permisconstr::permisconstr()
{
    cin=0;
    lieu="";
    codepostale=0;

}
permisconstr::permisconstr(int c,QString l,int co)
{
    cin=c;
    lieu=l;
    codepostale=co;

}
bool permisconstr::ajouter_permis()
{
    QSqlQuery query;
    QString cinp=QString::number(cin);
    query.prepare("INSERT INTO PERMISCONSTRUCTION(CIN, LIEU, CODEPOSTALE)"
                  "VALUES(:cin, :lieu, :codepostale)");

    query.bindValue(":cin",cinp);
    query.bindValue(":lieu",lieu);
    query.bindValue(":codepostale",codepostale);

    return query.exec();
}
QSqlQueryModel * permisconstr::afficher_permis()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from permisconstruction");
    model->setHeaderData(0,Qt::Horizontal, QObject::tr("CIN Citoyen"));
    model->setHeaderData(1,Qt::Horizontal, QObject::tr("LIEU"));
    model->setHeaderData(2,Qt::Horizontal, QObject::tr("CODE POSTALE"));
    return model;
}

bool permisconstr::supprimer_permis(int idp)
{
    QSqlQuery query;
    QString rest=QString::number(idp);
    query.prepare("delete from permisconstruction where CIN= :id");
    query.bindValue(":id",rest);
    return query.exec();

}

bool permisconstr::modifier_permis(int idd) //modifier permis
{
    QSqlQuery query;
    QString res=QString::number(idd);
    query.prepare("Update permisconstruction set CIN = :id , LIEU = :lieu , CODEPOSTALE = :codepostale where CIN = :id ");
    query.bindValue(":id", res);
    query.bindValue(":cin",cin);
    query.bindValue(":lieu",lieu);
    query.bindValue(":codepostale",codepostale);
    return query.exec();

}

QSqlQueryModel *permisconstr::recherche(QString cin)
 {
     QSqlQueryModel * model= new QSqlQueryModel();
     model->setQuery("select * from PERMISCONSTRUCTION where cin LIKE '"+cin+"%' or lieu LIKE '"+cin+"%' or codepostale LIKE '"+cin+"%'");


     model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("LIEU"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("CODE POSTALE"));

 return model;
}
QSqlQueryModel *permisconstr::triercroi() 
{
    QSqlQuery * q = new  QSqlQuery ();
           QSqlQueryModel * model = new  QSqlQueryModel ();
           q->prepare("SELECT * FROM permisconstruction order by lieu ASC");
           q->exec();
           model->setQuery(*q);
           return model;
     
       /*    QSqlQuery * q = new  QSqlQuery ();
                  QSqlQueryModel * model = new  QSqlQueryModel ();
                  q->prepare("SELECT * FROM permisconstruction order by codepostale DESC");
                  q->exec();
                  model->setQuery(*q);
                  return model;*/
}

QSqlQueryModel *permisconstr::trierdec()
{
                     QSqlQuery * q = new  QSqlQuery ();
                     QSqlQueryModel * model = new  QSqlQueryModel ();
                     q->prepare("SELECT * FROM permisconstruction order by lieu DESC");
                     q->exec();
                     model->setQuery(*q);
                     return model;


}
void permisconstr::CREATION_PDF()
{
    QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Export PDF", QString(), "*.pdf");
    if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }

    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPaperSize(QPrinter::A4);
    printer.setOutputFileName(fileName);

    QTextDocument doc;
    QSqlQuery q;
    q.prepare("SELECT * FROM PERMISCONSTRUCTION ");
    q.exec();
    QString pdf="<br> <h1  style='color:blue'>LISTE PERMIS CONSTRUCTION  <br></h1>\n <br> <table>  <tr>  <th>CIN </th> <th>LIEU </th> <th> CODE POSTALE </th> </tr>" ;


    while ( q.next()) {

    pdf= pdf+ " <br> <tr>  <td>"+ q.value(0).toString()+"    &nbsp;&nbsp;&nbsp;     " + q.value(1).toString() +"</td>  &nbsp;&nbsp;&nbsp; <td>" +q.value(2).toString() +" &nbsp; </td> </td>" ;
    }
    doc.setHtml(pdf);
    doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
    doc.print(&printer);
}
