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

	QwtPlotGrid *grid = new QwtPlotGrid;
	grid->enableX( true );//设置网格线
	grid->enableY( true );

	grid->setMajorPen( Qt::white, 0, Qt::DotLine );

	grid->attach( ui->qwtPlot );

}

status_dialog::~status_dialog()
{
	delete ui;
}
