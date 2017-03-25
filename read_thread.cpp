#include "read_thread.h"


receiveThread::receiveThread(QObject *parent)
{

}

receiveThread::~receiveThread()
{

}


void receiveThread::run()
{
	QString dataReceive;
	while (1) {
		qDebug() << "thread running";

		while (mSerialPort->waitForReadyRead(1000))
			dataReceive += mSerialPort->readAll();

//		if(dataReceive.toLatin1().indexOf("temp") < 0)
//			continue;

		qDebug() << dataReceive;



		dataReceive.clear();

		/* 线程的相关代码 */

	}
}
