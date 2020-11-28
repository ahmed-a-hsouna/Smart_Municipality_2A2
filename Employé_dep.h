#ifndef EMPLOYE_DEP_H
#define MACHINES_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class employe
{
public:
    employe();
    employe(int,QString,QString,QString,QString,QString,int,int,QString,QString,QString);
    int getcin(){return CIN;}
     QString getnom(){return nom;}
      QString getprenom(){return prenom;}
       QString getsexe(){return sexe;}
	QString getdate(){return daten;}      	
	 QString getemail(){return email;}      
	  int getnum(){return num;}      
	   int getcode(){return codep;}
	    QString getlieun(){return lieun;}
	     QString getville(){return ville;}
	      QString getadresse(){return adresse;}
bool ajouter();
        QSqlQueryModel * afficher();
        bool supprimer(int);
        bool modifier(int);



    private:
    int CIN,num,code;
    QString nom,prenom,sexe,daten,email,lieun,ville,adresse;
   



};

#endif // MACHINES_H
