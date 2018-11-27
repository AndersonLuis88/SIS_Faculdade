#ifndef ALTERAR_NOTAS_H
#define ALTERAR_NOTAS_H

#include <QDialog>
#include <QTableWidget>
#include <QtSql>
#include "ui_alterar_notas.h"

namespace Ui {
class Alterar_Notas;

}

class Alterar_Notas : public QDialog
{
    Q_OBJECT


public:
    explicit Alterar_Notas(QWidget *parent = nullptr);
    ~Alterar_Notas();


private slots:

    void on_Btn_PesquisaNota_clicked();
    void on_Btn_AlterarNota1_clicked();
    void on_Btn_AlterarNota2_clicked();
    void on_Btn_AlterarNota3_clicked();

    void on_btn_VoltarProfessorAlterNota_clicked();

private:
    Ui::Alterar_Notas *ui;
};

#endif // ALTERAR_NOTAS_H
