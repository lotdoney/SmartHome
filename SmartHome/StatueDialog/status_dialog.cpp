#include "status_dialog.h"
#include "ui_status_dialog.h"
#include "commonhelper.h"

status_dialog::status_dialog(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::status_dialog)
{

	ui->setupUi(this);

	QFont mFont;
	mFont.setPointSize(18);
	mFont.setFamily("msyh");
	this->setFont(mFont);


	connect(mSerialPort, SIGNAL(readFinish()), this, SLOT(serialDataProcess()));// 连接串口数据与显示槽
	connect(this, SIGNAL(writeFinish()), mSerialPort, SLOT(slotSendData()));

	initPlot();


}

status_dialog::~status_dialog()
{
	delete ui;
}

void status_dialog::serialDataProcess()
{
	if (!serialReceiveData.isEmpty()) {

		if ("temp" == serialReceiveData.at(0)) {

			ui->label_temp_2->setText(serialReceiveData.at(2));
			ui->label_temp->setText(serialReceiveData.at(1));
		}
		if ("fans" == serialReceiveData.at(0))
		{
			qDebug() << serialReceiveData.at(1);

			//ui->lcdNumber_3->display(serialReceiveData.at(1).toInt());

			if (serialReceiveData.at(1).toInt() > 200) {

				writeWindData("+");
			}

			if (serialReceiveData.at(1).toInt() < 50) {

				writeWindData("-");
			}

		}
		if ("siren" == serialReceiveData.at(0))
		{
			if (serialReceiveData.at(1) == "1")
			{
				ui->label_3->setText(" 安全.");
			}
			else
			{
				ui->label_3->setText(" 不安全.");

			}

		}
	}
}



void status_dialog::writeWindData(QString on_off)
{
	serialSendData.clear();
	serialSendData.append("wind"); // 添加头
	serialSendData.append(on_off);

	emit writeFinish();
}

void status_dialog::initPlot()
{
	
	QwtPlotGrid *grid = new QwtPlotGrid;
	grid->enableX(true);//设置网格线
	grid->enableY(true);

	grid->setMajorPen(Qt::white, 0, Qt::DotLine);

	grid->attach(ui->qwtPlot);

}

