#ifndef FORMULARIO_H
#define FORMULARIO_H

#include <QDialog>

namespace Ui {
class Formulario;
}

class Formulario : public QDialog
{
    Q_OBJECT

public:
    explicit Formulario(QWidget *parent = nullptr);
    ~Formulario();
    Ui::Formulario *ui;
private slots:
    void on_pushButton_clicked();

    void on_btn_voltarPrincipa_clicked();

private:

};

#endif // FORMULARIO_H
