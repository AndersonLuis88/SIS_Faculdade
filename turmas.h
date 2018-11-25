#ifndef TURMAS_H
#define TURMAS_H

#include <QDialog>

namespace Ui {
class Turmas;
}

class Turmas : public QDialog
{
    Q_OBJECT

public:
    explicit Turmas(QWidget *parent = nullptr);
    ~Turmas();

private:
    Ui::Turmas *ui;
};

#endif // TURMAS_H
