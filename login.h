#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include <QLogin>
#include <QtSql>
#include <QDebug>
#include <QFileInfo>
#include "aluno.h"
#include "professor.h"
#include "notas_aluno.h"
#include "alterar_notas.h"
#include "ui_login.h"

namespace Ui {
class Login;
}

class Login : public QDialog
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();
    int controle = 0;
    QSqlDatabase db_faculdade;
void connClose()
    {
        db_faculdade.close();
        db_faculdade.removeDatabase(QSqlDatabase::defaultConnection);
    }
bool connOpen()
    {
        // Conexão do Banco de dados
        db_faculdade=QSqlDatabase::addDatabase("QSQLITE");
        db_faculdade.setDatabaseName("I:/00.ESTUDOS/SIS_FACULDADE/DataBase/faculdade.db");


        if (!db_faculdade.open()){
            qDebug()<<("Banco de dados Offline");
            return false;

        }else{
            qDebug()<<("Banco de dados Online");
            return true;
        }

    }

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Login *ui;
};

#endif // LOGIN_H
