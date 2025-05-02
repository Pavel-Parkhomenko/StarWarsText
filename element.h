#ifndef ELEMENT_H
#define ELEMENT_H

#include <QWidget>
#include <QPaintEvent>
#include <QFont>
#include <QPainter>
#include <QDebug>
#include <QTransform>

class Element : public QWidget
{
  Q_OBJECT
public:
  explicit Element(QString text, QWidget *parent = nullptr);
  qreal scale = 50;

  void changeSize(int pt) {
    QSize size = this->size();
    if(size.width() - pt < 0) return;
    this->setFixedSize(size.width() - pt, size.height() - pt);
  }

protected:
  void paintEvent(QPaintEvent *) override {
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    // Рисуем рамку вокруг всего виджета
//    painter.setPen(QPen(Qt::red, 2)); // Красная рамка толщиной 2px
//    painter.drawRect(rect().adjusted(1, 1, -1, -1)); // Учитываем толщину пера

    QFont font("Arial", scale, QFont::Bold);
    painter.setFont(font);
    painter.setPen(QColor(255, 215, 0));

    QPointF center(width()/2.0, height()/2.0);

    QTransform transform;
    transform.translate(center.x(), center.y());
    transform.rotate(62, Qt::XAxis);
    transform.shear(-0.1, 0);
    transform.translate(-center.x(), -center.y());
    painter.setTransform(transform);

    QFontMetrics fm(font);
    QRect textBound = fm.boundingRect(text);
    QRectF textRect(
        center.x() - textBound.width() / 2.0,
        center.y() - textBound.height() / 2.0,
        textBound.width(),
        textBound.height()
        );

//    QRect textRect = rect();

    painter.drawText(textRect, Qt::AlignCenter, this->text);
  }


  private:
  QString text;

signals:

};

#endif // ELEMENT_H
