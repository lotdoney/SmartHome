#include "cameraget.h"
#include "ui_cameraget.h"

#include <QImage>
#include <QDebug>

using namespace cv;

cameraGet::cameraGet(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::cameraGet)
{
	ui->setupUi(this);
	timer   = new QTimer(this);
	imag    = new QImage();         // 初始化

	/*信号和槽*/
	connect(timer, SIGNAL(timeout()), this, SLOT(readFarme()));  // 时间到，读取当前摄像头信息
	connect(ui->open, SIGNAL(clicked()), this, SLOT(opencamera()));
	connect(ui->pic, SIGNAL(clicked()), this, SLOT(takingPictures()));
	connect(ui->closeCam, SIGNAL(clicked()), this, SLOT(closecamera()));
	
	Mat dst(frame);
	Mat mask(frame.rows, frame.cols, CV_8UC1);

	qDebug() << "init completed!";
}

/******************************
********* 打开摄像头 ***********
*******************************/
void cameraGet::opencamera()
{
//	cam = cvCreateCameraCapture(0);//打开摄像头，从摄像头中获取视频
	mCam = NULL;//  
	mCam = cvCaptureFromCAM(0);

	//if(!mCam->){
	//	 qDebug("open cam failed! \n");
	//}

	timer->start(33);              // 开始计时，超时则发出timeout()信号
}

/*********************************
********* 读取摄像头信息 ***********
**********************************/
void cameraGet::readFarme()
{
	frame = cvQueryFrame(mCam); // 从摄像头中抓取并返回每一帧


	//medianBlur(frame, frame, 5);

	// 将抓取到的帧，转换为QImage格式。QImage::Format_RGB888不同的摄像头用不同的格式。
//	QImage image = QImage((const uchar*)frame->imageData, frame->width, frame->height,
//						  QImage::Format_RGB888).rgbSwapped().mirrored(true, false);
	if (frame.empty())
	{
		qDebug() << "get cam failed";
	}
	
	//镜像图片
	QImage image = Mat2QImage(frame).mirrored(true, false);

	ui->label->setPixmap(QPixmap::fromImage(image));  // 将图片显示到label上

	filterCamera();

	contours.clear();
	hierarchy.clear();
	filterContours.clear();
	// 得到手的轮廓  
	findContours(mask, contours, hierarchy, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_SIMPLE);
	// 去除伪轮廓  

	

	for (size_t i = 0; i < contours.size(); i++)
	{
		//  approxPolyDP(Mat(contours[i]), Mat(approxContours[i]), arcLength(Mat(contours[i]), true)*0.02, true);  
		if (fabs(contourArea(Mat(contours[i]))) > 30000) //判断手进入区域的阈值  
		{
			filterContours.push_back(contours[i]);
		}
	}

	// 画轮廓  
	if (filterContours.size() > 0)
	{
		int minX = dst.rows/2;
		int minY = dst.cols/2;

		 
		int maxX = 240;
	
		int maxY = 240;

		count++;
		lastImgHasHand = true;
		drawContours(dst, filterContours, -1, Scalar(255, 0, 255), 3/*, 8, hierarchy*/);

		for (size_t j = 0; j < filterContours.size(); j++)
		{
			convexHull(Mat(filterContours[j]), hull, true);
			int hullcount = (int)hull.size();
			for (int i = 0; i < hullcount - 1; i++)
			{
				line(dst, hull[i + 1], hull[i], Scalar(255, 255, 255), 2, CV_AA);//白色             
				printf("num%d:x=%d\ty=%d\t\n", i, hull[i].x, hull[i].y);
				if (hull[i].x > maxX)
					maxX = hull[i].x;
				if (hull[i].x < minX)
					minX = hull[i].x;
				if (hull[i].y > maxY)
					maxY = hull[i].y;
				if (hull[i].y < minY)
					minY = hull[i].y;
				printf("miniX=%d\tminiY=%d\tmaxX=%d\tmaxY=%d\t\n", minX, minY, maxX, maxY);

			}

			line(dst, hull[hullcount - 1], hull[0], Scalar(0, 255, 0), 2, CV_AA);//绿色，最后一条  

			if (count == 5)//第一个轮廓的中心位置存在全局变量中，到最后一个再跟它比。  
			{
				previousX = (minX + maxX) / 2;
				printf("previousX=%d\n", previousX);
				previousY = (minY + maxY) / 2;
				printf("previousY=%d\n", previousY);
			}
			else
			{
				presentX = (minX + maxY)  / 2;
				presentY = (minY + maxY)  / 2;
			}
		}
	}
	else
	{
		if (lastImgHasHand == true)
		{
			if ((previousX - presentX) < 0)//中文的大括号和英文的大括号用肉眼看不出来，坑啊  
			{
				printf("<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<left\n");//镜像，没有flip过来，所以这里注意点。  
				qDebug() << "Detect  left";
				emit pageChanged(PAGE_LEFT);
			}
			if ((previousX - presentX) > 0)
			{
				printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>right\n");
				qDebug() << "Detect right";
				emit pageChanged(PAGE_RIGHT);
			}
			if ((previousY - presentY) < 0)
			{
				printf("downVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVV\n");
			}
			if ((previousY - presentY) > 0)
			{
				printf("upAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAa\n");
			}

			count = 0;
			lastImgHasHand = false;
		}
	}
	QImage image2 = Mat2QImage(dst).mirrored(true, false);
	ui->label_2->setPixmap(QPixmap::fromImage(image2));
	dst.release();

}

