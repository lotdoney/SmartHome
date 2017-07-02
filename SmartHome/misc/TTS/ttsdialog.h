#ifndef TTSDialog_H
#define TTSDialog_H

#include <QDebug>
#include <QBuffer>
#include <QFile>
#include <QDir>
#include <QAudioInput>
#include <QAudioDeviceInfo>
#include <QTimer>
#include <QMovie>

#include <QDialog>

#include "pullword.h"
#include "httprequest.h"
#include "misc/Recipes/recipedialog.h"

namespace Ui {
class TTSDialog;
}

class TTSDialog : public QDialog
{
	Q_OBJECT

public:
	explicit TTSDialog(QWidget *parent = 0);
	~TTSDialog();


	void setDevice(const QAudioDeviceInfo &device);
	RecipeDialog mRecipeDialog;

private:
	Ui::TTSDialog *ui;

	QFile outputFile;   // class member.
	QAudioInput *m_audioInput = NULL;
	QAudioDeviceInfo m_currentDevice;

	QByteArray m_buf;
	QBuffer *m_buffer = NULL;


	bool initMedia();
	void initGIF();

	HttpRequest mHttpRequest;
	PullWord mPullWord;

public slots:

	bool start(void);
	bool finish(void);

private slots:
	void getText();
	void getWord();

signals:

	void recipeRequested(QString tmp);
};

#endif // TTSDialog_H
