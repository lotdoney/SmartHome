#include "light_dialog.h"
#include "ui_light_dialog.h"

Light_Dialog::Light_Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Light_Dialog)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint); //把窗口设置成没框架的
}

Light_Dialog::~Light_Dialog()
{
    delete ui;
}
