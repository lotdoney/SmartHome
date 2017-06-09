#ifndef RECIPEDIALOG_H
#define RECIPEDIALOG_H

#include <QDialog>
#include "RecipeRequest.h"
#include "recipeformhome.h"
#include "recipeformpage.h"

namespace Ui {
class RecipeDialog;
}



class RecipeDialog : public QDialog
{
	Q_OBJECT

public:
	explicit RecipeDialog(QWidget *parent = 0);
	~RecipeDialog();

private:
	Ui::RecipeDialog *ui;
	RecipeRequest mRecipeRequest;
//	RecipeFormHome mRecipeFormHome;
//	RecipeFormPage mRecipeFormPage;

private slots:
	void readyRecipe(QString tmp);
	void readRecipe();

	void on_pushButtonNxt_clicked();
	void on_pushButtonPre_clicked();
};

#endif // RECIPEDIALOG_H
