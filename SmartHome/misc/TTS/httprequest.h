#ifndef HTTPREQUEST_H
#define HTTPREQUEST_H

#include<QtNetwork>
#include <QObject>

namespace Ui {
class HttpRequest;
}

class HttpRequest : public QObject
{
	Q_OBJECT

public:

	explicit HttpRequest();
	~HttpRequest();

	QString ttsText;
	void sendRequest();

private slots:

	void replyFinish(QNetworkReply *);

private:

	QNetworkAccessManager *manager;
	QNetworkRequest *req;

	QString API_access_token;
	QString API_id;
	QString API_key;
	QString API_secret_key;
	QString API_record_path;
	QString API_record_format;
	QString	API_record_HZ;
	QString API_language; //zh
	QString API_access_token_url;
	QString API_request_url;
	char * m_buf;
	int flag;

	void getText(QString para_API_id, QString para_API_access_token,QString para_API_language, QString para_API_record_path);

signals:

	void requestSuccess();
	void requestFail();
};

#endif // HTTPREQUEST_H
