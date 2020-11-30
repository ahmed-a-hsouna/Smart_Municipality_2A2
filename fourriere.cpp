#include "fourriere.h"



fourriere::fourriere()
{
    matricule="";
    type="";
    couleur="";

}

fourriere::fourriere(QString np,QString nm,QString mm)
{
    matricule=np;
    type=nm;
    couleur=mm;


}

bool fourriere::ajouterfourriere()
{
    QSqlQuery query;
    query.prepare("INSERT INTO TABLE2(matricule,type,couleur) "
                  "VALUES(:matricule,:type,:couleur)");
    query.bindValue(":matricule",matricule);
    query.bindValue(":type",type);
    query.bindValue(":couleur",couleur);

    return query.exec();


}


QSqlQueryModel *fourriere::afficherfourriere()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from TABLE2");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("matricule"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("type"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("couleur"));


       return model;


}


bool fourriere::supprimerfourriere(QString matricule1)
{

    QSqlQuery query;
    query.prepare("Delete from TABLE2  where matricule=:matricule");
    query.bindValue(":matricule",matricule1);
    return query.exec();

}


bool fourriere::modifierfourriere()
{

    QSqlQuery query;

    query.prepare("UPDATE TABLE2 set matricule=:matricule,type=:type,couleur=:couleur where matricule=:matricule ");
    query.bindValue(":matricule",matricule);
    query.bindValue(":type",type);
    query.bindValue(":couleur",couleur);

    return query.exec();

}
