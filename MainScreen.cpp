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
    ui->smallButton->setIcon(QIcon(":/small.bmp"));
    ui->closeButton->setIcon(QIcon(":/close.bmp"));
    ui->VersionLabel->setPixmap(QPixmap (":/Version.png"));
    ui->smallButton->installEventFilter(this);
    ui->closeButton->installEventFilter(this);

    ui->label->setStyleSheet("QLabel { background-color : red; color : blue; }");
   // ui->label_2->setStyleSheet("QLabel { background-color : blue; color : red; }");

}
Widget::~Widget()
{
    delete ui;
}
bool Widget::eventFilter(QObject *obj, QEvent *event)
{
    if (obj == (QObject*)ui->smallButton || obj == (QObject*)ui->closeButton) {
        if (event->type() == QEvent::Enter)
        {
            if(obj == (QObject*)ui->smallButton)
                ui->smallButton->setIcon(QIcon(":/small-select.bmp"));
            else if(obj == (QObject*)ui->closeButton)
                ui->closeButton->setIcon(QIcon(":/close-select.bmp"));

        }else if(event->type() == QEvent::Leave)
        {
            if(obj == (QObject*)ui->smallButton)
                ui->smallButton->setIcon(QIcon(":/small.bmp"));
            else if(obj == (QObject*)ui->closeButton)
                ui->closeButton->setIcon(QIcon(":/close.bmp"));

        }
        return QWidget::eventFilter(obj, event);
    }else {
        // pass the event on to the parent class
        return QWidget::eventFilter(obj, event);
    }
}
