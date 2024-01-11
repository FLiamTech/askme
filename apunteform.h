#ifndef APUNTEFORM_H
#define APUNTEFORM_H

#include <QWidget>

#include <asignatura.h>

namespace Ui {
class ApunteForm;
}

class ApunteForm : public QWidget
{
    Q_OBJECT

public:
    explicit ApunteForm(QWidget *parent = nullptr);
    ~ApunteForm();

    const QList<Asignatura *> &asignaturas() const;
    void setAsignaturas( QList<Asignatura *> &newAsignaturas);
    void cargarAsignaturas();
private slots:
    void on_cmbAsignatura_currentIndexChanged(int index);

private:
    Ui::ApunteForm *ui;
    QList<Asignatura *> m_asignaturas;
    void cargarTemas(int asignatura);
};

#endif // APUNTEFORM_H
