#include "mainwindow.h"
#include <QApplication>

#include "commonhelper.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

	CommonHelper::setStyle(":/my.qss");


    MainWindow w;

//    Light_Window_Dialog w;
//   Air_Window_Dialog w;
//    Curtain_Window_Dialog w;
    w.show();

    return a.exec();
}
