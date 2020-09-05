#include "Dialog.h"
#include "ui_Dialog.h"
#include <QDebug>

Dialog::Dialog(QWidget* parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
    , m_swap(true)
{
    ui->setupUi(this);
    m_image1 = QImage(":/images/images/1.png");
    m_image2 = QImage(":/images/images/2.jpg");
}



Dialog::~Dialog()
{
    delete ui;
}



void Dialog::on_pushButton_clicked()
{
    if(m_swap)
    {
        ui->label->setImage(QPixmap::fromImage(m_image1));

        m_swap = false;
    }
    else
    {
        ui->label->setImage(QPixmap::fromImage(m_image2));

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


