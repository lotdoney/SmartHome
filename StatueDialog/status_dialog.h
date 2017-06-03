#ifndef STATUS_DIALOG_H
#define STATUS_DIALOG_H

#include <QDialog>

namespace Ui {
class status_dialog;
}

class status_dialog : public QDialog
{
	Q_OBJECT

public:
	explicit status_dialog(QWidget *parent = 0);
	~status_dialog();

private:
	Ui::status_dialog *ui;
};

#endif // STATUS_DIALOG_H
