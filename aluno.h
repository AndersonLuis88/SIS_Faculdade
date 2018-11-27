#ifndef ALUNO_H
#define ALUNO_H

#include <QDialog>
#include "notas_aluno.h"
#include "disciplinas_aluno.h"

namespace Ui {
class Aluno;
}

class Aluno : public QDialog
{
    Q_OBJECT

public:
    explicit Aluno(QWidget *parent = nullptr);
    ~Aluno();

private slots:
    void on_notas_clicked();

    void on_disciplinas_clicked();

    void on_btn_voltarPrincipal_clicked();

private:
    Ui::Aluno *ui;
};

#endif // ALUNO_H
