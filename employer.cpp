#include "employer.h"
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>


employe::employe()
{
    CIN=0;
    nom="";
    prenom="";
    nume=0;
    adresse="";

}
employe::employe(int i,QString a,QString b,int c,QString d)
{
CIN=i;
nom=a;
prenom=b;
nume=c;
adresse=d;

}

bool employe::ajouter()
{QSqlQuery query;
  QString CINs=QString::number(CIN);
  QString nums=QString::number(nume);
  query.prepare("insert into employe (CIN,nom,prenom,nume,adresse) values (:CIN,:nom,:prenom,:nume,:adresse)");
  query.bindValue(":CIN",CINs);
  query.bindValue(":nume",nums);
  query.bindValue(":nom",nom);
  query.bindValue(":prenom",prenom);
  query.bindValue(":adresse",adresse);
  return query.exec();
}
QSqlQueryModel * employe::afficher()
{ QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from employe");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("CIN"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
     model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
     model->setHeaderData(3,Qt::Horizontal,QObject::tr("nume"));
     model->setHeaderData(4,Qt::Horizontal,QObject::tr("adresse"));

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
bool employe::modifier(int CINd)
{
    {
        QSqlQuery query ;
        query.prepare("update employe set CIN=? ,nom=?,prenom=?,nume=?,adresse=? where CIN=?");
        query.addBindValue(CIN);
        query.addBindValue(nom);
        query.addBindValue(prenom);
        query.addBindValue(nume);
        query.addBindValue(adresse);
        query.addBindValue(CINd);
        if(query.exec())
            return true;
        return false;
    }
}
bool employe::supprimerTout()
{ QSqlQuery query;

   query.prepare("delete from employe ");

  return query.exec();
}


/*void employe::rechercher(QString a,QTableView *g)
{ {QSqlQuery qry;
         QSqlQueryModel *m=new QSqlQueryModel();//initialisation
         qry.prepare("select * from employe where CIN like'%"+a+"%' OR nom like '%"+a+"%' OR prenom like '%"+a+"%' OR nume like '%"+a+"%' OR adresse like '%"+a+"%'");
                     qry.exec();
                 m->setQuery(qry);
         g->setModel(m);*/
    QSqlQueryModel *employe::recherche_CIN_employe(QString txt)
      {

          QSqlQueryModel *model=new QSqlQueryModel();
          model->setQuery("select * from employe where CIN LIKE '"+txt+"'" );
          model->setHeaderData(0,Qt::Horizontal,QObject::tr("CIN"));
          model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
          model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
          model->setHeaderData(3,Qt::Horizontal,QObject::tr("num"));
          model->setHeaderData(4,Qt::Horizontal,QObject::tr("adresse"));


          return model;
      }
      QSqlQueryModel *employe::recherche_nom_employe(QString txt)
      {

          QSqlQueryModel *model=new QSqlQueryModel();
          model->setQuery("select * from employe where nom LIKE '"+txt+"'" );
          model->setHeaderData(0,Qt::Horizontal,QObject::tr("CIN"));
          model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
          model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
          model->setHeaderData(3,Qt::Horizontal,QObject::tr("num"));
          model->setHeaderData(4,Qt::Horizontal,QObject::tr("adresse"));

          return model;
      }
      QSqlQueryModel *employe::recherche_prenom_employe(QString txt)
      {

          QSqlQueryModel *model=new QSqlQueryModel();
          model->setQuery("select * from employe where prenom LIKE '"+txt+"'" );
          model->setHeaderData(0,Qt::Horizontal,QObject::tr("CIN"));
          model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
          model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
          model->setHeaderData(3,Qt::Horizontal,QObject::tr("num"));
          model->setHeaderData(4,Qt::Horizontal,QObject::tr("adresse"));

          return model;
      }
     /* QSqlQueryModel *employe::recherche_num_employe(QString txt)
      {

          QSqlQueryModel *model=new QSqlQueryModel();
          model->setQuery("select * from employe where num LIKE '"+txt+"'" );
          model->setHeaderData(0,Qt::Horizontal,QObject::tr("CIN"));
          model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
          model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
          model->setHeaderData(3,Qt::Horizontal,QObject::tr("num"));
          model->setHeaderData(4,Qt::Horizontal,QObject::tr("adresse"));

          return model;
      }*/
      QSqlQueryModel *employe::recherche_adresse_employe(QString txt)
      {

          QSqlQueryModel *model=new QSqlQueryModel();
          model->setQuery("select * from employe where adresse LIKE '"+txt+"'" );
          model->setHeaderData(0,Qt::Horizontal,QObject::tr("CIN"));
          model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
          model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
          model->setHeaderData(3,Qt::Horizontal,QObject::tr("num"));
          model->setHeaderData(4,Qt::Horizontal,QObject::tr("adresse"));

          return model;
      }





QSqlQueryModel * employe::afficherTriNOM()
{ QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from employe ORDER BY nom ASC");// asc assendant dsc descendant
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("CIN"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
     model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
     model->setHeaderData(3,Qt::Horizontal,QObject::tr("nume"));
     model->setHeaderData(4,Qt::Horizontal,QObject::tr("adresse"));

    return model;

}

QSqlQueryModel *employe::ordre_CIN_employe()
     {
         QSqlQueryModel *model=new QSqlQueryModel();
         model->setQuery("select * from employe  order by CIN" );
         model->setHeaderData(0,Qt::Horizontal,QObject::tr("CIN"));
         model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
         model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
         model->setHeaderData(4,Qt::Horizontal,QObject::tr("num"));
         model->setHeaderData(3,Qt::Horizontal,QObject::tr("adresse"));



         return model;
     }

QSqlQueryModel *employe::ordre_nom_employe()
     {
         QSqlQueryModel *model=new QSqlQueryModel();
         model->setQuery("select * from employe  order by nom" );
         model->setHeaderData(0,Qt::Horizontal,QObject::tr("CIN"));
         model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
         model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
         model->setHeaderData(4,Qt::Horizontal,QObject::tr("num"));
         model->setHeaderData(3,Qt::Horizontal,QObject::tr("adresse"));



         return model;
     }
QSqlQueryModel *employe::ordre_prenom_employe()
     {
         QSqlQueryModel *model=new QSqlQueryModel();
         model->setQuery("select * from employe  order by prenom" );
         model->setHeaderData(0,Qt::Horizontal,QObject::tr("CIN"));
         model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
         model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
         model->setHeaderData(4,Qt::Horizontal,QObject::tr("num"));
         model->setHeaderData(3,Qt::Horizontal,QObject::tr("adresse"));



         return model;
     }
