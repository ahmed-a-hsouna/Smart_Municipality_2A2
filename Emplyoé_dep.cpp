#include "employe.h"
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>		


employe::employe()
{
    CIN=0;
    nom="";
    prenom="";
    sexe="";
    daten="";
    email="";	
    num=0;
    codep=0;
    lieun="";
    ville="";
    adresse="";

}
employe::employe(int i,QString a,QString b,QString c,QString d,QString e,int j,int k,QString f,QString g,QString h)
{
CIN=i;
nom=a;
prenom=b;
sexe=c;
daten=d;
email=e;
num=j;
codep=k;
lieun=f;
ville=g;
adresse=h;

}
bool employe::ajouter()
{
    QSqlQuery query;
    QString CINs= QString::number(CIN);
     QString nums= QString::number(num);
       QString codeps= QString::number(codep);
        
query.prepare("INSERT INTO EMPLOYE(CIN, nom, prenom, sexe, daten, email, num, codep, lieun, ville, adresse)""VALUES(:CIN , :nom , :prenom , :sexe , :daten , :email , :num , :codep , :lieun , :ville , :adresse )");
query.bindValue(":CIN",CINs);
query.bindValue(":nom",nom);
query.bindValue(":prenom",prenom);
query.bindValue(":daten",daten);
query.bindValue(":email",email);
query.bindValue(":num",nums);
query.bindValue(":codep",codeps);
query.bindValue(":lieun",lieun);
query.bindValue(":ville",ville);
query.bindValue(":adresse",adresse);
return query.exec();
}
QSqlQueryModel * employe::afficher()
{
QSqlQueryModel * model=new QSqlQueryModel();
  model->setQuery("select * from employe");
model->setHeaderData(0,Qt::Horizontal,QObject::tr("CIN"));
model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
model->setHeaderData(3,Qt::Horizontal,QObject::tr("sexe"));
model->setHeaderData(4,Qt::Horizontal,QObject::tr("daten"));
model->setHeaderData(5,Qt::Horizontal,QObject::tr("email"));
model->setHeaderData(6,Qt::Horizontal,QObject::tr("num"));
model->setHeaderData(7,Qt::Horizontal,QObject::tr("codep"));
model->setHeaderData(8,Qt::Horizontal,QObject::tr("lieun"));
model->setHeaderData(9,Qt::Horizontal,QObject::tr("ville"));
model->setHeaderData(10,Qt::Horizontal,QObject::tr("adresse"));

return model;

}
bool employe::supprimer(int CINe)
{
    QSqlQuery Query;
    QString CINs=QString::number(CINe);
    Query.prepare("Delete from employe where CIN = :CIN"  );
    Query.bindValue(":CIN",CINs);
    return Query.exec();


}
bool employe::modifier(int CIN)
{
    QSqlQuery query;

    QString CINs=QString::number(CIN);
     QString id_depart=QString::number(idDepart);
      query.prepare("UPDATE EMPLOYE SET CIN='"+CIN+"',nom='"+nom+"',prenom='"+prenom+"',sexe='"+sexe+"',daten='"+daten+"',email='"+email+"',num='"+num+"',codep='"+codep+"',lieun='"+lieun+"',ville='"+ville+"',adresse='"+adresse+"' where CIN='"+CINs+"'");

return query.exec();
}
