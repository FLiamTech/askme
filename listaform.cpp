#include "listaform.h"
#include "ui_listaform.h"

listaForm::listaForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::listaForm),
    m_asignaturas(nullptr)
{
    ui->setupUi(this);
    connect(ui->cmbAsignaturas, SIGNAL(currentIndexChanged(const QString&)), this, SLOT(cargarTemas()));
    connect(ui->tblTemas, SIGNAL(cellClicked(int, int)), this, SLOT(cargarTerminos(int, int)));
    ui->tblTemas->setColumnCount(1);
    ui->tblTerminos->setColumnCount(1);
    QStringList cabecera;
    QStringList cabeceraDos;
    cabecera << "Temas";
    ui->tblTemas->setHorizontalHeaderLabels(cabecera);
    cabeceraDos << "Conceptos";
    ui->tblTerminos->setHorizontalHeaderLabels(cabeceraDos);
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

void listaForm::cargarTerminos(int fila, int columna)
{
    ui->tblTerminos->clearContents();
    ui->tblTerminos->setRowCount(0);
    if (fila >= 0 && columna >= 0)
    {
        QString nombreAsignatura = ui->cmbAsignaturas->currentText();
        QString nombreTema = ui->tblTemas->item(fila, columna)->text();

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
                foreach (Tema *t, temas)
                {
                    if (t->nombre() == nombreTema)
                    {
                        QList<Apunte *> apuntes = t->apuntes();
                        int filaTerminos = 0;
                        foreach (Apunte *ap, apuntes)
                        {
                            ui->tblTerminos->insertRow(filaTerminos);
                            ui->tblTerminos->setItem(filaTerminos, 0, new QTableWidgetItem(ap->termino()));
                            filaTerminos++;
                        }
                        break;
                    }
                }
            }
        }
    }
}

void listaForm::limpiar()
{
    ui->tblTemas->clearContents();
    ui->tblTemas->setRowCount(0);

    ui->tblTerminos->clearContents();
    ui->tblTerminos->setRowCount(0);
    ui->tblTerminos->clear();
}

void listaForm::on_tblTemas_cellClicked(int row, int column)
{
    cargarTerminos(row, column);
}

