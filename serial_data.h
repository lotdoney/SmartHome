#ifndef SERIAL_DATA_H
#define SERIAL_DATA_H

#include <QDebug>
#include <QSerialPort>



class SerialPort : public QSerialPort
{
	Q_OBJECT

public:
	explicit SerialPort(QObject *parent = 0);
	~SerialPort();

	 QByteArray byteArray;

private slots:

	void slotSendData();
	void slotReadData();

};


#endif // SERIAL_DATA_H
