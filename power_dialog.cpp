#include "power_dialog.h"
#include "ui_power_dialog.h"



PowerDialog::PowerDialog(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::PowerDialog)
{
	ui->setupUi(this);
	initPlot();


//	QTimer *mTimer = new QTimer(this);

//	connect(mTimer,SIGNAL(timeout()),this,SLOT(plotRefrash()));
//	mTimer->start(200);

	startTimer(500);





	ui->Thermo->setValue(45);
	ui->Dial->setFocusPolicy(Qt::NoFocus);

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
	//ui->qwtPlot->resize(640,400);
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

	QwtPlotCurve *curve = new QwtPlotCurve("Acc_X");


	QwtPlotGrid *grid = new QwtPlotGrid;
	grid->enableX( true );//设置网格线
	grid->enableY( true );
	grid->setMajorPen( Qt::white, 0, Qt::DotLine );

	grid->attach( ui->qwtPlot );



	//实例化


	curve->setPen(QColor(Qt::white));
	//加载数据
//	curve->setSamples(time, val, 10);
	curve->setSamples(xTime,yPower);
	//加到plot，plot由IDE创建
	curve->attach(ui->qwtPlot);
}

void PowerDialog::timerEvent(QTimerEvent *)
{

	QwtPlotCurve *curve = new QwtPlotCurve("Acc_X");



	curve->attach(ui->qwtPlot);
	curve->setPen(QColor(Qt::white));

	ui->qwtPlot->setAxisScale(QwtPlot::xBottom, xTime.last()-10, xTime.last());

	//所有数据前移移位，首位被覆盖
	xTime.append(xTime.last()+1);

	//最后一位为新数据（这里为随机数模拟）
	yPower.append((double)(qrand()%10));
	//重新加载数据
	curve->setSamples(xTime, yPower);

	qDebug() << yPower.last() << xTime.last();
	//QwtPlot重绘，重要，没有这句不起作用
	ui->qwtPlot->replot();

	ui->Thermo->setValue(yPower.last());

}


