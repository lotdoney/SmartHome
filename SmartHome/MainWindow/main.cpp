#include "mainwindow.h"
#include <QApplication>

#include "commonhelper.h"


int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	CommonHelper::setStyle(":/Res/my.qss");
	QFont mFont;
	mFont.setPointSize(18);
	mFont.setFamily("msyh");
	a.setFont(mFont);

	MainWindow w;
	//flag 设为窗口模式


	//w.setWindowFlags(Qt::Window);

	w.showFullScreen();



	return a.exec();

}
