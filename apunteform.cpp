#include "apunteform.h"
#include "ui_apunteform.h"

ApunteForm::ApunteForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ApunteForm)
{
    ui->setupUi(this);
    connect(ui->cmbAsignatura, SIGNAL(currentIndexChanged(int)), this, SLOT(on_cmbAsignaturas_currentIndexChanged(int)));
}

ApunteForm::~ApunteForm()
{
    delete ui;
}

const QList<Asignatura *> &ApunteForm::asignaturas() const
{
    return m_asignaturas;
}

void ApunteForm::setAsignaturas(QList<Asignatura *> &newAsignaturas)
{
    m_asignaturas = newAsignaturas;
}

void ApunteForm::cargarAsignaturas()
{
    foreach(Asignatura *a, m_asignaturas)
    {
        ui->cmbAsignatura->addItem(a->nombre());
    }
}

void ApunteForm::on_cmbAsignatura_currentIndexChanged(int index)
{
    cargarTemas(index);
}

void ApunteForm::cargarTemas(int asignatura)
{
    ui->cmbClase->clear();
    if(asignatura >= 0 && asignatura < m_asignaturas.size())
    {
        Asignatura *a = m_asignaturas.at(asignatura);
        QList<Tema *> temas = a->temas();
        foreach(Tema *t, temas)
        {
            ui->cmbClase->addItem(t->nombre());
        }
    }
}

