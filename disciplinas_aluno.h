#ifndef DISCIPLINAS_ALUNO_H
#define DISCIPLINAS_ALUNO_H

#include <QDialog>

namespace Ui {
class Disciplinas_Aluno;
}

class Disciplinas_Aluno : public QDialog
{
    Q_OBJECT

public:
    explicit Disciplinas_Aluno(QWidget *parent = nullptr);
    ~Disciplinas_Aluno();

private:
    Ui::Disciplinas_Aluno *ui;
};

#endif // DISCIPLINAS_ALUNO_H
