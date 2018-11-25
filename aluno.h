#ifndef ALUNO_H
#define ALUNO_H

#include <QMainWindow>
#include "notas_aluno.h"
#include "disciplinas_aluno.h"
#include "grade_curso.h"

namespace Ui {
class Aluno;
}

class Aluno : public QMainWindow
{
    Q_OBJECT

public:
    explicit Aluno(QWidget *parent = nullptr);
    ~Aluno();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::Aluno *ui;
    Notas_Aluno *TelaNotAluno;
    Disciplinas_Aluno *TelaDiscAluno;
    Grade_Curso *TelaGrade;

};

#endif // ALUNO_H
