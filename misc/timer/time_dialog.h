#ifndef TIME_DIALOG_H
#define TIME_DIALOG_H

#include <QDialog>
#include <QTime>
#include <QTimer>
#include <QDebug>

namespace Ui {
class Time_Dialog;
}

class Time_Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Time_Dialog(QWidget *parent = 0);
    ~Time_Dialog();

private:
    Ui::Time_Dialog *ui;
private slots:

	void showTime();
};

#endif // TIME_DIALOG_H
