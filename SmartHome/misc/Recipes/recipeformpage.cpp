#include "recipeformpage.h"
#include "ui_recipeformpage.h"

RecipeFormPage::RecipeFormPage(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::RecipeFormPage)
{
	ui->setupUi(this);
	ui->labelStep->setWordWrap(true);
}

RecipeFormPage::~RecipeFormPage()
{
	delete ui;
}

void RecipeFormPage::setContents(QString tmp)
{
	ui->labelStep->setText(tmp);

}
