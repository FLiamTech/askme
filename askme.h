#ifndef ASKME_H
#define ASKME_H

#include <QMainWindow>
#include <QMdiSubWindow>
#include <QFile>
#include <QTextStream>
#include <QFileDialog>

#include <apunteform.h>
#include <asignatura.h>
#include <listaform.h>


QT_BEGIN_NAMESPACE
namespace Ui { class Askme; }
QT_END_NAMESPACE

class Askme : public QMainWindow
{
    Q_OBJECT

public:
    Askme(QWidget *parent = nullptr);
    ~Askme();
public slots:
    void on_apunteTomado(Apunte *apunte);

private:
    Ui::Askme *ui;
    void cargarSubVentana(QWidget *ventana);
    void cargarDatos();
    QList <Asignatura *> m_asignaturas;
    const QString ARCHIVO = "tareas.csv";
    void guardar();
    void cargar();
    void agregarApuntes(Asignatura *a, Tema *t, Apunte *ap);
private slots:
    void on_actionNuevo_triggered();

    void on_actionCargar_triggered();
    void on_actionLista_triggered();
};
#endif // ASKME_H
