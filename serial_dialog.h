#ifndef SERIAL_DIALOG_H
#define SERIAL_DIALOG_H

#include  "QTime"
#include <QDialog>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QDebug>
#include <QMessageBox>

extern QSerialPort *mSerialPort;


namespace Ui {
class serial_Dialog;
}

class serial_Dialog : public QDialog
{
	Q_OBJECT

public:
	explicit serial_Dialog(QWidget *parent = 0);
	~serial_Dialog();

//	QSerialPort *mSerialPort;


private slots:

	void on_pushButtonOpenPort_clicked();

	void on_pushButtonClosePort_clicked();

	void on_pushButtonTest_clicked();

private:
	void initPort();
	void setNonSelectable();
	void setSelectable();
	void sleep(unsigned int msec);
	Ui::serial_Dialog *ui;
};

#endif // SERIAL_DIALOG_H
