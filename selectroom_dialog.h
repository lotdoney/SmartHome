#ifndef SELECTROOM_DIALOG_H
#define SELECTROOM_DIALOG_H

#include <QDialog>

namespace Ui {
class SelectRoom_Dialog;
}

class SelectRoom_Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit SelectRoom_Dialog(QWidget *parent = 0);
    ~SelectRoom_Dialog();

private:
    Ui::SelectRoom_Dialog *ui;
};

#endif // SELECTROOM_DIALOG_H
