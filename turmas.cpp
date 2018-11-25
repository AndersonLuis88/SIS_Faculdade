#include "faculdade.h"

Turmas::Turmas(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Turmas)
{
    ui->setupUi(this);
    QSqlQuery Tabela;
        Tabela.prepare("select * from Disciplinas");
        if (Tabela.exec()){
            int cont=0;
            while(Tabela.next()){
                ui->tableWidget->insertRow(cont);
                ui->tableWidget->setItem(cont,0,new QTableWidgetItem(Tabela.value(0).toString()));
                cont++;
            }
        }else{
            QMessageBox::warning(this,"ERRO", "Erro ao pesquisar tabela");
        }
}

Turmas::~Turmas()
{
    delete ui;
}
