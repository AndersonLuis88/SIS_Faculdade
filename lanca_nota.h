#ifndef LANCA_NOTA_H
#define LANCA_NOTA_H

#include <QDialog>

namespace Ui {
class Lanca_nota;
}

class Lanca_nota : public QDialog
{
    Q_OBJECT

public:
    explicit Lanca_nota(QWidget *parent = nullptr);
    ~Lanca_nota();

private:
    Ui::Lanca_nota *ui;
};

#endif // LANCA_NOTA_H
