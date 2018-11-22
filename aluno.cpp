#include "aluno.h"
#include "ui_aluno.h"

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
    TelaNotAluno->showMaximized();
}

void Aluno::on_pushButton_2_clicked()
{
    TelaDiscAluno = new Disciplinas_Aluno(this);
    ui->mdiArea->addSubWindow(TelaDiscAluno);
    TelaDiscAluno->showMaximized();
}

void Aluno::on_pushButton_3_clicked()
{
    TelaGrade = new Grade_Curso(this);
    ui->mdiArea->addSubWindow(TelaGrade);
    TelaGrade->showMaximized();
}

void Aluno::on_pushButton_4_clicked()
{

}
