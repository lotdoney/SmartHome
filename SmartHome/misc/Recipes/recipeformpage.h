#ifndef RECIPEFORMPAGE_H
#define RECIPEFORMPAGE_H

#include <QWidget>

namespace Ui {
class RecipeFormPage;
}

class RecipeFormPage : public QWidget
{
	Q_OBJECT

public:
	explicit RecipeFormPage(QWidget *parent = 0);
	~RecipeFormPage();

	void setContents(QString tmp);
private:
	Ui::RecipeFormPage *ui;
};

#endif // RECIPEFORMPAGE_H
