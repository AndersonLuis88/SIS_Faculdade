#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include <QDebug>
#include <QFileInfo>
#include "aluno.h"
#include "professor.h"
#include "notas_aluno.h"
#include "alterar_notas.h"
#include "ui_mainwindow.h"
#include "formulario.h"
#include "QMessageBox"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    QSqlDatabase db_faculdade;
    QString cpf;

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

bool pega()
{
    QString login;
    login = cpf;
    if(login == "10000000001"){
        return true;
    }else{
        return false;
    }
}

bool valida_cpf(){
    int doc = cpf.length();
    qDebug()<<(doc);
    int size=11;
    if(doc != size){
        return false;
    }
    return true;
}


public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
