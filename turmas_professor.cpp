#include "turmas_professor.h"
#include "ui_turmas_professor.h"
#include <QtSql>
#include <QMessageBox>
#include "mainwindow.h"
#include "faculdade.h"
Turmas_Professor::Turmas_Professor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Turmas_Professor)
{
    ui->setupUi(this);
    MainWindow conn;
    QString pesquisa;
    QSqlQueryModel * modal=new QSqlQueryModel();
    if (!conn.pega()){
        pesquisa = "10000000001";
    }else{
        pesquisa = "20000000002";
    }


    conn.connOpen();
    QSqlQuery* qry=new QSqlQuery(conn.db_faculdade);
    qry->prepare("select * from turmas where professor='"+pesquisa+"'");
    qry->exec();
    modal->setQuery(*qry);
    ui->TV_Turmas_Professor->setModel(modal);
//  ui->select_materia->setModel(modal);
    conn.connClose();
    qDebug() <<(modal->rowCount());
}
Turmas_Professor::~Turmas_Professor()
{
    delete ui;
}




void Turmas_Professor::on_btn_voltaprofessor_clicked()
{
    this->close();
    Professor f_professor;
    f_professor.setModal(true);
    f_professor.exec();
}
