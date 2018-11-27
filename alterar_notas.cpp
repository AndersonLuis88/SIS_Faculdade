#include "alterar_notas.h"
#include "ui_alterar_notas.h"
#include <QtSql>
#include <QMessageBox>
#include "mainwindow.h"
#include "faculdade.h"


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

// INICIO DOS MÉTODOS DA CLASSE

// Método para pesquisa das notas, pelo cpf do aluno
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
//  ui->select_materia->setModel(modal);
    conn.connClose();
    qDebug() <<(modal->rowCount());

    QSqlQueryModel * modal2=new QSqlQueryModel();
    conn.connOpen();
    QSqlQuery* qry2=new QSqlQuery(conn.db_faculdade);
    qry2->prepare("select nome from disciplina");
    qry2->exec();
    modal2->setQuery(*qry2);
    ui->comboBox->setModel(modal2);
    conn.connClose();
    qDebug() <<(modal->rowCount());



}

// Método para Inserção/Alteração da Nota 01
void Alterar_Notas::on_Btn_AlterarNota1_clicked()
{
    QString disciplina = ui->comboBox->currentText();
    QString pesquisa=ui->Pesquisa_Aluno_Nota->text();
    QString Nota1Inserir=ui->Nota1Inserir->text();
    MainWindow conn;
    QSqlQueryModel * modal=new QSqlQueryModel();
    conn.connOpen();
    QSqlQuery* qry=new QSqlQuery(conn.db_faculdade);
    qry->prepare("update notas set Nota1='"+Nota1Inserir+"' where id_cpf='"+pesquisa+"' and disciplina='"+disciplina+"'");
    qry->exec();
    modal->setQuery(*qry);
    conn.close();
    qDebug() <<(modal->rowCount());
}

// Método para Inserção/Alteração da Nota 02
void Alterar_Notas::on_Btn_AlterarNota2_clicked()
{
    QString disciplina = ui->comboBox->currentText();
    QString pesquisa=ui->Pesquisa_Aluno_Nota->text();
    QString Nota2Inserir=ui->Nota2Inserir->text();
    MainWindow conn;
    QSqlQueryModel * modal=new QSqlQueryModel();
    conn.connOpen();
    QSqlQuery* qry=new QSqlQuery(conn.db_faculdade);
    qry->prepare("update notas set Nota2='"+Nota2Inserir+"' where id_cpf='"+pesquisa+"' and disciplina='"+disciplina+"'");
    qry->exec();
    modal->setQuery(*qry);
    conn.close();
    qDebug() <<(modal->rowCount());
}

// Método para Inserção/Alteração da Nota 03
void Alterar_Notas::on_Btn_AlterarNota3_clicked()
{
    QString disciplina = ui->comboBox->currentText();
    QString pesquisa=ui->Pesquisa_Aluno_Nota->text();
    QString Nota3Inserir=ui->Nota3Inserir->text();
    MainWindow conn;
    QSqlQueryModel * modal=new QSqlQueryModel();
    conn.connOpen();
    QSqlQuery* qry=new QSqlQuery(conn.db_faculdade);
    qry->prepare("update notas set Nota3='"+Nota3Inserir+"' where id_cpf='"+pesquisa+"' and disciplina='"+disciplina+"'");
    qry->exec();
    modal->setQuery(*qry);
    conn.close();
    qDebug() <<(modal->rowCount());
}

// FIM DOS MÉTODOS DA CLASSE


void Alterar_Notas::on_btn_VoltarProfessorAlterNota_clicked()
{
    this->close();
    Professor f_professor;
    f_professor.setModal(true);
    f_professor.exec();
}
