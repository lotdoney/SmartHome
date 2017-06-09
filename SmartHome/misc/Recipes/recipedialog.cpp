#include "recipedialog.h"
#include "ui_recipedialog.h"

RecipeDialog::RecipeDialog(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::RecipeDialog)
{
	ui->setupUi(this);

	this->setWindowFlags(Qt::FramelessWindowHint);
	this->setWindowOpacity(0.9);




	connect(&mRecipeRequest, SIGNAL(recipeGot()), this, SLOT(readRecipe()));
}

RecipeDialog::~RecipeDialog()
{
	delete ui;
}

void RecipeDialog::readRecipe()
{
	qDebug() << "dialog got title" << mRecipeRequest.mRecipe.title;

	RecipeFormHome *mRecipeFormHome = new RecipeFormHome();

	mRecipeFormHome->setContents(mRecipeRequest.mRecipe);
	ui->stackedWidget->addWidget(mRecipeFormHome);




	foreach (const QString &tmp, mRecipeRequest.mRecipe.steps) {

		qDebug() << tmp;
		RecipeFormPage *mRecipeFormPage = new RecipeFormPage();
		mRecipeFormPage->setContents(tmp);
		ui->stackedWidget->addWidget(mRecipeFormPage);
	}

	ui->stackedWidget->setCurrentIndex(0);


//	ui->labelTitle->setText(mRecipeRequest.mRecipe.title);
//	ui->labelTags->setText(mRecipeRequest.mRecipe.tags);
//	ui->labelIngred->setText(mRecipeRequest.mRecipe.ingredients);
//	ui->labelBurden->setText(mRecipeRequest.mRecipe.burden);
}

void RecipeDialog::readyRecipe(QString tmp)
{
	mRecipeRequest.getRecipe(tmp);
	this->setModal(true);
	this->exec();
}



void RecipeDialog::on_pushButtonNxt_clicked()
{
	ui->stackedWidget->setCurrentIndex(ui->stackedWidget->currentIndex() + 1);

}

void RecipeDialog::on_pushButtonPre_clicked()
{
	if(ui->stackedWidget->currentIndex() > 0)
		ui->stackedWidget->setCurrentIndex(ui->stackedWidget->currentIndex() - 1);
}
