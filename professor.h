#ifndef PROFESSOR_H
#define PROFESSOR_H

#include <QMainWindow>
#include "turmas.h"
#include "notas_professor.h"

namespace Ui {
class Professor;
}

class Professor : public QMainWindow
{
    Q_OBJECT

public:
    explicit Professor(QWidget *parent = nullptr);
    ~Professor();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Professor *ui;
    Turmas *TelaTurmas;
    Notas_Professor *TelaNotas;
};

#endif // PROFESSOR_H
