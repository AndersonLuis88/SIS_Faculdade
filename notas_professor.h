#ifndef NOTAS_PROFESSOR_H
#define NOTAS_PROFESSOR_H

#include <QDialog>

namespace Ui {
class Notas_Professor;
}

class Notas_Professor : public QDialog
{
    Q_OBJECT

public:
    explicit Notas_Professor(QWidget *parent = nullptr);
    ~Notas_Professor();
    int cont;
    void Exibir();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Notas_Professor *ui;

};

#endif // NOTAS_PROFESSOR_H
