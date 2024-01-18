#ifndef RESULTADOSFORM_H
#define RESULTADOSFORM_H

#include <QWidget>

namespace Ui {
class ResultadosForm;
}

class ResultadosForm : public QWidget
{
    Q_OBJECT

public:
    explicit ResultadosForm(QWidget *parent = nullptr);
    ~ResultadosForm();

private:
    Ui::ResultadosForm *ui;
};

#endif // RESULTADOSFORM_H
