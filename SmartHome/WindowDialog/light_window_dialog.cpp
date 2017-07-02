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

void LightWindowDialog::writePowrData()
{
	serialSendData.clear();

	serialSendData.append("powr"); // 添加头
	if (ui->horizontalSlider->value() < 10) {
		serialSendData.append(QString::number(ui->horizontalSlider->value()));
		/*由于zigbee 判断单字节的数据9的ascii 后面的是 : 所以为10 的时候发送 : 的ascii*/
	}
	else {
		serialSendData.append(":");
	}

	emit writeFinish();
}

