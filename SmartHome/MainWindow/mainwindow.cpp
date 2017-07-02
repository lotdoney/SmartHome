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
	mCamera = new cameraGet(this);
	connect(mCamera, SIGNAL(pageChanged(int)), this, SLOT(widgeIndexChanged(int)));
	connect(mCamera, SIGNAL(callVoice()), this, SLOT(on_pushButtonTTS_clicked()));

	initButtons();


	Time_Dialog *time_dialog=new Time_Dialog(this);
//	ui->verticalLayout->addWidget(time_dialog);

	//状态栏添加时钟
	ui->statusbar->addPermanentWidget(time_dialog);


	status_dialog   *dialogStatue=new status_dialog;
	LightWindowDialog *dialogLight = new LightWindowDialog();
	DialogSerial *dialogSerial = new DialogSerial();
	qDebug() << "serial initial completed!";
	PowerDialog *dialogPower = new PowerDialog(this);
	qDebug() << "power initial completed";
	//air_Dialog *dialogAir = new air_Dialog();


	ui->stackedWidget->addWidget(dialogStatue);
	ui->stackedWidget->addWidget(dialogSerial);
	ui->stackedWidget->addWidget(dialogPower);
	ui->stackedWidget->addWidget(dialogLight);
	//ui->stackedWidget->addWidget(dialogAir);

	ui->stackedWidget->setCurrentWidget(dialogStatue);



	ui->statusbar->showMessage("warning!");

	mCamera->show();
}

MainWindow::~MainWindow()
{
	delete ui;
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

}

void MainWindow::on_pushButtonTTS_clicked()
{

	TTSDialog *mTTS = new TTSDialog();

	mTTS->setModal(true);
	mTTS->start();
	mTTS->exec();
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
