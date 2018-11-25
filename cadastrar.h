#ifndef CADASTRAR_H
#define CADASTRAR_H

#include <QMainWindow>
#include "ui_cadastrar.h"

namespace Ui {
class Cadastrar;
}

class Cadastrar : public QMainWindow
{
    Q_OBJECT

public:
    explicit Cadastrar(QWidget *parent = nullptr);
    ~Cadastrar();
    Ui::Cadastrar *ui;

private slots:
    void on_pushButton_clicked();

private:

};

#endif // CADASTRAR_H
