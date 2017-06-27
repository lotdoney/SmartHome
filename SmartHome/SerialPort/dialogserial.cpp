#include "dialogserial.h"
#include "ui_dialogserial.h"
#include "commonhelper.h"

DialogSerial::DialogSerial(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::DialogSerial)
{
	ui->setupUi(this);
	//	setWindowFlags(Qt::FramelessWindowHint); //把窗口设置成没框架的
	initPort();
	on_pushButtonOpenPort_clicked();

	connect(mSerialPort, SIGNAL(readFinish()), this, SLOT(serialDataDisplay()));// 连接串口数据与显示槽

}

DialogSerial::~DialogSerial()
{
	delete ui;
}
void DialogSerial::initPort()
{
	//读取串口信息
	foreach(const QSerialPortInfo &mPortInfo, QSerialPortInfo::availablePorts()) {
		qDebug() << "Name:" << mPortInfo.portName();
		qDebug() << "Description:" << mPortInfo.description();
		qDebug() << "Manufacturer:" << mPortInfo.manufacturer();
		ui->textBrowser->append(mPortInfo.portName());
		ui->textBrowser->append(mPortInfo.description());
		ui->textBrowser->append(mPortInfo.manufacturer());
		//这里相当于自动识别串口号之后添加到了combobox，如果要手动选择可以用下面列表的方式添加进去
		QSerialPort mSerial;
		mSerial.setPort(mPortInfo);
		if (mSerial.open(QIODevice::ReadWrite))
		{
			//将串口号添加到comboBox
			ui->comboBoxPortName->addItem(mPortInfo.portName());
			//关闭串口等待人为(打开串口按钮)打开
			mSerial.close();
		}
	}

	QStringList baudList;//波特率
	QStringList parityList;//校验位
	QStringList dataBitsList;//数据位
	QStringList stopBitsList;//停止位

	baudList << "1200" << "1800" << "2400" << "4800" << "9600"
		<< "14400" << "19200" << "38400" << "56000" << "57600"
		<< "76800" << "115200" << "128000" << "256000";

	ui->comboBoxBaudRate->addItems(baudList);
	ui->comboBoxBaudRate->setCurrentIndex(11);

	parityList << "无." << "奇校验." << "偶校验.";
	parityList << "标志";
	parityList << "空格";

	ui->comboBoxParity->addItems(parityList);
	ui->comboBoxParity->setCurrentIndex(0);

	dataBitsList << "5" << "6" << "7" << "8";
	ui->comboBoxDataBits->addItems(dataBitsList);
	ui->comboBoxDataBits->setCurrentIndex(3);

	stopBitsList << "1";
	stopBitsList << "1.5";
	stopBitsList << "2";

	ui->comboBoxStopBits->addItems(stopBitsList);
	ui->comboBoxStopBits->setCurrentIndex(0);

}




void DialogSerial::on_pushButtonOpenPort_clicked()
{

	//mSerialPort = new QSerialPort(this);

	//设置串口号
	mSerialPort->setPortName(ui->comboBoxPortName->currentText());
	//以读写方式打开串口
	if (mSerialPort->open(QIODevice::ReadWrite))
	{
		//设置波特率
		mSerialPort->setBaudRate(ui->comboBoxBaudRate->currentText().toInt());
		//设置数据位
		mSerialPort->setDataBits(QSerialPort::Data8);
		//设置校验位
		mSerialPort->setParity(QSerialPort::NoParity);
		//设置流控制
		mSerialPort->setFlowControl(QSerialPort::NoFlowControl);
		//设置停止位
		mSerialPort->setStopBits(QSerialPort::OneStop);

		//每秒读一次
		//			mTimer = new QTimer(this);
		//			connect(mTimer, SIGNAL(timeout()), this, SLOT(readComDataSlot()));
		//			mTimer->start(1000);

		setNonSelectable();
	}
	else
	{
		QApplication::beep();
		QMessageBox::information(this, "提示!", "串口打开失败!");
		return;
	}

}

