#include "resultadosform.h"
#include "ui_resultadosform.h"

ResultadosForm::ResultadosForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ResultadosForm)
{
    ui->setupUi(this);
}

ResultadosForm::~ResultadosForm()
{
    delete ui;
}
