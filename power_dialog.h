#ifndef POWER_DIALOG_H
#define POWER_DIALOG_H

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
#include <qwt_plot_grid.h>

namespace Ui {
class PowerDialog;
}

class PowerDialog : public QDialog
{
	Q_OBJECT

public:
	explicit PowerDialog(QWidget *parent = 0);
	~PowerDialog();

private slots:
	void plotRefrash();
private:
	Ui::PowerDialog *ui;
	void initPlot();
	void timerEvent(QTimerEvent *);

	QVector<double> yPower;
	QVector<double> xTime;
	QwtPlotCurve * curve;
};

#endif // POWER_DIALOG_H
