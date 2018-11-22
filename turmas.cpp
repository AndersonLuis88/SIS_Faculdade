#include "turmas.h"
#include "ui_turmas.h"

Turmas::Turmas(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Turmas)
{
    ui->setupUi(this);
}

Turmas::~Turmas()
{
    delete ui;
}
