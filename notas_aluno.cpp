#include "notas_aluno.h"
#include "ui_notas_aluno.h"
#include <QtSql>
#include <QMessageBox>
#include "mainwindow.h"

Notas_Aluno::Notas_Aluno(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Notas_Aluno)
{
    ui->setupUi(this);
    ui->setupUi(this);
    MainWindow conn;
    QString pesquisa;
    QSqlQueryModel * modal=new QSqlQueryModel();
    if (!conn.pega()){
        pesquisa = "30000000003";
    }else{
        pesquisa = "40000000004";
    }


    conn.connOpen();
    QSqlQuery* qry=new QSqlQuery(conn.db_faculdade);
    qry->prepare("select * from notas where id_cpf='"+pesquisa+"'");
    qry->exec();
    modal->setQuery(*qry);
    ui->Tv_notas_aluno->setModel(modal);
//  ui->select_materia->setModel(modal);
    conn.connClose();
    qDebug() <<(modal->rowCount());
}

Notas_Aluno::~Notas_Aluno()
{
    delete ui;
}

void Notas_Aluno::on_btn_voltaraluno_clicked()
{
    this->close();
    Aluno f_aluno;
    f_aluno.setModal(true);
    f_aluno.exec();
}
