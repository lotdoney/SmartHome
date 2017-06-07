#include "pullword.h"

#include <QJsonDocument>
#include <QJsonParseError>

#include <QScriptEngine>
#include <QScriptValue>
#include <QScriptValueIterator>

PullWord::PullWord(void)
{
	API_request_url = "http://api.pullword.com/get.php?";

	manager = new QNetworkAccessManager();
	connect(manager,SIGNAL(finished(QNetworkReply*)),this,SLOT(replyFinish(QNetworkReply*)));

}

PullWord::~PullWord(void)
{

}


void PullWord::replyFinish(QNetworkReply * reply)
{

	QString result =reply->readAll();//得到http返回的所有信息
	QList<QString> resultList = result.split('\n');



	qDebug() << result;
	return ;
}

//param1 为api 的取词 取出概率最高的词汇 param2 为debug开关 显示每个词概率
void PullWord::pull(QString tmpStr)
{
	manager->get(QNetworkRequest(QUrl(API_request_url + "source=" + tmpStr + "&param1=1" + "&param2=0")));
}



void PullWord::pulld(QString tmpStr)
{
	manager->get(QNetworkRequest(QUrl(API_request_url + "source=" + "毛毛君很胖胖哦" + "&param1=0" + "&param2=1")));
}
