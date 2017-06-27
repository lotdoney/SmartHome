#ifndef power_dialog_H
#define power_dialog_H

#include <QDialog>
#include <QVector>
#include <QtMath>
#include <QTimer>
#include <QEvent>

#include <qwt_plot.h>
#include <qwt_plot_curve.h>
#include <qwt_plot_magnifier.h>
#include <qwt_plot_panner.h>
#include <qwt_legend.h>
#include <qwt_dial.h>
#include <qwt_dial_needle.h>
#include <qwt_plot_grid.h>


#include "SerialPort/serial_data.h"



extern QList<QByteArray> serialReceiveData;
extern QStringList serialSendData;
extern SerialPort *mSerialPort;


namespace Ui {
class PowerDialog;
}

class PowerDialog : public QDialog
{
	Q_OBJECT

public:
	explicit PowerDialog(QWidget *parent = 0);
	~PowerDialog();


	void writeTempData();
private slots:
	void plotRefrash();
	void serialDataProcess();
	void writePowrData();

	void writeFansData();
private:
	Ui::PowerDialog *ui;
	void initPlot();
	void timerEvent(QTimerEvent *);

	QVector<double> yPower;
	QVector<double> xTime;
	QwtPlotCurve  curve;

signals:

	void writeFinish();
};

#endif // PowerDialog/power_dialog_H
