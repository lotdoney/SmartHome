#include "selectroomdialog.h"
#include "ui_selectroomdialog.h"

SelectRoomDialog::SelectRoomDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SelectRoomDialog)
{
    ui->setupUi(this);
}

SelectRoomDialog::~SelectRoomDialog()
{
    delete ui;
}
