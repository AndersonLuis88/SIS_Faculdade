#ifndef TURMAS_PROFESSOR_H
#define TURMAS_PROFESSOR_H

#include <QDialog>

namespace Ui {
class Turmas_Professor;
}

class Turmas_Professor : public QDialog
{
    Q_OBJECT

public:
    explicit Turmas_Professor(QWidget *parent = nullptr);
    ~Turmas_Professor();

private slots:



    void on_btn_voltaprofessor_clicked();

private:
    Ui::Turmas_Professor *ui;
};

#endif // TURMAS_PROFESSOR_H
