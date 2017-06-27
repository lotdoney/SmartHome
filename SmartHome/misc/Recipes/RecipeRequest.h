#ifndef RECIPEREQUEST_H
#define RECIPEREQUEST_H

#include <QObject>
#include <QtNetwork>

class Steps
{
public:

	QString step;
	QString img;
};

class Recipe
{
public :
	QString title;
	QString tags;
	QString imtro;
	QString ingredients;
	QString burden;
	QString albums;
//	QStringList steps;
	Steps steps;
	QList<Steps> stepList;
};

class RecipeRequest : public QObject
{
	Q_OBJECT

public:
	RecipeRequest();

	void getRecipe(QString tmp);
	Recipe mRecipe;

private slots:
	bool replyFinish(QNetworkReply *reply);

private:

	QNetworkAccessManager *manager;

	QString API_secret_key;
	QString API_request_url;

signals:

	void recipeGot();
};

#endif // RECIPEREQUEST_H
