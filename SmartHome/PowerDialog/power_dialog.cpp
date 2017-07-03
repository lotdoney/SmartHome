#include "PowerDialog/power_dialog.h"
#include "ui_power_dialog.h"



PowerDialog::PowerDialog(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::PowerDialog)
{
	ui->setupUi(this);
	qDebug() << "power initial start! \n";

	initPlot();


	connect(mSerialPort, SIGNAL(readFinish()), this, SLOT(serialDataProcess()));// 连接串口数据与显示槽
	//connect(this, SIGNAL(writeFinish()), mSerialPort, SLOT(slotSendData()));

	mNeedle = new QwtDialSimpleNeedle(QwtDialSimpleNeedle::Arrow, true, Qt::gray, Qt::darkGray);
	ui->Dial->setNeedle(mNeedle);

//	QTimer *mTimer = new QTimer(this);

//	connect(mTimer,SIGNAL(timeout()),this,SLOT(plotRefrash()));
//	mTimer->start(200);

	startTimer(500);
	qDebug() << "power initial completed";
//	cameraGet *mCamera = new cameraGet();

//	ui->horizontalLayout_4->addWidget(mCamera);

}

PowerDialog::~PowerDialog()
{
	delete ui;
}



void PowerDialog::initPlot()
{
	for (int x = 0; x < 400; x++)
	{
		xTime.append((double)x);
		yPower.append(0);
		yTemp1.append(0);
		yTemp2.append(0); //用于对齐数据
		yFans.append(0);
	}

	ui->qwtPlot_2->setAxisScale(QwtPlot::yLeft, -10, 260);

	



	//设置坐标轴的名称
	ui->qwtPlot->setAxisTitle(QwtPlot::xBottom, "x-> Time");
	ui->qwtPlot->setAxisTitle(QwtPlot::yLeft, "y->");
	//设置坐标轴的范围
//	ui->qwtPlot->setAxisScale(QwtPlot::xBottom, 0.0, 2.0 * M_PI);
//	ui->qwtPlot->setAxisScale(QwtPlot::yLeft, -1.0, 1.0);

	//使用滚轮放大/缩小
//	(void) new QwtPlotMagnifier( ui->qwtPlot->canvas() );

	//使用鼠标左键平移
	//(void) new QwtPlotPanner( ui->qwtPlot->canvas() );



	QwtPlotGrid *grid_1 = new QwtPlotGrid();
	grid_1->enableX( true );//设置网格线
	grid_1->enableY( true );
	grid_1->setMajorPen( Qt::white, 0, Qt::DotLine );


	QwtPlotGrid *grid_2 = new QwtPlotGrid();
	grid_2->enableX(true);//设置网格线
	grid_2->enableY(true);
	grid_2->setMajorPen(Qt::white, 0, Qt::DotLine);

	QwtPlotGrid *grid_3 = new QwtPlotGrid();
	grid_3->enableX(true);//设置网格线
	grid_3->enableY(true);
	grid_3->setMajorPen(Qt::white, 0, Qt::DotLine);

	grid_1->attach( ui->qwtPlot );
	grid_2->attach(ui->qwtPlot_2);
	grid_3->attach(ui->qwtPlot_3);

	curveFans.setPen(QColor(Qt::white));
	curveTemp1.setPen(QColor(Qt::yellow));
	curveTemp2.setPen(QColor(Qt::green));
	curvePower.setPen(QColor(Qt::white));

	curveFans.attach(ui->qwtPlot_2);
	curveTemp2.attach(ui->qwtPlot_3);
	curveTemp1.attach(ui->qwtPlot_3);
	curvePower.attach(ui->qwtPlot);

	//实例化


	
	//加载数据
//	curve.setSamples(time, val, 10);
//	curve.setSamples(xTime,yPower);
	//加到plot，plot由IDE创建

}

void PowerDialog::timerEvent(QTimerEvent *)
{
	//所有数据前移移位，首位被覆盖
	xTime.append(xTime.last() + 1);

	curvePowerRefrash();
	curveTempRefrsh();
	curveFansRefrash();
}

void PowerDialog::curvePowerRefrash()
{

	ui->qwtPlot->setAxisScale(QwtPlot::xBottom, xTime.last() - 300, xTime.last());

	//最后一位为新数据（这里为随机数模拟）
	yPower.append(yPower.last());
	//yPower.append(rand()%10);
	ui->Dial->setValue(yPower.last());

	//重新加载数据
	curvePower.setSamples(xTime, yPower);

		//qDebug() << yPower.last() << xTime.last();

	//QwtPlot重绘，重要，没有这句不起作用
	ui->qwtPlot->replot();

	//设置状态条的值

	//ui->Thermo_2->setValue(yPower.last());

	//清零向量

	if (xTime.count() > 600)
		xTime.remove(200);

	if (yPower.count() > 600)
		yPower.remove(200);

}

void PowerDialog::curveTempRefrsh()
{
	//所有数据前移移位，首位被覆盖



	ui->qwtPlot_3->setAxisScale(QwtPlot::xBottom, xTime.last() - 300, xTime.last());

	yTemp1.append(yTemp1.last());
	yTemp2.append(yTemp2.last());
	//yTemp2.append(rand()%10);
	//yTemp1.append(rand()%10);
	//重新加载数据
	curveTemp1.setSamples(xTime, yTemp1);
	curveTemp2.setSamples(xTime, yTemp2);


	//QwtPlot重绘，重要，没有这句不起作用
	ui->qwtPlot_3->replot();

	//设置状态条的值

	ui->Thermo->setValue(yTemp1.last());

	//清零向量

	if (yTemp1.count() > 600) 
	{
		yTemp1.remove( 200);
		yTemp2.remove( 200);
	}

}



void PowerDialog::curveFansRefrash()
{

	//所有数据前移移位，首位被覆盖
	ui->qwtPlot_2->setAxisScale(QwtPlot::xBottom, xTime.last() - 300, xTime.last());


	//最后一位为新数据（这里为随机数模拟）
	yFans.append(yFans.last());
	//yFans.append(rand()%10);


	//重新加载数据
	curveFans.setSamples(xTime, yFans);


	//QwtPlot重绘，重要，没有这句不起作用
	ui->qwtPlot_2->replot();

	//设置状态条的值

	ui->Thermo_2->setValue(yFans.last());

	//清零向量

	if (yFans.count() > 600)
		yFans.remove(200);
}

void PowerDialog::serialDataProcess()
{
	if (!serialReceiveData.isEmpty())
	{

		if ("elec" == serialReceiveData.at(0))
		{

			if ("p" == serialReceiveData.at(1))
			{
				qDebug() << serialReceiveData;

				yPower.append(serialReceiveData.at(2).toDouble());

			}
			if ("w" == serialReceiveData.at(1))
			{
				qDebug() << serialReceiveData;

				ui->lcdNumber_2->display(serialReceiveData.at(2).toDouble());
			}
		}

		if ("fans" == serialReceiveData.at(0))
		{
			qDebug() << serialReceiveData;

			yFans.append(serialReceiveData.at(1).toDouble());
		}

		if ("temp" == serialReceiveData.at(0))
		{
			qDebug() << serialReceiveData;

			yTemp1.append(serialReceiveData.at(1).toDouble());
			yTemp2.append(serialReceiveData.at(2).toDouble());
		}
	}
}
