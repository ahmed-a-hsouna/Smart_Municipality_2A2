#include "commerciale.h"

commerciale::commerciale()
{
    Cin=0;
    CNSS=0;
    fiscale=" ";
    secteur_activite=" ";
}

commerciale::commerciale(int c,int cn,QString f,QString s)
{
    this->Cin=c;
    this->CNSS=cn;
    this->fiscale=f;
    this->secteur_activite=s;
}

bool commerciale ::ajouter_commerciale()
{
    QSqlQuery query;
    QString CINS= QString::number(Cin);
    query.prepare("INSERT INTO COMMERCIALE(CIN,CNSS,FISCALE,SECTEUR_DACTIVITE) "
                  "VALUES (:Cin, :CNSS,:fiscale,:secteur_dactivite)");
    query.bindValue(":Cin", CINS);
    query.bindValue(":CNSS", CNSS);
    query.bindValue(":fiscale", fiscale);
    query.bindValue(":secteur_dactivite", secteur_activite);

    return    query.exec();
}

QSqlQueryModel * commerciale ::afficher_commerciale()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from commerciale");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("CNSS"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("FISCALE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("SECTEUR_DACTIVITE"));

    return model;
}


bool commerciale :: supprimer_commerciale(int idd)
{
    QSqlQuery query;
    QString res=QString::number(idd);
    query.prepare("Delete from commerciale where CIN = :id");
    query.bindValue(":id",res);
    return query.exec();

}

bool commerciale::modifier_commerciale(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Update commerciale set CIN = :cin , CNSS = :cnss , FISCALE = :fiscale , SECTEUR_DACTIVITE = :secteur_dactivite   where CIN = :cin ");
query.bindValue(":id", res);
query.bindValue(":cin", Cin);
query.bindValue(":cnss", CNSS);
query.bindValue(":fiscale", fiscale);
query.bindValue(":secteur_dactivite", secteur_activite);

return    query.exec();
}

QString commerciale :: get_fiscale() { return fiscale; }
QString commerciale :: get_secteur_activite() { return secteur_activite; }

QSqlQueryModel* commerciale::Recherche(QString cin)
 {
     QSqlQueryModel * model= new QSqlQueryModel();
     model->setQuery("select * from COMMERCIALE where Cin LIKE '"+cin+"%' or CNSS LIKE '"+cin+"%' or fiscale LIKE '"+cin+"%'");


     model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("CNSS"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("FISCALE"));

 return model;
}

QSqlQueryModel *commerciale::trierA() // m sghir lel kbir
{
    QSqlQuery * q = new  QSqlQuery ();
           QSqlQueryModel * model = new  QSqlQueryModel ();
           q->prepare("SELECT * FROM commerciale order by Cin ASC");
           q->exec();
           model->setQuery(*q);
           return model;

}

QSqlQueryModel *commerciale::trierB() // m sghir lel kbir
{
           QSqlQuery * q = new  QSqlQuery ();
                  QSqlQueryModel * model = new  QSqlQueryModel ();
                  q->prepare("SELECT * FROM commerciale order by Cin DESC");
                  q->exec();
                  model->setQuery(*q);
                  return model;
}
