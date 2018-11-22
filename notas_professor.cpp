#include "notas_professor.h"
#include "ui_notas_professor.h"

Notas_Professor::Notas_Professor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Notas_Professor)
{
    ui->setupUi(this);
}

Notas_Professor::~Notas_Professor()
{
    delete ui;
}
