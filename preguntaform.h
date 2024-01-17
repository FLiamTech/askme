#ifndef PREGUNTAFORM_H
#define PREGUNTAFORM_H

#include <QWidget>

#include <cuestionario.h>

namespace Ui {
class PreguntaForm;
}

class PreguntaForm : public QWidget
{
    Q_OBJECT

public:
    explicit PreguntaForm(QWidget *parent = nullptr);
    ~PreguntaForm();

    void setCuestionario(Cuestionario *newCuestionario);
    void mostrarConceptos();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::PreguntaForm *ui;
    Cuestionario *m_cuestionario;


};

#endif // PREGUNTAFORM_H
