#ifndef LIGHT_WINDOW_DIALOG_H
#define LIGHT_WINDOW_DIALOG_H

#include <QDialog>

namespace Ui {
class Light_Window_Dialog;
}

class LightWindowDialog : public QDialog
{
    Q_OBJECT

public:
	explicit LightWindowDialog(QWidget *parent = 0);
	~LightWindowDialog();

private:
    Ui::Light_Window_Dialog *ui;
};

#endif // LIGHT_WINDOW_DIALOG_H
