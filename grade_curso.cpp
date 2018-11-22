#include "grade_curso.h"
#include "ui_grade_curso.h"

Grade_Curso::Grade_Curso(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Grade_Curso)
{
    ui->setupUi(this);
}

Grade_Curso::~Grade_Curso()
{
    delete ui;
}
