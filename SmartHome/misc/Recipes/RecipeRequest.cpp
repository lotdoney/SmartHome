#include <QJsonDocument>
#include <QJsonParseError>
#include <QDebug>
#include <QFileInfo>
#include <QFile>
#include <QMessageBox>
#include <QUrl>

#include <QScriptEngine>
#include <QScriptValue>
#include <QScriptValueIterator>

#include "RecipeRequest.h"

RecipeRequest::RecipeRequest()
{

	API_secret_key = "8d55799ad4cae19fde4e6b0838b9375b";
	API_request_url = "http://apis.juhe.cn/cook/query?";

	manager = new QNetworkAccessManager();

	connect(manager,SIGNAL(finished(QNetworkReply*)),this,SLOT(replyFinish(QNetworkReply*)));



}

bool RecipeRequest::replyFinish(QNetworkReply *reply)
{




	QByteArray jsonText = reply->readAll();

	qDebug() << "jonsText is " << jsonText;

	QString str(jsonText);


	QScriptEngine engine;
	QScriptValue data = engine.evaluate("value=" + str);

	if(data.property("reason").toString()!= "Success")
	{
		QMessageBox::information(NULL, tr("错误."),tr("查询出现错误，请重新查询!"));
		qDebug() << data.property("reason").toString();
		return false;
	}
	qDebug() << "reason is " << data.property("reason").toString();



//	//外层JSOM表达式，翻译结果
//	this->ui->outEdit->setText(sc.property("translation").toString());

	//第二层JSON表达式，网络延伸
	QScriptValue dataResult = data.property("result");

	QScriptValue dataData = dataResult.property("data");


	mRecipe.title = dataData.property(0).property("title").toString();
	mRecipe.tags = dataData.property(0).property("tags").toString();
	mRecipe.imtro = dataData.property(0).property("imtro").toString();
	mRecipe.ingredients = dataData.property(0).property("ingredients").toString();
	mRecipe.albums = dataData.property(0).property("albums").toString();
	mRecipe.burden = dataData.property(0).property("burden").toString();

	if (mRecipe.title == "") {

		qDebug() << "json decode error!";
		return false;
	}



	QScriptValueIterator iteratorText(dataData.property(0).property("steps"));

	//读取json数据 直到result项
	while (iteratorText.hasNext()){

		iteratorText.next();
		mRecipe.steps.step = iteratorText.value().property("step").toString();
		mRecipe.steps.img = iteratorText.value().property("img").toString();


		mRecipe.stepList.append(mRecipe.steps);

	}




	qDebug() << mRecipe.steps.step;
	emit recipeGot();

	return true;

}

void RecipeRequest::getRecipe(QString tmp)
{

	manager->get(QNetworkRequest(QUrl(API_request_url + "key=" + API_secret_key + "&menu=" + tmp + "&rn=1" )));

}
