#include "AirDialog/air_dialog.h"
#include "ui_air_dialog.h"
#include "SerialPort/serial_data.h"
#include "commonhelper.h"



air_Dialog::air_Dialog(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::air_Dialog)
{
	ui->setupUi(this);

	setWindowFlags(Qt::FramelessWindowHint); //把窗口设置成没框架的

	connect(mSerialPort, SIGNAL(readFinish()), this, SLOT(serialDataProcess()));// 连接串口数据与显示槽

	connect(this->ui->dialTemp, SIGNAL(actionTriggered(int)), this, SLOT(writeTempData()));
	connect(this->ui->dialRh, SIGNAL(actionTriggered(int)), this, SLOT(writeTempData()));

	connect(this, SIGNAL(writeFinish()), mSerialPort, SLOT(slotSendData()));

//	if(mSerialPort->isOpen()){

//		QTimer * timer = new QTimer(this);
//		connect(timer,SIGNAL(timeout()), this, SLOT(serialWriteTemp()));

//		timer->start (5000);        //每1000ms刷新一次，即1秒
//	}




}


air_Dialog::~air_Dialog()
{
	delete ui;
}



void air_Dialog::on_dialTemp_valueChanged(int value)
{
}

void air_Dialog::serialDataProcess()
{
	if(!serialReceiveData.isEmpty()){

		if("temp" == serialReceiveData.at(0)){

			ui->label_temp_2->setText(serialReceiveData.at(2));
			ui->label_temp->setText(serialReceiveData.at(1));
		}
		if("fans" == serialReceiveData.at(0))
		{
			qDebug() << serialReceiveData.at(1);

			ui->lcdNumber_3->display( serialReceiveData.at(1).toInt());

			if(serialReceiveData.at(1).toInt() > 200){

				writeWindData("+");
			}

			if(serialReceiveData.at(1).toInt() < 50){

				writeWindData("-");
			}

		}
	}
}

void air_Dialog::on_dialRh_valueChanged(int value)
{
}


void air_Dialog::writeTempData()
{
	serialSendData.clear();

	serialSendData.append("temp"); // 添加头
	serialSendData.append(QString::number(ui->dialTemp->value()));
	serialSendData.append(QString::number(ui->dialRh->value()));

	emit writeFinish();
}

void air_Dialog::writeWindData(QString on_off)
{
	serialSendData.clear();
	serialSendData.append("wind"); // 添加头
	serialSendData.append(on_off);

	emit writeFinish();
}
