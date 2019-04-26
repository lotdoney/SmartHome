#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "commonhelper.h"


MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	this->setWindowFlags(Qt::FramelessWindowHint);
	//连接手势信号和槽函数;
	//mCamera = new cameraGet(this);
	//connect(mCamera, SIGNAL(pageChanged(int)), this, SLOT(widgeIndexChanged(int)));
	//connect(mCamera, SIGNAL(callVoice()), this, SLOT(on_pushButtonTTS_clicked()));
	
	connect(mSerialPort, SIGNAL(readFinish()), this, SLOT(serialDataProcess()));// 连接串口数据与显示槽

	//client = new QTcpSocket(this);

	initButtons();
	jsonInit();
	uiInit();

	//startTimer(5000);
	//mCamera->show();
}

MainWindow::~MainWindow()
{
	delete ui;
	//delete mCamera;
}



void MainWindow::initButtons() {
	// 把按钮放在一个list里为了方便管理
	buttons.append(ui->toolButton_1);
	buttons.append(ui->toolButton_2);
	buttons.append(ui->toolButton_3);
	buttons.append(ui->toolButton_4);

	foreach (QToolButton *b, buttons) {
		connect(b, SIGNAL(clicked()), this, SLOT(changeButtonStatus()));
	}

	ui->toolButton_1->setProperty("first", "true"); // 第一个按钮上面的边框不要.
	ui->toolButton_2->click(); // 第二个按钮被按下, 即设置它的current属性为true
}

void MainWindow::changeButtonStatus() {
	// 用按钮的current属性来控制被按下按钮的外观.
	// 当按钮被按下时, 设置其current属性为true,
	// 其他按钮的current属性为false, 为了更新按钮的外观.

	foreach (QToolButton *b, buttons) {
		b->setProperty("current", "false");
		b->setStyleSheet(""); // 刷新按钮的样式
	}
	QToolButton *source = qobject_cast<QToolButton *>(sender());
	source->setProperty("current", "true");
	source->setStyleSheet("");
}




// 这里是对 按钮组的配置,点击之后可以作相应的跳转
void MainWindow::on_toolButton_1_clicked()
{
	ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_toolButton_2_clicked()
{
	ui->stackedWidget->setCurrentIndex(1);
}
void MainWindow::on_toolButton_3_clicked()
{
	ui->stackedWidget->setCurrentIndex(2);
}
void MainWindow::on_toolButton_4_clicked()
{
	ui->stackedWidget->setCurrentIndex(3);
}


void MainWindow::on_pushButtonTTS1_clicked()
{
	client->connectToHost(QHostAddress("192.168.1.1"), 8383);
	if (client->isOpen())
	{
		qDebug() << "connected";
	}
	if (client->isOpen())
	{
		QJsonDocument document;
		document.setArray(json);
		QByteArray byte_array = document.toJson(QJsonDocument::Compact);
		QString json_str(byte_array);
		qDebug() << json_str;

		client->write(json_str.toLatin1().trimmed() + "\n");
		client->close();
	}

}

void MainWindow::on_pushButtonTTS_clicked()
{

	//TTSDialog *mTTS = new TTSDialog();

	//mTTS->setModal(true);
	//mTTS->start();
	//mTTS->exec();
}

void MainWindow::widgeIndexChanged(int pageChange)
{
	if (pageChange == PAGE_LEFT)
	{
		ui->stackedWidget->setCurrentIndex(ui->stackedWidget->currentIndex() - 1);
	} 
	else if (pageChange == PAGE_RIGHT)
	{
		ui->stackedWidget->setCurrentIndex(ui->stackedWidget->currentIndex() + 1);
	}
}

void MainWindow::jsonInit()
{
	json.insert(0, "");
	json.insert(1, "");
	json.insert(2, "");
	json.insert(3, "");
}


void MainWindow::timerEvent(QTimerEvent *)
{
	//client->connectToHost(QHostAddress("192.168.1.1"), 8383);
	//if (client->isOpen())
	//{
	//	qDebug() << "connected";
	//}
	//if (client->isOpen())
	//{
	//	QJsonDocument document;
	//	document.setArray(json);
	//	QByteArray byte_array = document.toJson(QJsonDocument::Compact);
	//	QString json_str(byte_array);
	//	qDebug() << json_str;

	//	client->write(json_str.toLatin1().trimmed() + "\n");
	//	client->close();
	//}
}



void MainWindow::serialDataProcess()
{

	if (!serialReceiveData.isEmpty()) {
		if ("elec" == serialReceiveData.at(0)) {
			if ("p" == serialReceiveData.at(1)) {
				qDebug() << serialReceiveData;
				json.replace(0, serialReceiveData.at(2).toDouble());
			}
			if ("w" == serialReceiveData.at(1)) {
				qDebug() << serialReceiveData;

				//ui->lcdNumber_2->display(serialReceiveData.at(2).toDouble());
			}
		}

		if ("fans" == serialReceiveData.at(0)) {
			qDebug() << serialReceiveData;

			//yFans.append(serialReceiveData.at(1).toDouble());
		}

		if ("temp" == serialReceiveData.at(0)){
			qDebug() << serialReceiveData;
		
			json.replace(1, serialReceiveData.at(1).toDouble());
			json.replace(2, serialReceiveData.at(2).toDouble());

		}
		if ("fans" == serialReceiveData.at(0)){
			json.replace(3, serialReceiveData.at(1).toDouble());
		}
	}

}

void MainWindow::uiInit()
{

	//状态栏添加时钟
	Time_Dialog *time_dialog = new Time_Dialog(this);
	//	ui->verticalLayout->addWidget(time_dialog);
	ui->statusbar->addPermanentWidget(time_dialog);


	status_dialog   *dialogStatue = new status_dialog;
	LightWindowDialog *dialogLight = new LightWindowDialog();
	DialogSerial *dialogSerial = new DialogSerial();

	if (dialogSerial != NULL) {
		qDebug() << "serial initial completed!";
	}
	
	PowerDialog *dialogPower = new PowerDialog(this);
	if (dialogPower != NULL) {
		qDebug() << "power initial completed";
	}
	//air_Dialog *dialogAir = new air_Dialog();

	
	ui->stackedWidget->addWidget(dialogStatue);
	ui->stackedWidget->addWidget(dialogSerial);
	ui->stackedWidget->addWidget(dialogPower);
	ui->stackedWidget->addWidget(dialogLight);
	//ui->stackedWidget->addWidget(dialogAir);

	ui->stackedWidget->setCurrentWidget(dialogStatue);



	ui->statusbar->showMessage("系统运行中!");

}
