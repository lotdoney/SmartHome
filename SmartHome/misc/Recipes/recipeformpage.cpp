#include "recipeformpage.h"
#include "ui_recipeformpage.h"

RecipeFormPage::RecipeFormPage(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::RecipeFormPage)
{
	ui->setupUi(this);
}

RecipeFormPage::~RecipeFormPage()
{
	delete ui;
}
