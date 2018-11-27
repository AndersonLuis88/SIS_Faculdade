#include "aluno.h"
#include "ui_aluno.h"
#include <QtSql>
#include <QMessageBox>
#include "mainwindow.h"
#include <QMainWindow>

Aluno::Aluno(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Aluno)
{
    ui->setupUi(this);
}

Aluno::~Aluno()
{
    delete ui;
}
//Referência para a tela de notas, quando clicado no botão Notas
void Aluno::on_notas_clicked()
{
    this->close();
    Notas_Aluno f_nota;
    f_nota.setModal(true);
    f_nota.exec();
}


//Referência para a tela de notas, quando clicado no botão Diciplinas
void Aluno::on_disciplinas_clicked()
{
    this->close();
    Disciplinas_Aluno f_disciplina_aluno;
    f_disciplina_aluno.setModal(true);
    f_disciplina_aluno.exec();
}

void Aluno::on_btn_voltarPrincipal_clicked()
{
    this->close();
}
