#include "status_dialog.h"
#include "ui_status_dialog.h"
#include "commonhelper.h"

status_dialog::status_dialog(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::status_dialog)
{

	ui->setupUi(this);

}

status_dialog::~status_dialog()
{
	delete ui;
}
