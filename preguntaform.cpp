#include "preguntaform.h"
#include "ui_preguntaform.h"

PreguntaForm::PreguntaForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PreguntaForm)
{
    ui->setupUi(this);

    connect(ui->buttonBox, SIGNAL(accepted()), this, SLOT(on_buttonBox_accepted()));
}

PreguntaForm::~PreguntaForm()
{
    delete ui;
}

void PreguntaForm::setCuestionario(Cuestionario *newCuestionario)
{
    m_cuestionario = newCuestionario;

    ui->lblTema->setText(m_cuestionario->nombreTema());
    ui->cmbTerminos->addItems(m_cuestionario->terminos());

    mostrarConceptos();
}

void PreguntaForm::mostrarConceptos()
{
    if (m_cuestionario) {
        Pregunta *preguntaActual = m_cuestionario->siguiente();
        if (preguntaActual) {
            ui->txtConceptos->setText(preguntaActual->apunte()->concepto());
            ui->txtConceptos->setReadOnly(true);
        } else {
            // Se llegó al final del cuestionario
            // Puedes hacer algo aquí, como cerrar la ventana o mostrar un mensaje.
        }
    }
}

void PreguntaForm::on_buttonBox_accepted()
{
    mostrarConceptos();
}

