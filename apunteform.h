#ifndef APUNTEFORM_H
#define APUNTEFORM_H

#include <QWidget>

namespace Ui {
class ApunteForm;
}

class ApunteForm : public QWidget
{
    Q_OBJECT

public:
    explicit ApunteForm(QWidget *parent = nullptr);
    ~ApunteForm();

private:
    Ui::ApunteForm *ui;
};

#endif // APUNTEFORM_H
