#ifndef PULLWORD_H
#define PULLWORD_H

#include<QtNetwork>
#include <QObject>

namespace Ui {
class PullWord;
}

class PullWord : public QObject
{
	Q_OBJECT

public:

	explicit PullWord(void);

	~PullWord(void);

	void pulld(QString tmpStr);
	void pull(QString tmpStr);

private slots:
	void replyFinish(QNetworkReply *reply);

private:

	QNetworkAccessManager *manager;
	QString API_request_url;


};

#endif // PULLWORD_H
