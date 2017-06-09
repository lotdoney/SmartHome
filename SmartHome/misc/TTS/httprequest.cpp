#include "httprequest.h"

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




HttpRequest::HttpRequest()
{
	API_id = "9585891";//百度ID
	API_key = "xEEzSygRBRLUU3LwHMAZ4epu";//百度API Key
	API_secret_key = "d4a4498c47ece3ee4913a3a62a37aeaa";//百度Secret Key
	API_access_token="";

	API_record_format="pcm";
	API_record_HZ="8000";

	API_language="zh";
	API_record_path= QDir::currentPath() + "/qt_code/test.raw";//录音文件的路径

	API_access_token_url = "http://openapi.baidu.com/oauth/2.0/token?grant_type=client_credentials&client_id=";
	API_request_url = "http://vop.baidu.com/server_api?lan=";

	//标志,,第一次http回应要获得 API_access_token 值,第二次(以后)的http回应才是语音识别的返回结果,我把http回应都写到一个方法里,所以要区分一下
	//flag=1是得到API_access_token   flag=0是得到返回的文本

	flag=1;

	manager = new QNetworkAccessManager();

	connect(manager,SIGNAL(finished(QNetworkReply*)),this,SLOT(replyFinish(QNetworkReply*)));

	/*发送http请求,目的是得到 API_access_token口令*/

	manager->get(QNetworkRequest(QUrl(API_access_token_url + API_key + "&client_secret=" + API_secret_key)));

}


void HttpRequest::replyFinish(QNetworkReply * reply)
{
	if(flag==1)
	{
			/*QString all=reply->readAll();
			QJsonParseError jsonError;
			QJsonDocument parse_doucment = QJsonDocument::fromJson(all.toUtf8(), &jsonError);
			qDebug()<<jsonError.error<<endl;
			if(jsonError.error == QJsonParseError::NoError)
			{
			  if(parse_doucment.isObject())
				{
				   QJsonObject jsonObj = parse_doucment.object();
					if(jsonObj.contains("access_token"))
						API_access_token=jsonObj.take("access_token").toString();
				}
			 }*/

			QString strJsonAccess=reply->readAll();//得到http返回的所有信息,这个返回的JSON包所携带的是API_access_token口令

			/*以下是对返回信息(JSON包)进行解析*/
			QScriptValue jsonAccess;
			QScriptEngine engineAccess;
			jsonAccess = engineAccess.evaluate("value = " + strJsonAccess);
			QScriptValueIterator iteratorAccess(jsonAccess);
			while (iteratorAccess.hasNext())
			{

				iteratorAccess.next();

				if(iteratorAccess.name()=="access_token"){
					API_access_token = iteratorAccess.value().toString();//得到 API_access_token,验证是百度用户
					qDebug() << "the API_access_token is " + API_access_token;
				}

			}
			if(API_access_token==""){
				QMessageBox::warning(NULL,"警告","access_token口令获取失败！");
			}
			flag=0;

			reply->deleteLater();//释放
	}
	else{
			QString strJsonText = reply->readAll();//对文本进行解析,这个返回的JSON包所携带的是语音文本

			qDebug() << "the jonsText is " << strJsonText;

			QString strText="";
			QScriptValue jsontext;
			QScriptEngine engineText;
			jsontext = engineText.evaluate("value = " + strJsonText );
			QScriptValueIterator iteratorText(jsontext);

				//读取json数据 直到result项
			while (iteratorText.hasNext()){

				iteratorText.next();
				if(iteratorText.name()=="result"){
					strText = iteratorText.value().toString();

//					ui->label->setText(strText);
					qDebug() << strText;

					ttsText = strText;

					emit requestSuccess();

//					break;
				}
			}
	}
	return ;
}


HttpRequest::~HttpRequest()
{

}

void HttpRequest::getText(QString para_API_id, QString para_API_access_token, QString para_API_language, QString para_API_record_path)
{
	QFile file(para_API_record_path);
	if( !(file.open(QIODevice::ReadOnly)))
	{
		QMessageBox::warning(NULL,"警告","打开语音文件失败！");
		return;
	}
	/*读入文件流*/
	QDataStream in(&file);
	m_buf =new char[file.size()];
	in.readRawData(m_buf,file.size());
	file.close();

	/*发送http请求,目的是得到语音文本*/
	QString  getTextUrl = API_request_url + para_API_language + "&cuid=" + para_API_id + "&token=" + para_API_access_token;
	QUrl url;
	url.setUrl(getTextUrl);
	QNetworkRequest request(url);
	request.setHeader(QNetworkRequest::ContentTypeHeader, "audio/"+API_record_format+";rate="+API_record_HZ);
	QByteArray arr = QByteArray(m_buf, file.size());
	manager->post(request,arr);
}

void HttpRequest::sendRequest()
{
	if(API_access_token == ""){
		qDebug() << "API_access_token got failed!";
	}else {
		getText(API_id,API_access_token,API_language,API_record_path);
	}
}
