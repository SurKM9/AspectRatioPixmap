#include "Dialog.h"
#include "ui_Dialog.h"
#include <QDebug>

Dialog::Dialog(QWidget* parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_pushButton_clicked()
{
    ui->label_3->hide();
    ui->label_4->hide();

    QImage image1(":/images/images/1.png");
    ui->label->setImage(QPixmap::fromImage(image1));

    QImage image2(":/images/images/2.png");
    ui->label_2->setImage(QPixmap::fromImage(image2));

    QImage image3(":/images/images/3.jpg");
    ui->label_3->setImage(QPixmap::fromImage(image3));

    QImage image4(":/images/images/4.png");
    ui->label_4->setImage(QPixmap::fromImage(image4));


    int h = ui->label->height();
    int w = ui->label->widthForHeight(h);

    qDebug() << "Width For height: " << w << "Height: " << h;

    qDebug() << "label: " << ui->label->size();
    qDebug() << "label_2: " << ui->label_2->size();
    qDebug() << "label_3: " << ui->label_3->size();
    qDebug() << "label_4: " << ui->label_4->size();

    ui->label->setFixedWidth(w);
    ui->label_2->setFixedWidth(w);
    ui->label_3->setFixedWidth(w);
    ui->label_4->setFixedWidth(w);

    qDebug() << "label: " << ui->label->size();
    qDebug() << "label_2: " << ui->label_2->size();
    qDebug() << "label_3: " << ui->label_3->size();
    qDebug() << "label_4: " << ui->label_4->size();
}



void Dialog::resizeEvent(QResizeEvent* event)
{
    Q_UNUSED(event);

    int h = ui->label->height();
    int w = ui->label->widthForHeight(h);

    qDebug() << "Width For height: " << w << "Height: " << h;

    qDebug() << "label: " << ui->label->size();
    qDebug() << "label_2: " << ui->label_2->size();
    qDebug() << "label_3: " << ui->label_3->size();
    qDebug() << "label_4: " << ui->label_4->size();

    ui->label->setFixedWidth(w);
    ui->label_2->setFixedWidth(w);
    ui->label_3->setFixedWidth(w);
    ui->label_4->setFixedWidth(w);

    qDebug() << "label: " << ui->label->size();
    qDebug() << "label_2: " << ui->label_2->size();
    qDebug() << "label_3: " << ui->label_3->size();
    qDebug() << "label_4: " << ui->label_4->size();
}


