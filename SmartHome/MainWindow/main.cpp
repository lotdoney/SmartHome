#include "mainwindow.h"
#include <QApplication>
#include <QDesktopWidget> 

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
	w.move((QApplication::desktop()->screen(1)->width() - w.width()) / 2,
		(0));
	w.show();



	return a.exec();

}
