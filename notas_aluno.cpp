#include "notas_aluno.h"
#include "ui_notas_aluno.h"

Notas_Aluno::Notas_Aluno(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Notas_Aluno)
{
    ui->setupUi(this);
}

Notas_Aluno::~Notas_Aluno()
{
    delete ui;
}
