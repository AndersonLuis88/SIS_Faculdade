#include "login.h"
#include "ui_login.h"
#include "aluno.h"
#include "QMessageBox"

Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    controle = 0;
}

Login::~Login()
{
    delete ui;
}

void Login::on_pushButton_clicked()
{
    if(ui->lineEdit->text()=="Aluno1"&&ui->lineEdit_2->text()=="123456"){
        this->close();
        controle = 1;
    }
    else{
        QMessageBox::warning(this,"Erro de Autenticação!","<font color=red>Usuário ou Senha Incorreto!");
    }
}

void Login::on_pushButton_2_clicked()
{
    if(ui->lineEdit_3->text()=="Professor1"&&ui->lineEdit_4->text()=="123456"){
        this->close();
        controle = 2;
    }
    else{
        QMessageBox::warning(this,"Erro de Autenticação!","<font color=red>Usuário ou Senha Incorreto!");
    }
}
