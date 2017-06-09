#ifndef RECIPEFORMHOME_H
#define RECIPEFORMHOME_H

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

private:
	Ui::RecipeFormHome *ui;
};

#endif // RECIPEFORMHOME_H
