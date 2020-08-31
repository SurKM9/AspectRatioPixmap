#include "PixmapLabel.h"
#include <QPainter>
#include <QDebug>


PixmapLabel::PixmapLabel(QWidget* parent) :
    QLabel(parent),
    m_cols(0),
    m_rows(0)
{
    QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    sizePolicy.setHeightForWidth(true);
    sizePolicy.setWidthForHeight(true);
    setSizePolicy(sizePolicy);

    // set borders on the QLabel
    setStyleSheet("QLabel{border: 1px solid black; background: gray;}");
}


void PixmapLabel::setImage(const QPixmap& image)
{
    m_pixmap = image;

    m_cols = m_pixmap.width();
    m_rows = m_pixmap.height();

    setPixmap(scaledPixmap()); // <= this acts weird

    //update();  // <= this works
}


/* virtual */ QSize PixmapLabel::sizeHint() const
{
    if (m_cols != 0)
    {
        return QSize(m_cols, heightForWidth(m_cols));
    }
    else
    {
        return QSize(100, 100);
    }
}


/* virtual */ int PixmapLabel::heightForWidth(int width) const
{
    return (m_cols != 0) ? width * m_rows / m_cols : width;
}



int PixmapLabel::widthForHeight(int height) const
{
    return (m_rows != 0) ? height * m_cols / m_rows : height;
}


QPixmap PixmapLabel::scaledPixmap()
{
    auto scaled = m_pixmap.scaled(this->size() * devicePixelRatioF(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
    scaled.setDevicePixelRatio(devicePixelRatioF());

    return scaled;
}



//void PixmapLabel::paintEvent(QPaintEvent* paintEvent)
//{
//    if (!m_pixmap.isNull())
//    {
//        qDebug() << "Label size inside paint event: " << this->size();
//        //qDebug() << "Width: " << width() << "Height: " << height();

//        // create painter
//        QPainter painter(this);

//        // enable anti aliasing
//        painter.setRenderHint(QPainter::Antialiasing);

//        // scale the pixmap
//        // this should work for High DPI screens as well
//        auto scaled = m_pixmap.scaled(this->size() * devicePixelRatioF(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
//        scaled.setDevicePixelRatio(devicePixelRatioF());

//        // draw the pixmap
//        painter.drawPixmap(QPoint(), scaled);
//    }
//    else
//    {
//        QLabel::paintEvent(paintEvent);
//    }
//}


void PixmapLabel::resizeEvent(QResizeEvent* event)
{
    Q_UNUSED(event);
    if(!m_pixmap.isNull())
    {
        QLabel::setPixmap(scaledPixmap());
    }
}
