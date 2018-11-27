#include "disciplinas_aluno.h"
#include "ui_disciplinas_aluno.h"
#include <QtSql>
#include <QMessageBox>
#include "mainwindow.h"

Disciplinas_Aluno::Disciplinas_Aluno(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Disciplinas_Aluno)
{
    // Preenche a tabela no construtor com as disciplinas do aluno!
    ui->setupUi(this);
    QSqlQuery query;

    query.prepare("select * from disciplina where fase='1'");
    if(query.exec()){
        int cont=0;
        ui->tw_disci_aluno->setColumnCount(4);
        while(query.next()){
            ui->tw_disci_aluno->insertRow(cont);
            ui->tw_disci_aluno->setItem(cont,0,new QTableWidgetItem(query.value(0).toString()));
            ui->tw_disci_aluno->setItem(cont,1,new QTableWidgetItem(query.value(1).toString()));
            ui->tw_disci_aluno->setItem(cont,2,new QTableWidgetItem(query.value(2).toString()));
            ui->tw_disci_aluno->setItem(cont,3,new QTableWidgetItem(query.value(3).toString()));
            cont++;
        }
    }else{
        QMessageBox::warning(this,"ERRO","Erro na pesquisa, tente novamente");
    }
}

Disciplinas_Aluno::~Disciplinas_Aluno()
{
    delete ui;
}


void Disciplinas_Aluno::on_btn_voltarAlunoDisciplina_clicked()
{
    this->close();
    Aluno f_aluno;
    f_aluno.setModal(true);
    f_aluno.exec();
}
