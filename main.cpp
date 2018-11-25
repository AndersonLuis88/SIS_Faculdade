#include "faculdade.h"

int main(int argc, char *argv[])
{
    QApplication Faculdade(argc, argv);

    Login *TelaLogin = new Login;
    TelaLogin->setFixedSize(297,300);
    TelaLogin->setWindowFlag(Qt::WindowMinMaxButtonsHint, false);
    TelaLogin->setWindowIcon(QIcon("C:/Users/Z400/Desktop/Faculdade/c++.ico"));
    TelaLogin->show();

    return Faculdade.exec();
}
