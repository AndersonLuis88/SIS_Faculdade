#include "professor.h"
#include "ui_professor.h"

Professor::Professor(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Professor)
{
    ui->setupUi(this);
}

Professor::~Professor()
{
    delete ui;
}

void Professor::on_pushButton_clicked()
{
    TelaTurmas = new Turmas(this);
    ui->mdiArea->addSubWindow(TelaTurmas);
    TelaTurmas->showMaximized();
}

void Professor::on_pushButton_2_clicked()
{
    TelaNotas = new Notas_Professor(this);
    ui->mdiArea->addSubWindow(TelaNotas);
    TelaNotas->showMaximized();
}
