#include "serial_data.h"
#include "dialogserial.h"

QList<QByteArray> serialReceiveData;

QStringList serialSendData;

SerialPort *mSerialPort = new SerialPort();	//new 一个串口对象嘛



SerialPort::SerialPort(QObject *parent) :
	QSerialPort(parent)
{
	connect(this, SIGNAL(readyRead()), this, SLOT(slotReadData()));
}

SerialPort::~SerialPort()
{

}

void SerialPort::slotSendData()
{
	QString tmp = serialSendData.join('*');
	//list使用*连接
	tmp = tmp.prepend('#');
	//加#作为引导符
	mSerialPort->write(tmp.toLatin1());
}

void SerialPort::slotReadData()
{
	byteArray.clear();
	QByteArray tmp = mSerialPort->readAll();

	if(!tmp.isEmpty())
	{
		byteArray.append(tmp);
		if(byteArray.contains("#"))
		{

			byteArray = byteArray.right(byteArray.length()-byteArray.indexOf('#')-1);
			//去掉#头
			QList<QByteArray> list = byteArray.trimmed().split('*');
			//分割*
			qDebug() << byteArray.trimmed();
			serialReceiveData = list;

		}
	}
}

