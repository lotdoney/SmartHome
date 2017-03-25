#ifndef CONTROL_DIALOG_H
#define CONTROL_DIALOG_H

#include <QDialog>
#include "QPushButton"

#define SETTING_NUM     1
#define LIGHT_NUM       2
#define CURTAIN_NUM     3
#define AIR_NUM         4
#define SECURITY_NUM    5
#define TV_NUM          6
#define TALKBACK_NUM    7
#define MUSIC_NUM       8
#define MOV_NUM         9
namespace Ui {
class Control_Dialog;
}

class Control_Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Control_Dialog(QWidget *parent = 0);
    ~Control_Dialog();
	char GetControl_Num(void);

private slots:
 //   void on_Light_Control_toggled(bool checked);


    void on_LightControl_toggled(bool checked);

    void on_SettingControl_toggled(bool checked);

    void on_CurtainControl_toggled(bool checked);

    void on_AirControl_toggled(bool checked);

    void on_SecurityControl_toggled(bool checked);

    void on_TVControl_toggled(bool checked);

    void on_TalkbackControl_toggled(bool checked);

    void on_MusicControl_toggled(bool checked);

    void on_MoveControl_toggled(bool checked);

	void on_CurtainControl_clicked();

	void on_LightControl_clicked();

private:
    Ui::Control_Dialog *ui;
    unsigned int Control_Num;

    void SetButtonFree(void);

};

#endif // CONTROL_DIALOG_H
