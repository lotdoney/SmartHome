#include "mainwindow.h"
#include <QApplication>
#include <QDesktopWidget> 

#include "commonhelper.h"


//
//                       _oo0oo_
//                      o8888888o
//                      88" . "88
//                      (| -_- |)
//                      0\  =  /0
//                    ___/`---'\___
//                  .' \\|     |// '.
//                 / \\|||  :  |||// \
//                / _||||| -:- |||||- \
//               |   | \\\  -  /// |   |
//               | \_|  ''\---/''  |_/ |
//               \  .-\__  '-'  ___/-. /
//             ___'. .'  /--.--\  `. .'___
//          ."" '<  `.___\_<|>_/___.' >' "".
//         | | :  `- \`.;`\ _ /`;.`/ - ` : | |
//         \  \ `_.   \_ __\ /__ _/   .-` /  /
//     =====`-.____`.___ \_____/___.-`___.-'=====
//                       `=---='
//
//
//     ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//
//               佛祖保佑         永无BUG
//
//
//

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QApplication::addLibraryPath("./plugins");
	CommonHelper::setStyle(":/Res/my.qss");
	QFont mFont;
	mFont.setPointSize(18);
	mFont.setFamily("msyh");
	a.setFont(mFont);

	MainWindow w;
	
	//flag 设为窗口模式


	//w.setWindowFlags(Qt::Window);
	w.move((QApplication::desktop()->screen(2)->width() - w.width()) / 2, (0)); 
	w.showFullScreen();



	return a.exec();

}
