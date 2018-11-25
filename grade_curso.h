#ifndef GRADE_CURSO_H
#define GRADE_CURSO_H

#include <QDialog>

namespace Ui {
class Grade_Curso;
}

class Grade_Curso : public QDialog
{
    Q_OBJECT

public:
    explicit Grade_Curso(QWidget *parent = nullptr);
    ~Grade_Curso();

private:
    Ui::Grade_Curso *ui;
};

#endif // GRADE_CURSO_H
