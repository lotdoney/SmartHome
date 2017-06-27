#ifndef CAMERAGET_H
#define CAMERAGET_H

#include <QMainWindow>

#include <QWidget>
#include <QImage>
#include <QTimer>     // 设置采集数据的间隔时间
#include <QWidget>


#include <opencv/highgui.h>
#include <opencv/cxcore.hpp>
#include <opencv/cvaux.hpp>//必须引此头文件
#include <opencv/cv.hpp>
#include <opencv2/opencv.hpp>

using namespace cv;
namespace Ui {
   class cameraGet;
}

class cameraGet : public QMainWindow
{
   Q_OBJECT

public:
   explicit cameraGet(QWidget *parent = 0);
   ~cameraGet();

private slots:
   void opencamera();      // 打开摄像头
   void readFarme();       // 读取当前帧信息
   void filterCamera();
   void closecamera();     // 关闭摄像头。
   //void takingPictures();  // 拍照

private:
   Ui::cameraGet *ui;
   QTimer    *timer;
   QImage    *imag;
 
   CvCapture* mCam; 
 
   vector< vector<Point> > contours;   // 轮廓  
   vector< vector<Point> > filterContours; // 筛选后的轮廓  
   vector< Vec4i > hierarchy;    // 轮廓的结构信息  
   vector< Point > hull; // 凸包络的点集  
   // 输入视频帧序列 
   Mat frame;
   Mat frameHSV;
   Mat mask;
   Mat dst;

   int delay = 1;
   char c;
   int frameNum = -1;          // Frame counter  
   bool lastImgHasHand = false;

   int previousX = 0;
   int previousY = 0;

   //Size refS = Size( (int) captRefrnc.get(CV_CAP_PROP_FRAME_WIDTH),  
   //  (int) captRefrnc.get(CV_CAP_PROP_FRAME_HEIGHT) );  

   bool bHandFlag = false;


   bool movement = false;
   int count = 0;

   int presentX = 0;
   int presentY = 0;

   //Mat to Qimage
   QImage Mat2QImage(const cv::Mat& mat);
};


#endif // CAMERAGET_H
