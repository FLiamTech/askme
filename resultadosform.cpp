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

void ResultadosForm::setDatos(Cuestionario *cuestionario)
{
        m_cuestionario = cuestionario;
        cargarDatos();
}

void ResultadosForm::cargarDatos()
{
    float score = m_cuestionario->score();
    QString tema = m_cuestionario->nombreTema();

    QString porcentaje = QString::number(score, 'f', 2) + "%";

    ui->lblScore->setText("Score: " + porcentaje);
    ui->lblTema->setText(tema);

    QList<Pregunta *> preguntas = m_cuestionario->preguntas();

    QList<Pregunta *> preguntasContestadas;
    for (Pregunta *pregunta : preguntas) {
        if (pregunta->respuesta()) {
            preguntasContestadas.append(pregunta);
        }
    }
    ui->tblResultados->setRowCount(preguntas.size());
    ui->tblResultados->setColumnCount(2);

    ui->tblResultados->setHorizontalHeaderLabels({"Termino", "Contestada Correctamente"});

    // Llenar la tabla con los datos de las preguntas
    for (int i = 0; i < preguntasContestadas.size(); ++i)
    {
        QTableWidgetItem *terminoItem = new QTableWidgetItem(preguntas[i]->apunte()->termino());
        QTableWidgetItem *correctoItem = new QTableWidgetItem(preguntas[i]->correcto() ? "😁" : "😞");

        ui->tblResultados->setItem(i, 0, terminoItem);
        ui->tblResultados->setItem(i, 1, correctoItem);
    }
}

void ResultadosForm::on_btnCerrar_released()
{
    this->parentWidget()->close();
}

