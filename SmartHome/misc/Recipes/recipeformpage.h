#ifndef RECIPEFORMPAGE_H
#define RECIPEFORMPAGE_H

#include <QWidget>
#include <QtNetwork>
#include <QUrl>
#include <QFont>
#include <QTime>
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
	void setNetworkImg(const QString &szUrl);
private:
	Ui::RecipeFormPage *ui;


	QTime time;
private slots:
	void setTimer();
};

#endif // RECIPEFORMPAGE_H
