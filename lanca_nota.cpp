#include "lanca_nota.h"
#include "ui_lanca_nota.h"

Lanca_nota::Lanca_nota(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Lanca_nota)
{
    ui->setupUi(this);
}

Lanca_nota::~Lanca_nota()
{
    delete ui;
}
