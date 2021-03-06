#ifndef AIR_DIALOG_H
#define AIR_DIALOG_H

#include <QDialog>


#include <QDialog>
#include "QTimer"
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>

#include "SerialPort/serial_data.h"

extern SerialPort *mSerialPort;
extern QList<QByteArray> serialReceiveData;
extern QStringList serialSendData;



namespace Ui {
class air_Dialog;
}

class air_Dialog : public QDialog
{
	Q_OBJECT

public:
	explicit air_Dialog(QWidget *parent = 0);
	~air_Dialog();

private slots:


	void on_dialTemp_valueChanged(int value);
	void serialDataProcess();
	void on_dialRh_valueChanged(int value);
	void writeTempData();
private:

	Ui::air_Dialog *ui;
	void writeWindData(QString on_off);

signals:

	void writeFinish();

};

#endif // AIR_DIALOG_H
