#include "faculdade.h"

Notas_Aluno::Notas_Aluno(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Notas_Aluno)
{
    ui->setupUi(this);
    QSqlQuery Tabela;
        Tabela.prepare("select * from Notas");
        if (Tabela.exec()){
            int cont=0;
            ui->tableWidget->setColumnCount(5);
            while(Tabela.next()){
                ui->tableWidget->insertRow(cont);
                ui->tableWidget->setItem(cont,0,new QTableWidgetItem(Tabela.value(0).toString()));
                ui->tableWidget->setItem(cont,1,new QTableWidgetItem(Tabela.value(1).toString()));
                ui->tableWidget->setItem(cont,2,new QTableWidgetItem(Tabela.value(2).toString()));
                ui->tableWidget->setItem(cont,3,new QTableWidgetItem(Tabela.value(3).toString()));
                cont++;
            }
        }else{
            QMessageBox::warning(this,"ERRO", "Erro ao pesquisar tabela");
        }
}

Notas_Aluno::~Notas_Aluno()
{
    delete ui;
}
