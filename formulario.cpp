#include "formulario.h"
#include "ui_formulario.h"
#include <QtSql>
#include <QMessageBox>
#include "mainwindow.h"

Formulario::Formulario(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Formulario)
{
    ui->setupUi(this);

}

Formulario::~Formulario()
{
    delete ui;
}

void Formulario::on_pushButton_clicked()
{
    MainWindow conn;
    QString cpf,pass,cnpj,nome,acesso;
    conn.cpf = ui->lineEdit->text();
    pass = ui->lineEdit_2->text();
    cnpj = ui->lineEdit_3->text();
    nome = ui->lineEdit_4->text();
    if(ui->checkBox->isChecked()){
        acesso = '0';
    }else{
        acesso= '1';
    }


    if(!conn.connOpen()){
        qDebug()<<"Banco de dados Offline";
        return;
    }
    QSqlQuery query;
    if(conn.valida_cpf()){
        ui->label->setText("Cpf Válido");
        conn.connOpen();
        query.prepare("insert into pessoa (id_cpf, nome, cnpj, acesso, senha) values ('"+cpf+"', '"+nome+"', '"+cnpj+"','"+acesso+"', '"+pass+"'");
    }else{
        QMessageBox::warning(this,"ERRO","Cpf, Inválido!");
        QMessageBox::critical(this,tr("error::"),query.lastError().text());

    }


    if(query.exec( ))
    {
      QMessageBox::critical(this,tr("Save"),tr("Dados Salvos!"));
      conn.connClose();

    }

    qDebug() <<(cpf);
    qDebug() <<(pass);
    qDebug() <<(cnpj);
    qDebug() <<(nome);
    qDebug() <<(acesso);
    qDebug() <<(conn.valida_cpf());
}

void Formulario::on_btn_voltarPrincipa_clicked()
{
    this->close();
    MainWindow *f_main = new MainWindow;
    f_main->show();

}
