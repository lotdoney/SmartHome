#include "light_window_dialog.h"
#include "ui_light_window_dialog.h"
#include "commonhelper.h"

LightWindowDialog::LightWindowDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Light_Window_Dialog)
{
    ui->setupUi(this);

	setWindowFlags(Qt::FramelessWindowHint); //把窗口设置成没框架的
}

LightWindowDialog::~LightWindowDialog()
{
    delete ui;
}
