#ifndef READ_THREAD_H
#define READ_THREAD_H

#include "qthread.h"
#include <QSerialPort>
#include <QDebug>
#include "serial_data.h"

extern SerialPort *mSerialPort;

class receiveThread : public QThread
{
	Q_OBJECT

public:
	explicit receiveThread(QObject *parent = 0);
	~receiveThread();
	void run();
	void enStopFlag();
	void enBaudChanged_flag();

	int fd;
	int stop_flag;
	char buff[100];
	int baudChanged_flag;

signals:
void sendbuff(QString );

};


#endif // READ_THREAD_H
