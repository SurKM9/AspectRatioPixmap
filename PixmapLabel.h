#ifndef PIXMAPLABEL_H
#define PIXMAPLABEL_H

#include <QLabel>
#include <QPixmap>


class PixmapLabel : public QLabel
{
    public:

        PixmapLabel(QWidget* parent = nullptr);
        virtual QSize sizeHint() const override;

        void setImage(const QPixmap& image);
        int heightForWidth(int width) const override;

    protected:

        void paintEvent(QPaintEvent* event) override;

    private:

        QPixmap m_pixmap;
        int m_cols;
        int m_rows;
};
#endif // PIXMAPLABEL_H
