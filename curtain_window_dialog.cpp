#include "curtain_window_dialog.h"
#include "ui_curtain_window_dialog.h"
#include "selectroom_dialog.h"
#include "QMovie"
#include "QDebug"


QMovie *movie1,*movie2;

unsigned char curtain1_control_num;
unsigned char curtain2_control_num;

CurtainWindowDialog::CurtainWindowDialog(QWidget *parent) :
    QDialog(parent),
	ui(new Ui::CurtainWindowDialog)
{
    //默认窗帘1停
    curtain1_control_num=CUATAIN_STOP;
    //默认窗帘2停
    curtain2_control_num=CUATAIN_STOP;
    ui->setupUi(this);


    movie1=new QMovie(this);
    movie2=new QMovie(this);
    movie1->setFileName(":/gif/image/curtain.gif");
    movie2->setFileName(":/gif/image/curtain.gif");
    movie1->setCacheMode(QMovie::CacheAll);
    movie2->setCacheMode(QMovie::CacheAll);
    QSize size=ui->label_3->size();
    qDebug()<<size;
    movie1->setScaledSize(QSize(206,120));
    movie2->setScaledSize(QSize(206,120));

    ui->label_2->setMovie(movie1);
    ui->label_3->setMovie(movie2);

//    movie1->setSpeed(10);
    movie1->start();
    movie2->start();

    setWindowFlags(Qt::FramelessWindowHint); //把窗口设置成没框架的



}

CurtainWindowDialog::~CurtainWindowDialog()
{
    delete ui;
}




//设置第一组窗帘控制按钮的释放
void CurtainWindowDialog::SetButton1Free(void)
{
    switch(curtain1_control_num)
    {
        case CUATAIN_UP:
        disconnect(ui->curtain1standup,SIGNAL(toggled(bool)),
                    this,SLOT(on_curtain1standup_toggled(bool)));
        ui->curtain1standup->setChecked(false);
        connect(ui->curtain1standup,SIGNAL(toggled(bool)),
                            this,SLOT(on_curtain1standup_toggled(bool)));
        break;
        case CUATAIN_STOP:
        disconnect(ui->curtain1standstop,SIGNAL(toggled(bool)),
                    this,SLOT(on_curtain1standstop_toggled(bool)));
        ui->curtain1standstop->setChecked(false);
        connect(ui->curtain1standup,SIGNAL(toggled(bool)),
                            this,SLOT(on_curtain1standstop_toggled(bool)));
        break;
        case CUATAIN_DOWN:
        disconnect(ui->curtain1standdown,SIGNAL(toggled(bool)),
                    this,SLOT(on_curtain1standdown_toggled(bool)));
        ui->curtain1standdown->setChecked(false);
        connect(ui->curtain1standup,SIGNAL(toggled(bool)),
                            this,SLOT(on_curtain1standdown_toggled(bool)));
        break;

    }
}

//设置第二组窗帘控制按钮的释放
void CurtainWindowDialog::SetButton2Free(void)
{

}



void CurtainWindowDialog::on_curtain1standup_toggled(bool checked)
{
    if(curtain1_control_num!=CUATAIN_UP)
    {
        if(checked==true)
        {
            SetButton1Free();
            curtain1_control_num=CUATAIN_UP;
        }
    }
    else
    {
 //       ui->curtain1standup->setChecked(true);
    }
    qDebug()<<curtain1_control_num;
}

void CurtainWindowDialog::on_curtain1standstop_toggled(bool checked)
{
    if(curtain1_control_num!=CUATAIN_STOP)
    {
        if(checked==true)
        {
            SetButton1Free();
            curtain1_control_num=CUATAIN_STOP;
        }
    }
    else
    {
 //       ui->curtain1standstop->setChecked(true);
    }
    qDebug()<<curtain1_control_num;
}

void CurtainWindowDialog::on_curtain1standdown_toggled(bool checked)
{
    if(curtain1_control_num!=CUATAIN_DOWN)
    {
        if(checked==true)
        {
            SetButton1Free();
            curtain1_control_num=CUATAIN_DOWN;
        }
    }
    else
    {
 //       ui->curtain1standdown->setChecked(true);
    }
    qDebug()<<curtain1_control_num;
}

void CurtainWindowDialog::on_curtain2standup_toggled(bool checked)
{

}

void CurtainWindowDialog::on_curtain2standstop_toggled(bool checked)
{

}

void CurtainWindowDialog::on_curtain2standdown_toggled(bool checked)
{

}
