#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QList>
#include <QTimer>
#include <QEvent>
#include <QTcpSocket> 

#include "SerialPort/dialogserial.h"
#include "misc/timer/time_dialog.h"
#include "WindowDialog/light_window_dialog.h"
#include "AirDialog/air_dialog.h"
#include "PowerDialog/power_dialog.h"
#include "misc/TTS/TTSDialog.h"
#include "StatueDialog/status_dialog.h"
#include "misc/Camera/cameraget.h"

#include "SerialPort/serial_data.h"

extern SerialPort *mSerialPort;
extern QList<QByteArray> serialReceiveData;
extern QStringList serialSendData;


class QToolButton;
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

	void widgeIndexChanged(int pageChange);
//	void on_listWidget_clicked(const QModelIndex &index);

	void on_toolButton_1_clicked();

	void serialDataProcess();
	void on_toolButton_4_clicked();

	void on_pushButtonTTS1_clicked();

	void on_pushButtonTTS_clicked();


private:

	Ui::MainWindow *ui;
	cameraGet *mCamera;
//	TTSDialog mTTSDialog;
	QList<QToolButton *> buttons;
	QJsonArray json;
	QTcpSocket *client;
	

	void jsonInit();
	void timerEvent(QTimerEvent *);
	void initButtons();
	void uiInit();
};

#endif // MAINWINDOW_H
