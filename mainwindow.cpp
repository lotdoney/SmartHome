#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "commonhelper.h"
#include "serial_data.h"
#include "power_dialog.h"

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	initButtons();
	Time_Dialog *time_dialog=new Time_Dialog(this);
	ui->verticalLayout->addWidget(time_dialog);


	air_Dialog   *dialogAir=new air_Dialog();
	LightWindowDialog *dialogLight = new LightWindowDialog();
	DialogSerial *dialogSerial = new DialogSerial();
	PowerDialog *dialogPower = new PowerDialog();



	ui->stackedWidget->addWidget(dialogSerial);
	ui->stackedWidget->addWidget(dialogAir);
	ui->stackedWidget->addWidget(dialogLight);
	ui->stackedWidget->addWidget(dialogPower);

	ui->stackedWidget->setCurrentWidget(dialogPower);

//	receiveThread *readThread = new receiveThread(this);	//线程读串口
//	readThread->start();

	ui->statusbar->showMessage("warning!");
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
