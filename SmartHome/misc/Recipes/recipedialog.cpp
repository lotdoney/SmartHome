#include "recipedialog.h"
#include "ui_recipedialog.h"

RecipeDialog::RecipeDialog(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::RecipeDialog)
{
	ui->setupUi(this);
}

RecipeDialog::~RecipeDialog()
{
	delete ui;
}
