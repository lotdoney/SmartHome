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
	tmp = tmp.append("*");
	//加#作为引导符
	mSerialPort->write(tmp.toLatin1());
}

void SerialPort::slotReadData()
{

	QByteArray tmp = mSerialPort->readAll();
	qDebug() << "i got " << tmp;

	if(!tmp.isEmpty())
	{
		byteArray.append(tmp);					//对收到的数据进行缓冲
		qDebug() << "buff is "<< byteArray;

		if(!byteArray.contains('#') || !byteArray.contains('\n') || !byteArray.contains('*')){	//检验是否为完整数据包
			waitForReadyRead(10);			//不是就等待，并返回
			return;
		}

		/*提取最后的一串完整的数据*/
		byteArray = byteArray.right(byteArray.length()-byteArray.lastIndexOf('#')-1);
		//去掉#头
		QList<QByteArray> list = byteArray.trimmed().split('*');//	去掉最后作为结束符的\n
		//分割*
		qDebug() << "finally" << byteArray.trimmed();
		
		serialReceiveData = list;
		serialReceiveData.append(0);
		byteArray.clear();
		emit readFinish();
	}
}
