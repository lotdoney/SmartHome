#include "recipeformpage.h"
#include "ui_recipeformpage.h"

RecipeFormPage::RecipeFormPage(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::RecipeFormPage)
{
	ui->setupUi(this);
	ui->labelStep->setWordWrap(true);
	time.setHMS(0,10,30);
	time.start();
	QTimer::singleShot(1000, this, SLOT(setTimer()));

}

RecipeFormPage::~RecipeFormPage()
{
	delete ui;
}

void RecipeFormPage::setContents(QString tmp)
{
	ui->labelStep->setText(tmp);

}


void RecipeFormPage::setNetworkImg(const QString &szUrl)
{
	QUrl url(szUrl);
	QNetworkAccessManager manager;
	QEventLoop loop;

	// qDebug() << "Reading picture form " << url;
	QNetworkReply *reply = manager.get(QNetworkRequest(url));
	//请求结束并下载完成后，退出子事件循环
	QObject::connect(reply, SIGNAL(finished()), &loop, SLOT(quit()));
	//开启子事件循环
	loop.exec();

	QByteArray jpegData = reply->readAll();
	QPixmap pixmap;
	pixmap.loadFromData(jpegData);

	pixmap = pixmap.scaled(640, 640);
	ui->labelImg->setPixmap(pixmap); // 你在QLabel显示图片
	qDebug() << ui->labelImg->size();
}

void RecipeFormPage::setTimer()
{
	QString text= time.toString("mm:ss");     //以时：分：秒 方式显示
	//	qDebug() << text;
	ui->lcdNumber->display (text);     //显示LCD文字
}
