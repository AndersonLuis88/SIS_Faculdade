#ifndef PROFESSOR_H
#define PROFESSOR_H

#include <QDialog>
#include "alterar_notas.h"
#include "ui_alterar_notas.h"
#include "turmas_professor.h"




namespace Ui {
class Professor;
}

class Professor : public QDialog
{
    Q_OBJECT

public:
    explicit Professor(QWidget *parent = nullptr);
    ~Professor();

private slots:


    void on_AlterarNota_clicked();



    void on_btn_turmas_clicked();

    void on_btn_voltaPrincipal_clicked();

private:
    Ui::Professor *ui;
};

#endif // PROFESSOR_H
