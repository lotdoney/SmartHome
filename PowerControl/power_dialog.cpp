#include "power_dialog.h"
#include "ui_power_dialog.h"



PowerDialog::PowerDialog(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::PowerDialog)
{
	ui->setupUi(this);
	qDebug() << "power initial start! \n";

	initPlot();
	connect(mSerialPort, SIGNAL(readFinish()), this, SLOT(serialDataProcess()));// 连接串口数据与显示槽
	connect(this, SIGNAL(writeFinish()), mSerialPort, SLOT(slotSendData()));

	connect(ui->horizontalSlider,SIGNAL(valueChanged(int)),this,SLOT(writePowrData()));

//	QTimer *mTimer = new QTimer(this);

//	connect(mTimer,SIGNAL(timeout()),this,SLOT(plotRefrash()));
//	mTimer->start(200);

	startTimer(100);
	qDebug() << "power initial completed";

}

PowerDialog::~PowerDialog()
{
	delete ui;
}

void PowerDialog::plotRefrash()
{

}



void PowerDialog::initPlot()
{
	for(int x=0;x<10;x++)
	{
	   xTime.append((double)x);
	   yPower.append((double)x);
	}


	//设置坐标轴的名称
	ui->qwtPlot->setAxisTitle(QwtPlot::xBottom, "x-> Time");
	ui->qwtPlot->setAxisTitle(QwtPlot::yLeft, "y->");
	//设置坐标轴的范围
//	ui->qwtPlot->setAxisScale(QwtPlot::xBottom, 0.0, 2.0 * M_PI);
//	ui->qwtPlot->setAxisScale(QwtPlot::yLeft, -1.0, 1.0);

	//使用滚轮放大/缩小
	(void) new QwtPlotMagnifier( ui->qwtPlot->canvas() );

	//使用鼠标左键平移
	(void) new QwtPlotPanner( ui->qwtPlot->canvas() );

//QwtPlotCurve *curve 	= new QwtPlotCurve("Acc_X");


	QwtPlotGrid *grid = new QwtPlotGrid;
	grid->enableX( true );//设置网格线
	grid->enableY( true );

	grid->setMajorPen( Qt::white, 0, Qt::DotLine );

	grid->attach( ui->qwtPlot );



	//实例化


	curve.setPen(QColor(Qt::white));
	//加载数据
//	curve.setSamples(time, val, 10);
//	curve.setSamples(xTime,yPower);
	//加到plot，plot由IDE创建

	curve.attach(ui->qwtPlot);
}

void PowerDialog::timerEvent(QTimerEvent *)
{

//	QwtPlotCurve *curve = new QwtPlotCurve("Acc_X");



	curve.attach(ui->qwtPlot);
	curve.setPen(QColor(Qt::white));

	ui->qwtPlot->setAxisScale(QwtPlot::xBottom, xTime.last()-300, xTime.last());

	//所有数据前移移位，首位被覆盖
	xTime.append(xTime.last()+1);

	//最后一位为新数据（这里为随机数模拟）
//	yPower.append(yPower.last());
	yPower.append(rand()%10);


	//重新加载数据
	curve.setSamples(xTime, yPower);

//	qDebug() << yPower.last() << xTime.last();

	//QwtPlot重绘，重要，没有这句不起作用
	ui->qwtPlot->replot();

	//设置状态条的值
	ui->Thermo->setValue(yPower.last());

	//清零向量

	if(xTime.count() > 600)
		xTime.remove(0, 300);

	if(yPower.count() > 600)
		yPower.remove(0,300);

}


void PowerDialog::serialDataProcess()
{
	if(!serialReceiveData.isEmpty()){

		if("powr" == serialReceiveData.at(0)){
			qDebug() << serialReceiveData;
			yPower.append(serialReceiveData.at(1).toDouble());

		}
	}
}

void PowerDialog::writePowrData()
{
	serialSendData.clear();

	serialSendData.append("powr"); // 添加头
	if(ui->horizontalSlider->value() < 10){
		serialSendData.append(QString::number(ui->horizontalSlider->value()));
		/*由于zigbee 判断单字节的数据9的ascii 后面的是 : 所以为10 的时候发送 : 的ascii*/
	}else {
		serialSendData.append(":");
	}

	emit writeFinish();
}

void PowerDialog::writeFansData()
{


}