void DialogSerial::on_pushButtonClosePort_clicked()
{

	if (mSerialPort->isOpen()) {

		mSerialPort->close();
	}

	if (!ui->comboBoxBaudRate->isEnabled())
		setSelectable();
}

void DialogSerial::setSelectable()					//使得下拉框不可点击
{
	ui->comboBoxBaudRate->setEnabled(true);
	ui->comboBoxDataBits->setEnabled(true);
	ui->comboBoxFlowControl->setEnabled(true);
	ui->comboBoxParity->setEnabled(true);
	ui->comboBoxPortName->setEnabled(true);
	ui->comboBoxStopBits->setEnabled(true);
}

void DialogSerial::sleep(unsigned int msec)		//延时函数
{
	QTime dieTime = QTime::currentTime().addMSecs(msec);
	while (QTime::currentTime() < dieTime)
		QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

void DialogSerial::setNonSelectable()
{
	ui->comboBoxBaudRate->setEnabled(false);
	ui->comboBoxDataBits->setEnabled(false);
	ui->comboBoxFlowControl->setEnabled(false);
	ui->comboBoxParity->setEnabled(false);
	ui->comboBoxPortName->setEnabled(false);
	ui->comboBoxStopBits->setEnabled(false);
}

void DialogSerial::on_pushButtonTest_clicked()
{
	if (mSerialPort->isOpen()) {
		return;
	}

	//mSerialPort = new QSerialPort(this);

	ui->labelOpen->setText("unknown");
	ui->labelSetting->setText("unknown");
	ui->labelSend->setText("unknown");
	ui->labelReceive->setText("unknown");
	ui->textBrowser->append("测试串口中..");
	//设置串口号
	mSerialPort->setPortName(ui->comboBoxPortName->currentText());
	//以读写方式打开串口
	if (!mSerialPort->open(QIODevice::ReadWrite)) {

		ui->labelOpen->setText("failed");
		ui->labelSetting->setText("failed");
		ui->labelSend->setText("failed");
		ui->labelReceive->setText("failed");
		ui->textBrowser->append("串口测试失败!");
		return;
	}
	else {

		ui->labelOpen->setText("succeed");
	}
	//设置波特率
	mSerialPort->setBaudRate(ui->comboBoxBaudRate->currentText().toInt());
	//设置数据位
	mSerialPort->setDataBits(QSerialPort::Data8);
	//设置校验位
	mSerialPort->setParity(QSerialPort::NoParity);
	//设置流控制
	mSerialPort->setFlowControl(QSerialPort::NoFlowControl);
	//设置停止位
	mSerialPort->setStopBits(QSerialPort::OneStop);

	ui->labelSetting->setText("succeed");

	if (!mSerialPort->write(QByteArray(ui->lineEditTest->text().toLatin1()))) {
		ui->labelSend->setText("failed");
	}
	else {
		ui->labelSend->setText("succeed");
		ui->textBrowser->append("Send :	" + ui->lineEditTest->text());
	}
	sleep(100);

	if (!mSerialPort->readAll().isEmpty()) {
		ui->textBrowser->append("recevied:	" + mSerialPort->readAll());
		ui->labelReceive->setText("succeed");

	}
	sleep(100);

	if (mSerialPort->isOpen()) {
		mSerialPort->close();
	}
	ui->textBrowser->append("测试完成...");


}

void DialogSerial::on_pushButton_clicked()
{
	this->initPort();
}

void DialogSerial::serialDataDisplay()
{
	if (!serialReceiveData.isEmpty()) {

		foreach(const QString &tmp, serialReceiveData) {		//变量Qlist 每个值赋给tmp
			ui->textBrowser_2->append(tmp);
		}
	}
	if (!serialSendData.isEmpty()) {

		foreach(const QString &tmp, serialSendData) {		//变量Qlist 每个值赋给tmp
			ui->textBrowser_2->append(tmp);
		}
	}
}
