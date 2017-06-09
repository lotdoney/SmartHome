#ifndef RECIPEFORMHOME_H
#define RECIPEFORMHOME_H

#include "RecipeRequest.h"
#include <QWidget>

namespace Ui {
class RecipeFormHome;
}

class RecipeFormHome : public QWidget
{
	Q_OBJECT

public:
	explicit RecipeFormHome(QWidget *parent = 0);
	~RecipeFormHome();


	void setContents(Recipe mRecipe);

private:
	Ui::RecipeFormHome *ui;
};

#endif // RECIPEFORMHOME_H
