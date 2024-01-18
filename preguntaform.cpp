#include "preguntaform.h"
#include "ui_preguntaform.h"

PreguntaForm::PreguntaForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PreguntaForm),
    m_cuestionario(nullptr)
{
    ui->setupUi(this);
   // connect(ui->buttonBox, SIGNAL(accepted()), this, SLOT(on_buttonBox_accepted()));
}

PreguntaForm::~PreguntaForm()
{
    delete ui;
}

void PreguntaForm::setCuestionario(Cuestionario *newCuestionario)
{
    m_cuestionario = newCuestionario;
    if (m_cuestionario) {
        ui->lblTema->setText(m_cuestionario->nombreTema());
        ui->cmbTerminos->clear();
        ui->cmbTerminos->addItems(m_cuestionario->terminos());
        mostrarConceptos();
    }
}

void PreguntaForm::mostrarConceptos()
{
    if (m_cuestionario) {
        qDebug() << "Antes de siguiente";
        Pregunta *preguntaActual = m_cuestionario->siguiente();
        qDebug() << "Después de siguiente";
        if (preguntaActual) {
            ui->txtConceptos->setText(preguntaActual->apunte()->concepto());
            ui->txtConceptos->setReadOnly(true);
        } else {
            ui->txtConceptos->clear();
            // ui->buttonBox->setEnabled(false);
            emit preguntasContestadas();
            this->parentWidget()->close();
        }
    }
}

void PreguntaForm::on_buttonBox_accepted()
{
    // Responde la pregunta actual
    QString respuesta = ui->cmbTerminos->currentText();
    if (!respuesta.isEmpty()) {
        Pregunta *preguntaActual = m_cuestionario->siguiente();
        if (preguntaActual) {
            preguntaActual->responder(respuesta);
            mostrarConceptos();
        }
    }
}

void PreguntaForm::siguienteConcepto()
{
    mostrarConceptos();

    disconnect(ui->buttonBox, SIGNAL(accepted()), this, SLOT(siguienteConcepto()));
}
