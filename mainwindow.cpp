#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


        if (!connOpen()){
            ui->label->setText("Banco de dados Offline");

        }else{
            ui->label->setText("Banco de dados Online");
        }

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    // Captura o que foi digitado na tela de Login
    cpf=ui->cx_name->text();
    if(valida_cpf()){
        ui->label->setText("Cpf Válido");
    }else{
        QMessageBox::warning(this,"ERRO","Cpf, Inválido!");

    }

    QString pass=ui->cx_senha->text();

    //Veririca novamente o estado do Banco de dados e interrompe caso não esteja online.
    if(!connOpen()){
        qDebug()<<"Banco de dados Offline";
        return;
    }
    //Faz a consulta no banco do cpf e senha para acesso
    connOpen();
    QSqlQuery qry;
    //Se o acesso for do tipo Pessoa_Professor executa o if
    if(qry.exec("select * from pessoa where id_cpf='"+cpf+"' and senha='"+pass+"' and acesso='0'")){
        int cont=0;
        while(qry.next()){
            cont++;

        }
        //Se encontrar o cpf e senha aciona a próxima janela
        if(cont>0){
            this->close();
            Professor f_professor;
            Aluno f_aluno;
            f_professor.setModal(true);
            f_professor.exec();

        }else{
            //Retorna erro para cpf ou senha não encontrado.
            ui->label->setText("Usuário ou senha incorretos!");
        }
    }
    //Se o acesso for do tipo Pessoa_Aluno executa o if
    if(qry.exec("select * from pessoa where id_cpf='"+cpf+"' and senha='"+pass+"' and acesso='1'")){
        int cont=0;
        while(qry.next()){
            cont++;

        }
        if(cont>0){
            this->close();
            Aluno f_aluno;
            Professor f_professor;
            f_aluno.setModal(true);
            f_aluno.exec();

        }else{
            ui->label->setText("Usuário ou senha incorretos!");
            connClose();
        }
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    this->close();
    Formulario f_formulario;
    f_formulario.setModal(true);
    f_formulario.exec();
}
