#include "mainwindow.h"
#include <QApplication>

#include "commonhelper.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

	CommonHelper::setStyle(":/Src/my.qss");

    MainWindow w;
	//flag 设为窗口模式

//	w.setWindowFlags(Qt::Window);
//	w.showFullScreen();

	w.show();
//    Light_Window_Dialog w;
//   Air_Window_Dialog w;
//    Curtain_Window_Dialog w;

    return a.exec();

}
