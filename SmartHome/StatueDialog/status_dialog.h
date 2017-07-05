#ifndef STATUS_DIALOG_H
#define STATUS_DIALOG_H

#include <QDialog>
#include <qwt_plot.h>
#include <qwt_plot_curve.h>
#include <qwt_plot_magnifier.h>
#include <qwt_plot_panner.h>
#include <qwt_legend.h>
#include <qwt_dial.h>
#include <qwt_dial_needle.h>
#include <qwt_plot_grid.h>
 
#include "SerialPort/serial_data.h"

extern SerialPort *mSerialPort;
extern QList<QByteArray> serialReceiveData;
extern QStringList serialSendData;


namespace Ui {
class status_dialog;
}

class status_dialog : public QDialog
{
	Q_OBJECT

public:
	explicit status_dialog(QWidget *parent = 0);
	~status_dialog();


private slots:
	void serialDataProcess();

private:
	Ui::status_dialog *ui;
	void writeWindData(QString on_off);
	void initPlot();






signals:

	void writeFinish();
};

#endif // STATUS_DIALOG_H
