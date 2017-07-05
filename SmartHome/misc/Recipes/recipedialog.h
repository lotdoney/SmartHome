#ifndef RECIPEDIALOG_H
#define RECIPEDIALOG_H

#include <QDialog>
#include "RecipeRequest.h"
#include "recipeformhome.h"
#include "recipeformpage.h"

#include "SerialPort/serial_data.h"

extern SerialPort *mSerialPort;
extern QList<QByteArray> serialReceiveData;
extern QStringList serialSendData;

namespace Ui {
class RecipeDialog;
}



class RecipeDialog : public QDialog
{
	Q_OBJECT

public:
	explicit RecipeDialog(QWidget *parent = 0);
	~RecipeDialog();

private:
	Ui::RecipeDialog *ui;
	RecipeRequest mRecipeRequest;
//	RecipeFormHome mRecipeFormHome;
//	RecipeFormPage mRecipeFormPage;
	
	bool isSmartMode();

	bool smartMode;


	void timerEvent(QTimerEvent *);
private slots:
	void readyRecipe(QString tmp);
	void readRecipe();

	void on_pushButtonNxt_clicked();
	void on_pushButtonPre_clicked();

signals:

	void writeFinish();
};

#endif // RECIPEDIALOG_H
