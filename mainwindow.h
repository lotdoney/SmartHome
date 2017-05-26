#ifndef MAINWINDOW_H
#define MAINWINDOW_H

//#include "read_thread.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "time_dialog.h"
#include "light_window_dialog.h"
#include "air_dialog.h"
#include "dialogserial.h"


#include <QMainWindow>
#include <QDebug>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QList>

class QToolButton;


extern SerialPort *mSerialPort;


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit MainWindow(QWidget *parent = 0);
	~MainWindow();
public slots:
	void on_toolButton_2_clicked();
	void on_toolButton_3_clicked();
private slots:
	void changeButtonStatus();

private slots:

//	void on_listWidget_clicked(const QModelIndex &index);

	void on_toolButton_1_clicked();

	void on_toolButton_4_clicked();

private:
	QList<QToolButton *> buttons;

	void initButtons();
	Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
