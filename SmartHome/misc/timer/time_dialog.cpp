#include "time_dialog.h"
#include "ui_time_dialog.h"
//#include "commonhelper.h"

Time_Dialog::Time_Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Time_Dialog)
{
    ui->setupUi(this);

	QTimer * timer = new QTimer(this);
	connect(timer,SIGNAL(timeout()),this,SLOT(showTime()));
	timer->start (1000);        //每1000ms刷新一次，即1秒
	showTime();
}

Time_Dialog::~Time_Dialog()
{
	delete ui;
}

void Time_Dialog::showTime()
{
	QTime time = QTime::currentTime ();    //获取系统当前时间
	QString text= time.toString ("hh:mm:ss");     //以时：分：秒 方式显示
//	qDebug() << text;
	ui->lcdNumber->display (text);     //显示LCD文字
}