void cameraGet::filterCamera()
{

	// 中值滤波，去除椒盐噪声
	medianBlur(frame, frame, 5);
	cvtColor(frame, frameHSV, CV_BGR2HSV);

	Mat dstTemp1(frame.rows, frame.cols, CV_8UC1);
	Mat dstTemp2(frame.rows, frame.cols, CV_8UC1);


	// 对HSV空间进行量化，得到2值图像，亮的部分为手的形状  
	//选取手的颜色范围
	inRange(frameHSV, Scalar(0, 30, 30), Scalar(40, 170, 256), dstTemp1);
	inRange(frameHSV, Scalar(156, 30, 30), Scalar(180, 170, 256), dstTemp2);
	bitwise_or(dstTemp1, dstTemp2, mask);
	//  inRange(frameHSV, Scalar(0,30,30), Scalar(180,170,256), dst);    

	// 形态学操作，去除噪声，并使手的边界更加清晰  
	Mat element = getStructuringElement(MORPH_RECT, Size(3, 3));
	erode(mask, mask, element);
	morphologyEx(mask, mask, MORPH_OPEN, element);
	dilate(mask, mask, element);
	morphologyEx(mask, mask, MORPH_CLOSE, element);
	frame.copyTo(dst, mask);
}
/*************************
********* 拍照 ***********
**************************/
//void cameraGet::takingPictures()
//{
//	frame = cvQueryFrame(cam);// 从摄像头中抓取并返回每一帧

//	// 中值滤波，去除椒盐噪声
//	medianBlur(frame, frame, 5);
////	cvtColor( frame, frameHSV, CV_BGR2HSV );





//	// 将抓取到的帧，转换为QImage格式。QImage::Format_RGB888不同的摄像头用不同的格式。
//	QImage image = QImage((const uchar*)frame->imageData, frame->width,
//					  frame->height, QImage::Format_RGB888).rgbSwapped().mirrored();

//	ui->label_2->setPixmap(QPixmap::fromImage(image));  // 将图片显示到label上
//}

/*******************************
***关闭摄像头，释放资源，必须释放***
********************************/
void cameraGet::closecamera()
{
	timer->stop();         // 停止读取数据。
	frame.release();
//	cvReleaseCapture(&cam);//释放内存；

}

cameraGet::~cameraGet()
{
	delete ui;
}

QImage cameraGet::Mat2QImage(const cv::Mat& mat)
{
	// 8-bits unsigned, NO. OF CHANNELS = 1
	if(mat.type() == CV_8UC1)
	{
		QImage image(mat.cols, mat.rows, QImage::Format_Indexed8);
		 //Set the color table (used to translate colour indexes to qRgb values)
		image.setColorCount(256);
		for(int i = 0; i < 256; i++)
		{
			image.setColor(i, qRgb(i, i, i));
		}
		// Copy input Mat
		uchar *pSrc = mat.data;
		for(int row = 0; row < mat.rows; row ++)
		{
			uchar *pDest = image.scanLine(row);
			memcpy(pDest, pSrc, mat.cols);
			pSrc += mat.step;
		}
		return image;
	}
	// 8-bits unsigned, NO. OF CHANNELS = 3
	else if(mat.type() == CV_8UC3)
	{
		// Copy input Mat
		const uchar *pSrc = (const uchar*)mat.data;
		// Create QImage with same dimensions as input Mat
		QImage image(pSrc, mat.cols, mat.rows, mat.step, QImage::Format_RGB888);
		return image.rgbSwapped();
	}
	else if(mat.type() == CV_8UC4)
	{
		qDebug() << "CV_8UC4";
		// Copy input Mat
		const uchar *pSrc = (const uchar*)mat.data;
		// Create QImage with same dimensions as input Mat
		QImage image(pSrc, mat.cols, mat.rows, mat.step, QImage::Format_ARGB32);
		return image.copy();
	}
	else
	{
		qDebug() << "ERROR: Mat could not be converted to QImage.";
		return QImage();
	}
}
