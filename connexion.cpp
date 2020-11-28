#include "connexion.h"

connexion::connexion()
{

}
bool connexion::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("testprojet");
db.setUserName("amri");//inserer nom de l'utilisateur
db.setPassword("amri");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;





    return  test;
}
