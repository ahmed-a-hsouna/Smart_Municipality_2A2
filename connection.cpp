#include "connection.h"
#include "QSqlDatabase"
connection::connection()
{

}
bool connection::createConnection(){
   bool test=false;
   QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
   db.setDatabaseName("projet");
   db.setUserName("rahmouni");
   db.setPassword("amine");
   if(db.open())
test=true;
return test;
}
