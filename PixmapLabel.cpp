#include "PixmapLabel.h"
#include <QPainter>
#include <QDebug>
#include <QPaintEvent>



PixmapLabel::PixmapLabel(QWidget* parent) :
    QLabel(parent),
    m_cols(0),
    m_rows(0)
{
    QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    sizePolicy.setHeightForWidth(true);
    setSizePolicy(sizePolicy);

    setMinimumSize(sizeHint());

    // set borders on the QLabel
    setStyleSheet("QLabel{border: 1px solid black; background: gray;}");
}



void PixmapLabel::setImage(const QPixmap& image)
{
    m_pixmap = image;

    m_cols = m_pixmap.width();
    m_rows = m_pixmap.height();

    update();
}



/* virtual */ QSize PixmapLabel::sizeHint() const
{
    if (m_cols != 0)
    {
        int width = this->width();
        return QSize(width, heightForWidth(width));
    }
    else
    {
        return QSize(200, 200);
    }
}



/* virtual */ int PixmapLabel::heightForWidth(int width) const
{
    return (m_cols != 0) ? width * m_rows / m_cols : width;
}



void PixmapLabel::paintEvent(QPaintEvent* event)
{
    QLabel::paintEvent(event);

    if(m_pixmap.isNull())
    {
        return;
    }

    // Create painter
    QPainter painter(this);

    // Get current pixmap size
    QSize pixmapSize = m_pixmap.size();

    // Scale size to painted rect
    pixmapSize.scale(event->rect().size(), Qt::KeepAspectRatio);

    // Scale the pixmap
    QPixmap pixmapScaled = m_pixmap.scaled(pixmapSize, Qt::KeepAspectRatio, Qt::SmoothTransformation);

    // Draw the pixmap
    painter.drawPixmap(QPoint(), pixmapScaled);
}
