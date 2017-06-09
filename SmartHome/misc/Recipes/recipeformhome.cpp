#include "recipeformhome.h"
#include "ui_recipeformhome.h"
#include "RecipeRequest.h"

RecipeFormHome::RecipeFormHome(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::RecipeFormHome)
{
	ui->setupUi(this);
	ui->labelTags->setWordWrap(true);

	ui->labelBurden->setWordWrap(true);
}

RecipeFormHome::~RecipeFormHome()
{
	delete ui;
}

void RecipeFormHome::setContents(Recipe mRecipe)
{
	ui->labelTitle->setText(mRecipe.title);
	ui->labelTags->setText(mRecipe.tags);
	ui->labelBurden->setText(mRecipe.burden);
	ui->labelIngred->setText(mRecipe.ingredients);
}
