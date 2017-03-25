#include "selectroom_dialog.h"
#include "ui_selectroom_dialog.h"

SelectRoom_Dialog::SelectRoom_Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SelectRoom_Dialog)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint); //把窗口设置成没框架的
}

SelectRoom_Dialog::~SelectRoom_Dialog()
{
    delete ui;
}
