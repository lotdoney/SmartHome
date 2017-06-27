#ifndef DIALOGSERIAL_H
#define DIALOGSERIAL_H

#include  "QTime"
#include <QDialog>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QDebug>
#include <QMessageBox>
#include "serial_data.h"

extern QList<QByteArray> serialReceiveData;
extern QStringList serialSendData;

extern SerialPort *mSerialPort;

namespace Ui {
class DialogSerial;
}

class DialogSerial : public QDialog
{
	Q_OBJECT

public:
	explicit DialogSerial(QWidget *parent = 0);
	~DialogSerial();


private slots:

	void serialDataDisplay();

	void on_pushButtonOpenPort_clicked();

	void on_pushButtonClosePort_clicked();

	void on_pushButtonTest_clicked();

	void on_pushButton_clicked();


private:

	void initPort();
	void setNonSelectable();
	void setSelectable();
	void sleep(unsigned int msec);
	Ui::DialogSerial *ui;

};

#endif // DIALOGSERIAL_H
