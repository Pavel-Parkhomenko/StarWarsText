#include "element.h"
#include "qnamespace.h"

Element::Element(QString text, QWidget *parent)
    : QWidget{parent}
{
  this->text = text;
  setFixedSize(50, 60); //75
//  this->setStyleSheet("border: 2px solid red;");

//  this->setFixedSize(200, 200);
//  QPainter painter(this);
//  painter.setRenderHint(QPainter::Antialiasing);
//  painter.fillRect(rect(), Qt::yellow);
}
