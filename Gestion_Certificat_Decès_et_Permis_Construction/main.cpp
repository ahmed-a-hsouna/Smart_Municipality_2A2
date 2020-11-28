#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include <QDebug>
#include "connexion.h"
#include "fenetre.h"

int main(int argc, char *argv[])
{   
    QApplication a(argc, argv);
        MainWindow w;
        Fenetre f;
        //w.show();
        connexion c;
        bool test=c.createconnect();
        if(test)
        {
            qDebug() <<"connexion reussite";
            f.show();
           // w.show();
            QMessageBox::information(nullptr, QObject::tr("database is open"),
                        QObject::tr("connection successful.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

    }
        else
        {
           qDebug() <<"erreur de connexion";
           f.show();
           QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                        QObject::tr("connection failed.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
}


        return a.exec();
}
