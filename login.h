#ifndef LOGIN_H
#define LOGIN_H

#include "faculdade.h"

namespace Ui {
class Login;
}

class Login : public QMainWindow
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();
    Ui::Login *ui;
    QSqlDatabase BD;
    void BD_Desconecta()
    {
        BD.close();
        BD.removeDatabase(QSqlDatabase::defaultConnection);
    }

    bool BD_Conecta()
    {
        QSqlDatabase BD = QSqlDatabase::addDatabase("QSQLITE");
        BD.setDatabaseName("C:/Users/Z400/Desktop/Faculdade.db");

        if (!BD.open()){

            return false;
        }
        else{

            return true;
        }
    }


private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:

};

#endif // LOGIN_H
