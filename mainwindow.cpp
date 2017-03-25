#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "commonhelper.h"
#include "serial_data.h"


MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	ui->listWidget->setFrameShape(QListWidget::NoFrame);

	Time_Dialog *time_dialog=new Time_Dialog(this);
	ui->verticalLayout->addWidget(time_dialog);


	air_Dialog   *dialogAir=new air_Dialog();
	LightWindowDialog *dialogLight = new LightWindowDialog();
	DialogSerial *dialogSerial = new DialogSerial();



	ui->stackedWidget->addWidget(dialogSerial);
	ui->stackedWidget->addWidget(dialogAir);
	ui->stackedWidget->addWidget(dialogLight);
	ui->stackedWidget->setCurrentIndex(0);

//	receiveThread *readThread = new receiveThread(this);	//线程读串口
//	readThread->start();

	ui->statusbar->showMessage("warning!");
}

MainWindow::~MainWindow()
{
	delete ui;
}



void MainWindow::on_listWidget_clicked(const QModelIndex &index)
{
	qDebug() << index.data().toString() << "clicked";
	QString selected = index.data().toString();
	if("Setting" == selected)
		ui->stackedWidget->setCurrentIndex(0);
	if("Temp" == selected)
		ui->stackedWidget->setCurrentIndex(1);


}
