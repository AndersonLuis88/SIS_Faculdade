#include "alterar_notas.h"
#include "ui_alterar_notas.h"
#include <QtSql>
#include <QMessageBox>
#include "mainwindow.h"


Alterar_Notas::Alterar_Notas(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Alterar_Notas)

{
    ui->setupUi(this);






}
Alterar_Notas::~Alterar_Notas()
{
    delete ui;
}






void Alterar_Notas::on_Btn_PesquisaNota_clicked()
{
    QString pesquisa=ui->Pesquisa_Aluno_Nota->text();
    MainWindow conn;
    QSqlQueryModel * modal=new QSqlQueryModel();

    conn.connOpen();
    QSqlQuery* qry=new QSqlQuery(conn.db_faculdade);
    qry->prepare("select * from notas where id_cpf='"+pesquisa+"'");
    qry->exec();
    modal->setQuery(*qry);
    ui->Tv_AlunoNota->setModel(modal);
    conn.connClose();
    qDebug() <<(modal->rowCount());




}
// Função para alterar ou inserir a nota 1 do aluno!
void Alterar_Notas::on_Btn_AlterarNota1_clicked()
{
    QString pesquisa=ui->Pesquisa_Aluno_Nota->text();
    QString Nota1Inserir=ui->Nota1Inserir->text();
    MainWindow conn;
    QSqlQueryModel * modal=new QSqlQueryModel();

    conn.connOpen();
    QSqlQuery* qry=new QSqlQuery(conn.db_faculdade);
    qry->prepare("update notas set Nota1='"+Nota1Inserir+"' where id_cpf='"+pesquisa+"'");
    qry->exec();
    modal->setQuery(*qry);
    conn.close();
    qDebug() <<(modal->rowCount());
}

void Alterar_Notas::on_Btn_AtualizaTabelaNota_clicked()
{
    MainWindow conn;
    QString pesquisa=ui->Pesquisa_Aluno_Nota->text();
    QSqlQueryModel * modal=new QSqlQueryModel();
    conn.connOpen();
    QSqlQuery* qry=new QSqlQuery(conn.db_faculdade);
    qry->prepare("select * notas where id_cpf='"+pesquisa+"'");
    qry->exec();
    modal->setQuery(*qry);
    conn.close();
    qDebug() <<(modal->rowCount());
}
