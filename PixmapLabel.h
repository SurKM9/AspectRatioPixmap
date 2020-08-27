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
        int widthForHeight(int height) const;
    protected:
        //        virtual void paintEvent(QPaintEvent* paintEvent) override;

    private:

        QPixmap m_pixmap;
        int m_cols;
        int m_rows;
};
#endif // PIXMAPLABEL_H
