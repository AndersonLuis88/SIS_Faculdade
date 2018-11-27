#include "professor.h"
#include "ui_professor.h"
#include <QtSql>
#include <QMessageBox>
#include "mainwindow.h"
#include <QMainWindow>

Professor::Professor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Professor)
{
    ui->setupUi(this);
}

Professor::~Professor()
{
    delete ui;
}


//Referência para a tela de Alterar Notas, quando clicado no botão Alterar Notas
void Professor::on_AlterarNota_clicked()
{

    this->close();
    Alterar_Notas f_altera;
    f_altera.setModal(true);
    f_altera.exec();
}


//Referência para a tela de Turmas Professor, quando clicado no botão Turmas
void Professor::on_btn_turmas_clicked()
{   
    this->close();
    Turmas_Professor f_turma;
    f_turma.setModal(true);
    f_turma.exec();
}



void Professor::on_btn_voltaPrincipal_clicked()
{
    this->close();
}
