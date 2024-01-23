#include "creditosform.h"
#include "ui_creditosform.h"

CreditosForm::CreditosForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CreditosForm)
{
    ui->setupUi(this);

    ui->comboBox->addItem("rtufino");
    ui->comboBox->addItem("FLiam Tech");
    ui->comboBox->addItem("ArielFLores5");
    ui->comboBox->addItem("Hayai01");
    ui->comboBox->addItem("Mayerli12");
    ui->comboBox->addItem("LuisCOD369");
    ui->comboBox->addItem("defaultdavr21");
    ui->comboBox->addItem("EonSoulCout");

}

CreditosForm::~CreditosForm()
{
    delete ui;
}

void CreditosForm::on_pushButton_released()
{
    int index = ui->comboBox->currentIndex();
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

