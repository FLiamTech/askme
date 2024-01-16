#include "listaform.h"
#include "ui_listaform.h"

listaForm::listaForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::listaForm),
    m_asignaturas(nullptr)
{
    ui->setupUi(this);
    connect(ui->cmbAsignaturas, SIGNAL(currentIndexChanged(const QString&)), this, SLOT(cargarTemas()));
    ui->tblTemas->setColumnCount(1);
    QStringList cabecera;
    cabecera << "Temas";
    ui->tblTemas->setHorizontalHeaderLabels(cabecera);
    cargarAsignaturas();
}

listaForm::~listaForm()
{
    delete ui;
}

void listaForm::cargarTemas()
{
    //ui->tblTemas->clearContents();
    ui->tblTemas->rowCount();

    QString nombreAsignatura = ui->cmbAsignaturas->currentText();
    cargarTT(nombreAsignatura);

    if (m_asignaturas)
    {
        Asignatura *asignaturaSeleccionada = nullptr;
        foreach (Asignatura *a, *m_asignaturas)
        {
            if (a->nombre() == nombreAsignatura)
            {
                asignaturaSeleccionada = a;
                break;
            }
        }

        if (asignaturaSeleccionada)
        {
            QList<Tema *> temas = asignaturaSeleccionada->temas();

            int fila = 0;
            foreach (Tema *t, temas)
            {
                ui->tblTemas->insertRow(fila);
                ui->tblTemas->setItem(fila, 0, new QTableWidgetItem(t->nombre()));
                fila++;
            }
        }
    }

    ui->tblTerminos->clearContents();
    ui->tblTerminos->setRowCount(0);
}

void listaForm::setAsignaturas(QList<Asignatura *> *asignaturas)
{
    m_asignaturas = asignaturas;
}

void listaForm::cargarAsignaturas()
{
    ui->cmbAsignaturas->clear();

    if (m_asignaturas)
    {
        foreach(Asignatura *a, *m_asignaturas)
        {
            ui->cmbAsignaturas->addItem(a->nombre());
        }
    }
}

void listaForm::cargarTT(QString nombreAsignatura)
{
    limpiar();

}

void listaForm::limpiar()
{
    ui->tblTemas->clearContents();
    ui->tblTemas->setRowCount(0);

    ui->tblTerminos->clearContents();
    ui->tblTerminos->setRowCount(0);
    ui->tblTerminos->clear();
}
