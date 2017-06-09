#include "recipeformhome.h"
#include "ui_recipeformhome.h"

RecipeFormHome::RecipeFormHome(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::RecipeFormHome)
{
	ui->setupUi(this);
}

RecipeFormHome::~RecipeFormHome()
{
	delete ui;
}
