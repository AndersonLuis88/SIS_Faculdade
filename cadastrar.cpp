#include "faculdade.h"

Cadastrar::Cadastrar(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Cadastrar)
{
    ui->setupUi(this);
}

Cadastrar::~Cadastrar()
{
    delete ui;
}

void Cadastrar::on_pushButton_clicked()
{
    QSqlQuery Tabela;
    this->close();
    QString valor1 = ui->lineEdit->text();
    QString valor2 = ui->lineEdit_2->text();
    QString valor3 = ui->lineEdit_3->text();
    QString valor4 = ui->lineEdit_4->text();
    QString valor5 = ui->lineEdit_5->text();
    QString valor6 = ui->lineEdit_6->text();
    if(ui->label_7->text()=="Cadastro - Novo Aluno"){
        Tabela.prepare("insert into Alunos (Acesso, Senha, Matrícula, CPF, Nome, Endereço) values ('"+valor1+"','"+valor2+"','"+valor3+"','"+valor4+"','"+valor5+"','"+valor6+"')");
        if(Tabela.exec()){

                QMessageBox::information(this,"Confirmação de Registro","Registro Gravado com Sucesso");

        }else{
            qDebug()<<"Erro ao inserir registro";
        }
        Aluno *TelaAluno = new Aluno;
        TelaAluno->setWindowIcon(QIcon("C:/Users/Z400/Desktop/Faculdade/c++.ico"));
        TelaAluno->showMaximized();
    }else{
        Tabela.prepare("insert into Professor (Acesso, Senha, Registro, CPF, Nome, Endereço) values ('"+valor1+"','"+valor2+"','"+valor3+"','"+valor4+"','"+valor5+"','"+valor6+"')");
        if(Tabela.exec()){

                QMessageBox::information(this,"Confirmação de Registro","Registro Gravado com Sucesso");

        }else{
            qDebug()<<"Erro ao inserir registro";
        }
        Professor *TelaProfessor = new Professor;
        TelaProfessor->setWindowIcon(QIcon("C:/Users/Z400/Desktop/Faculdade/c++.ico"));
        TelaProfessor->showMaximized();
    }
}
