#include "faculdade.h"

Login::Login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);

    if(!BD_Conecta()){
        ui->label_6->setText("<font size=45><font color=red>•");
        ui->label_7->setText("Banco de Dados Desconectado!");
    }else{
        ui->label_6->setText("<font size=45><font color=green>•");
        ui->label_7->setText("Banco de Dados Conectado com Sucesso!");
    }
}

Login::~Login()
{
    delete ui;
}

bool BD_Procura(int aluno_professor, QString usuario, QString senha)
{
    QSqlQuery Tabela;

    if(aluno_professor==1){
        Tabela.exec("select from Alunos where Acesso='"+usuario+"' and Senha='"+senha+"'");
    }else{
        Tabela.exec("select from Professor where Acesso='"+usuario+"' and Senha='"+senha+"'");
    }
    if(Tabela.exec()){
        while(Tabela.next()){
            if (Tabela.value(0).toString()==usuario&&Tabela.value(1).toString()==senha){
                return true;
            }
        }
    }
    return false;
}

void Login::on_pushButton_clicked()
{
    if(BD_Procura(1,ui->lineEdit->text(),ui->lineEdit_2->text())==true){
        this->close();
        Aluno *TelaAluno = new Aluno;
        TelaAluno->setWindowIcon(QIcon("C:/Users/Z400/Desktop/Faculdade/c++.ico"));
        TelaAluno->showMaximized();
    }
    else{
        QMessageBox::warning(this,"Erro de Autenticação!","<font color=red>Usuário ou Senha Incorreto!");
    }
}

void Login::on_pushButton_2_clicked()
{
    if(BD_Procura(0,ui->lineEdit_3->text(),ui->lineEdit_4->text())==true){
        this->close();
        Professor *TelaProfessor = new Professor;
        TelaProfessor->setWindowIcon(QIcon("C:/Users/Z400/Desktop/Faculdade/c++.ico"));
        TelaProfessor->showMaximized();
    }
    else{
        QMessageBox::warning(this,"Erro de Autenticação!","<font color=red>Usuário ou Senha Incorreto!");
    }
}

void Login::on_pushButton_3_clicked()
{
    this->close();
    Cadastrar *TelaCadastrar = new Cadastrar;
    TelaCadastrar->setWindowIcon(QIcon("C:/Users/Z400/Desktop/Faculdade/c++.ico"));
    TelaCadastrar->ui->lineEdit->setText(ui->lineEdit->text());
    TelaCadastrar->ui->lineEdit_2->setText(ui->lineEdit_2->text());
    TelaCadastrar->show();
}

void Login::on_pushButton_4_clicked()
{
    this->close();
    Cadastrar *TelaCadastrar = new Cadastrar;
    TelaCadastrar->setWindowIcon(QIcon("C:/Users/Z400/Desktop/Faculdade/c++.ico"));
    TelaCadastrar->ui->label_7->setText("Cadastro - Novo Professor");
    TelaCadastrar->ui->label_3->setText("Nº do Registro");
    TelaCadastrar->ui->lineEdit->setText(ui->lineEdit_3->text());
    TelaCadastrar->ui->lineEdit_2->setText(ui->lineEdit_4->text());
    TelaCadastrar->show();
}
