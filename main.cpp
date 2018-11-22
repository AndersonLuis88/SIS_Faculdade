#include "aluno.h"
#include "login.h"
#include "professor.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Aluno TelaAluno;
    Login TelaLogin;
    Professor TelaProfessor;
    TelaLogin.exec();
    if(TelaLogin.controle==1){
        TelaAluno.showMaximized();
    }
    else if(TelaLogin.controle==2){
        TelaProfessor.showMaximized();
    }

    return a.exec();
}
