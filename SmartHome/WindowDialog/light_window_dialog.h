#ifndef LIGHT_WINDOW_DIALOG_H
#define LIGHT_WINDOW_DIALOG_H

#include <QDialog>
#include "SerialPort/serial_data.h"



extern QList<QByteArray> serialReceiveData;
extern QStringList serialSendData;
extern SerialPort *mSerialPort;


namespace Ui {
class Light_Window_Dialog;
}

class LightWindowDialog : public QDialog
{
    Q_OBJECT

public:
	explicit LightWindowDialog(QWidget *parent = 0);
	~LightWindowDialog();


private:
    Ui::Light_Window_Dialog *ui;

signals:
	void writeFinish();

private slots:	
	void writePowrData();

};

#endif // LIGHT_WINDOW_DIALOG_H
