#ifndef COMMONHELPER_H
#define COMMONHELPER_H


#include <QFile>
#include <QApplication>
#include <QTextStream>
class CommonHelper
{
public:
/*没什么用的，他们的qss直接从mainwindow一套*/
//	static void setStyle(const QString &style, QWidget *widget) {
//		QFile file(style);
//		file.open(QFile::ReadOnly);
//		QTextStream filetext(&file);
//		QString stylesheet = filetext.readAll();
//		widget->setStyleSheet(stylesheet);
//	   file.close();

//	}

	static void setStyle(const QString &style)
	{
			   QFile qss(style);
			   qss.open(QFile::ReadOnly);
			   qApp->setStyleSheet(qss.readAll());
			   qss.close();
	 }

};

#endif // COMMONHELPER_H
