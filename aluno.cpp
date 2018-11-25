#include "faculdade.h"

Aluno::Aluno(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Aluno)
{
    ui->setupUi(this);
}

Aluno::~Aluno()
{
    delete ui;
}

void Aluno::on_pushButton_clicked()
{
    TelaNotAluno = new Notas_Aluno(this);
    ui->mdiArea->addSubWindow(TelaNotAluno);
    TelaNotAluno->setWindowIcon(QIcon("C:/Users/Z400/Desktop/Faculdade/c++.ico"));
    TelaNotAluno->showMaximized();
}

void Aluno::on_pushButton_2_clicked()
{
    TelaDiscAluno = new Disciplinas_Aluno(this);
    ui->mdiArea->addSubWindow(TelaDiscAluno);
    TelaDiscAluno->setWindowIcon(QIcon("C:/Users/Z400/Desktop/Faculdade/c++.ico"));
    TelaDiscAluno->showMaximized();
}

void Aluno::on_pushButton_3_clicked()
{
    TelaGrade = new Grade_Curso(this);
    ui->mdiArea->addSubWindow(TelaGrade);
    TelaGrade->setWindowIcon(QIcon("C:/Users/Z400/Desktop/Faculdade/c++.ico"));
    TelaGrade->showMaximized();
}

void Aluno::on_pushButton_4_clicked()
{
    QMessageBox::StandardButton verifica;
    verifica = QMessageBox::warning(this,"Confirmação de Saida","Deseja realmente sair do Sistema Aluno?",QMessageBox::Ok|QMessageBox::Cancel);
    if( verifica == QMessageBox::Ok) {
        this->close();
        Login *TelaLogin = new Login;
        TelaLogin->setFixedSize(297,300);
        TelaLogin->setWindowFlag(Qt::WindowMinMaxButtonsHint, false);
        TelaLogin->setWindowIcon(QIcon("C:/Users/Z400/Desktop/Faculdade/c++.ico"));
        TelaLogin->show();
    }
}
