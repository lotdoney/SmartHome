#include "TTSDialog.h"
#include "ui_TTSDialog.h"
#include <QErrorMessage>
#include <QMessageBox>

TTSDialog::TTSDialog(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::TTSDialog)
{
	//隐藏了标题栏
	this->setWindowFlags(Qt::FramelessWindowHint);

	//设置窗口的透明度
	this->setWindowOpacity(0.5);
//	this->setAttribute(Qt::WA_TranslucentBackground, true);

	ui->setupUi(this);

	initGIF();
	initMedia();

	//录音时间控制
	QTimer::singleShot(3000, this, SLOT(finish()));

	//连接请求成功 和文本读取
	connect(&mHttpRequest, SIGNAL(requestSuccess()), this, SLOT(getText()));
	connect(&mPullWord, SIGNAL(pullWordSuccess()), this, SLOT(getWord()));
	connect(this, SIGNAL(recipeRequested(QString)), &mRecipeDialog, SLOT(readyRecipe(QString)));
	connect(&mHttpRequest, SIGNAL(requestFail()), this, SLOT(Fail()));
}

TTSDialog::~TTSDialog()
{
	delete ui;
}

void TTSDialog::initGIF()
{
	QMovie *movie = new QMovie(":/Res/Gifs/load.gif");
	ui->label->setMovie(movie);
	movie->start();
}




void TTSDialog::setDevice(const QAudioDeviceInfo &device)
{
	m_currentDevice = device;
}

bool TTSDialog::initMedia()
{

	outputFile.setFileName(QDir::currentPath() + "/qt_code/test.raw");
	outputFile.open( QIODevice::ReadWrite | QIODevice::Truncate );
	qDebug() << QDir::currentPath() + "/qt_code/test.raw";

	QList<QAudioDeviceInfo> availableDevices = QAudioDeviceInfo::availableDevices(QAudio::AudioInput);

	foreach (const QAudioDeviceInfo mInfo, QAudioDeviceInfo::availableDevices(QAudio::AudioInput)){
		qDebug()<<"Name:"<<mInfo.deviceName();

	}

	if(!availableDevices.isEmpty())
	{
		m_currentDevice = availableDevices.last();

		QAudioFormat format;
		format.setSampleRate(8000);
		format.setChannelCount(1);
		format.setSampleSize(16);
		format.setSampleType(QAudioFormat::SignedInt);
		format.setByteOrder(QAudioFormat::LittleEndian);
		format.setCodec("audio/pcm");

		//配置format
		if (!m_currentDevice.isFormatSupported(format)) {

			qWarning()<<"default format not supported try to use nearest";
			format = m_currentDevice.nearestFormat(format);
		}
		m_audioInput = new QAudioInput(m_currentDevice, format, this);
	}


	return true;
}



bool TTSDialog::start(void)
{

//    m_buffer = new QBuffer;
//    m_buffer->open(QIODevice::ReadWrite);
//    m_audioInput->start(m_buffer);
	m_audioInput->start(&outputFile);
	qDebug() << "open Device Successed!";

	return true;
}

bool TTSDialog::finish()
{

	m_audioInput->stop();
	outputFile.close();

	delete m_audioInput;

//	HttpRequest *mHttp = new HttpRequest();
//	mHttp->sendRequest();

	mHttpRequest.sendRequest();

	this->close();
	return true;
}

void TTSDialog::Fail(void)
{
	this->close();
	mRecipeDialog.close();
}

//分词
void TTSDialog::getText()
{
	QString tmp = mHttpRequest.ttsText;
	mPullWord.pull(tmp);
//	QMessageBox::information(this,"info",tmp);
}

void TTSDialog::getWord()
{
	//分词没有做

	QString tmp = mPullWord.pullWord;
	qDebug() << tmp;
	emit recipeRequested(tmp);
}
