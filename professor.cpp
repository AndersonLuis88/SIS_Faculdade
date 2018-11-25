#include "faculdade.h"

Professor::Professor(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Professor)
{
    ui->setupUi(this);
}

Professor::~Professor()
{
    delete ui;
}

void Professor::on_pushButton_clicked()
{
    TelaTurmas = new Turmas(this);
    ui->mdiArea->addSubWindow(TelaTurmas);
    TelaTurmas->setWindowIcon(QIcon("C:/Users/Z400/Desktop/Faculdade/c++.ico"));
    TelaTurmas->showMaximized();
}

void Professor::on_pushButton_2_clicked()
{
    TelaNotas = new Notas_Professor(this);
    ui->mdiArea->addSubWindow(TelaNotas);
    TelaNotas->setWindowIcon(QIcon("C:/Users/Z400/Desktop/Faculdade/c++.ico"));
    TelaNotas->showMaximized();
}

void Professor::on_pushButton_3_clicked()
{
    QMessageBox::StandardButton verifica;
    verifica = QMessageBox::warning(this,"Confirmação de Saida","Deseja realmente sair do Sistema Professor?",QMessageBox::Ok|QMessageBox::Cancel);
    if( verifica == QMessageBox::Ok) {
        this->close();
        Login *TelaLogin1 = new Login;
        TelaLogin1->setFixedSize(297,300);
        TelaLogin1->setWindowFlag(Qt::WindowMinMaxButtonsHint, false);
        TelaLogin1->setWindowIcon(QIcon("C:/Users/Z400/Desktop/Faculdade/c++.ico"));
        TelaLogin1->ui->label_6->setText("<font size=45><font color=green>•");
        TelaLogin1->ui->label_7->setText("Banco de Dados Conectado com Sucesso!");
        TelaLogin1->show();
    }
}
