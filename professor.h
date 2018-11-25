#ifndef PROFESSOR_H
#define PROFESSOR_H

#include <QMainWindow>
#include "turmas.h"
#include "alterar_notas.h"


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

    void on_Alterar_Notas_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::Professor *ui;

};

#endif // PROFESSOR_H
