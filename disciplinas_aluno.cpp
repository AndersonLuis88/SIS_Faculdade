#include "disciplinas_aluno.h"
#include "ui_disciplinas_aluno.h"

Disciplinas_Aluno::Disciplinas_Aluno(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Disciplinas_Aluno)
{
    ui->setupUi(this);
}

Disciplinas_Aluno::~Disciplinas_Aluno()
{
    delete ui;
}
