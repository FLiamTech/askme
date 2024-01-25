#include "creditosform.h"
#include "ui_creditosform.h"

CreditosForm::CreditosForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CreditosForm)
{
    ui->setupUi(this);

    // Colaboradores de Computación

    ui->cmbColaboradoresUno->addItem("rtufino");
    ui->cmbColaboradoresUno->addItem("FLiam Tech");
    ui->cmbColaboradoresUno->addItem("ArielFLores5");
    ui->cmbColaboradoresUno->addItem("Hayai01");
    ui->cmbColaboradoresUno->addItem("Mayerli12");
    ui->cmbColaboradoresUno->addItem("LuisCOD369");
    ui->cmbColaboradoresUno->addItem("defaultdavr21");
    ui->cmbColaboradoresUno->addItem("EonSoulCout");

    // Colaboradores de Filosofia

    ui->cmbColaboradoresDos->addItem("William Orlando Cárdenas Marin");
    ui->cmbColaboradoresDos->addItem("Jonathan Andrés Analuisa Vargas");
    ui->cmbColaboradoresDos->addItem("Juan Pablo Pauchi Cerda");
    ui->cmbColaboradoresDos->addItem("Jimmy Xavier Zambrano");
    ui->cmbColaboradoresDos->addItem("Félix David Tulcán Coral");
    ui->cmbColaboradoresDos->addItem("Gustavo Rubén Quishpe Ayala");
    ui->cmbColaboradoresDos->addItem("Rómulo Yordan Valera Quispilaya");
    ui->cmbColaboradoresDos->addItem("Jennifer Nicole Játiva Erazo");
}

CreditosForm::~CreditosForm()
{
    delete ui;
}

void CreditosForm::on_pushButton_released()
{
    int index = ui->cmbColaboradoresUno->currentIndex();
    QString URL;
    switch(index)
    {
    case 0:
        URL = "https://github.com/rtufino";
        break;
    case 1:
        URL = "https://github.com/FLiamTech";
        break;
    case 2:
        URL = "https://github.com/ArielFLores5";
        break;
    case 3:
        URL = "https://github.com/Hayai01";
        break;
    case 4:
        URL = "https://github.com/Mayerli12";
        break;
    case 5:
        URL = "https://github.com/LuisCOD369";
        break;
    case 6:
        URL = "https://github.com/defaultdavr21";
        break;
    case 7:
        URL = "https://github.com/EonSoulCout";
        break;

    }

    if(!URL.isEmpty())
    {
        QDesktopServices::openUrl(QUrl(URL));
    }

}

