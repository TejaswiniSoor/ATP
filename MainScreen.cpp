#include "MainScreen.h"
#include "ui_MainScreen.h"
#include "QDesktopWidget"
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    QPalette palette;
    palette.setBrush(this->backgroundRole(), QBrush(QImage(":/background.bmp")));
    this->setPalette(palette);

    QRect r = this->geometry();
    r.moveCenter(QApplication::desktop()->availableGeometry().center());
    this->setGeometry(r);
}

Widget::~Widget()
{
    delete ui;
}
