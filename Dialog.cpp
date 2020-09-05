#include "Dialog.h"
#include "ui_Dialog.h"
#include <QDebug>

Dialog::Dialog(QWidget* parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
    , m_swap(true)
{
    ui->setupUi(this);
}



Dialog::~Dialog()
{
    delete ui;
}



void Dialog::on_pushButton_clicked()
{
    if(m_swap)
    {
        QImage image1(":/images/images/1.png");
        ui->label->setImage(QPixmap::fromImage(image1));

        m_swap = false;
    }
    else
    {
        QImage image2(":/images/images/2.jpg");
        ui->label->setImage(QPixmap::fromImage(image2));

        m_swap = true;
    }

    int w = ui->label->width();
    int h = ui->label->heightForWidth(w);

    ui->label->setFixedHeight(h);
}



void Dialog::resizeEvent(QResizeEvent* event)
{
    Q_UNUSED(event);

    int w = ui->label->width();
    int h = ui->label->heightForWidth(w);

    ui->label->setFixedHeight(h);
}


