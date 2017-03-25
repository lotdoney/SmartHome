#ifndef LIGHT_DIALOG_H
#define LIGHT_DIALOG_H

#include <QDialog>

namespace Ui {
class Light_Dialog;
}

class Light_Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Light_Dialog(QWidget *parent = 0);
    ~Light_Dialog();

private:
    Ui::Light_Dialog *ui;
};

#endif // LIGHT_DIALOG_H
