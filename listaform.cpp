#include "listaform.h"
#include "ui_listaform.h"

listaForm::listaForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::listaForm)
{
    ui->setupUi(this);
    ui->tblTemas->setColumnCount(4);
    QStringList cabecera;
    cabecera << "Tarea" << "Asignatura" << "Fecha" << "Hora";
}

void listaForm::setAsignaturas(QList<Asignatura *> &asignaturas)
{
    disconnect(ui->cmbAsignaturas, SIGNAL(currentIndexChanged(int)), this, SLOT(on_cmbAsignaturas_currentIndexChanged(int)));
    m_asignaturas = &asignaturas;

    // Cargar las asignaturas en el combo box
    ui->cmbAsignaturas->clear();
    foreach (Asignatura *a, *m_asignaturas)
    {
        ui->cmbAsignaturas->addItem(a->nombre());
    }

    connect(ui->cmbAsignaturas, SIGNAL(currentIndexChanged(int)), this, SLOT(on_cmbAsignaturas_currentIndexChanged(int)));
}

listaForm::~listaForm()
{
    delete ui;
}

void listaForm::on_cmbAsignaturas_currentIndexChanged(int index)
{
    ui->tblTemas->clearContents();
    ui->tblTemas->setRowCount(0);
    ui->tblConceptos->clearContents();
    ui->tblConceptos->setRowCount(0);

    if (index >= 0 && index < m_asignaturas->size())
    {
        Asignatura *asignatura = m_asignaturas->at(index);

        int row = 0;
        foreach (Tema *tema, asignatura->temas())
        {
            ui->tblTemas->insertRow(row);
            ui->tblTemas->setItem(row, 0, new QTableWidgetItem(tema->nombre()));
            ++row;
        }

    }
}
