#include "faculdade.h"

Notas_Professor::Notas_Professor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Notas_Professor)
{
    ui->setupUi(this);
    Exibir();
}

Notas_Professor::~Notas_Professor()
{
    delete ui;
}

void Notas_Professor::Exibir(){
    QSqlQuery Tabela;
    cont=0;
        Tabela.prepare("select * from Notas");
        if (Tabela.exec()){

            while(Tabela.next()){
                ui->tableWidget->insertRow(cont);
                ui->tableWidget->setItem(cont,0,new QTableWidgetItem(Tabela.value(0).toString()));
                ui->tableWidget->setItem(cont,1,new QTableWidgetItem(Tabela.value(1).toString()));
                ui->tableWidget->setItem(cont,2,new QTableWidgetItem(Tabela.value(2).toString()));
                ui->tableWidget->setItem(cont,3,new QTableWidgetItem(Tabela.value(3).toString()));
                ui->tableWidget->setItem(cont,4,new QTableWidgetItem(Tabela.value(4).toString()));
                ui->tableWidget->setItem(cont,5,new QTableWidgetItem(Tabela.value(5).toString()));
                cont++;
            }
        }else{
            QMessageBox::warning(this,"ERRO", "Erro ao pesquisar tabela");
        }
        ui->tableWidget->setColumnHidden(0,true);
        ui->tableWidget->setColumnHidden(2,true);
}

void Notas_Professor::on_pushButton_clicked()
{
    QSqlQuery Tabela;
    Tabela.prepare("truncate Notas");
    Tabela.prepare("delete from Notas");
    if(!Tabela.exec()){
        qDebug() << "Falha na definição";
    }else{

        for(int i=0;i<cont;i++){
            Tabela.prepare("select from Notas");
            Tabela.next();
            QString valor1 = ui->tableWidget->takeItem(i,0)->text();
            QString valor2 = ui->tableWidget->takeItem(i,1)->text();
            QString valor3 = ui->tableWidget->takeItem(i,2)->text();
            QString valor4;
            if(ui->checkBox->checkState()==2){
                valor4 = ui->tableWidget->takeItem(i,3)->text();
            }else{
                valor4 = "";
            }
            QString valor5;
            if(ui->checkBox_2->checkState()==2){
                valor5 = ui->tableWidget->takeItem(i,4)->text();
            }else{
                valor5 = "";
            }
            QString valor6;
            if(ui->checkBox_3->checkState()==2){
                valor6 = ui->tableWidget->takeItem(i,5)->text();
            }else{
                valor6 = "";
            }
            QString valor7 = "";
            Tabela.prepare("insert into Notas (Matrícula, Nome, Disciplina, Nota1, Nota2, Nota3, Média) values ('"+valor1+"','"+valor2+"','"+valor3+"','"+valor4+"','"+valor5+"','"+valor6+"','"+valor7+"')");
            if(Tabela.exec()){
                if(i==(Tabela.next()-1)){
                    QMessageBox::information(this,"Confirmação de Registro","Registro Gravado com Sucesso");
                }
            }else{
                qDebug()<<"Erro ao inserir registro";
            }
        }
    }
    for(int i=cont;i>=0;i--){
        ui->tableWidget->removeRow(i);
    }
    Exibir();
    ui->tableWidget->update();
}
