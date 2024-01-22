#include "creditosform.h"
#include "ui_creditosform.h"

CreditosForm::CreditosForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CreditosForm)
{
    ui->setupUi(this);
    ui->comboBox->addItem("FLiam Tech");
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
        URL = "https://github.com/FLiamTech";
        break;
    }

    if(!URL.isEmpty())
    {
        QDesktopServices::openUrl(QUrl(URL));
    }

}

