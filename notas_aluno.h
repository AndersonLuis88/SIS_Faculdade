#ifndef NOTAS_ALUNO_H
#define NOTAS_ALUNO_H

#include <QDialog>

namespace Ui {
class Notas_Aluno;
}

class Notas_Aluno : public QDialog
{
    Q_OBJECT

public:
    explicit Notas_Aluno(QWidget *parent = nullptr);
    ~Notas_Aluno();

private:
    Ui::Notas_Aluno *ui;
};

#endif // NOTAS_ALUNO_H
