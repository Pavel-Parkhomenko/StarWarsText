#include "mainwindow.h"
#include "qnamespace.h"
#include "ui_mainwindow.h"

#include <QLabel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
  ui->setupUi(this);

  this->setStyleSheet(
      "QMainWindow {"
      "   background-image: url(:/img/back.jpg);"
      "   background-position: center;"
      "   background-repeat: no-repeat;"
      "   background-attachment: fixed;"
      "}"
      );

//  this->setStyleSheet("background-color: black;");
  this->vl = new QVBoxLayout(this->centralWidget());
  vl->setSpacing(0);
  vl->addStretch();

//  this->setFixedHeight(600);
}

void MainWindow::keyPressEvent(QKeyEvent *event) {
  if (event->text().isEmpty()) {
    event->ignore();
    return;
  }

  if(els.length() % 15 == 0) {
    changeScale();


    QHBoxLayout *hl = new QHBoxLayout;
    hl->setSpacing(0);
    hl->setAlignment(Qt::AlignCenter);
    hl->setContentsMargins(0, 0, 0, 0);
    hls.push_back(hl);

    this->vl->addLayout(hl);
  }

  Element *el = new Element(event->text());
  QHBoxLayout* lastLayout = hls.back();
  lastLayout->addWidget(el);

  els.push_back(el);

  QWidget::keyPressEvent(event);
}

void MainWindow::changeScale() {
  int fScale = 50;
  int cntRow = els.length() / 15;
  int s = fScale - (cntRow * 3);

  for(int i = 0; i < els.length(); i++) {
    if(i % 15 == 0 && i != 0) {
      s += 3;
    }

    els[i]->changeSize(3);
    els[i]->scale = s;
    els[i]->update();
  }
}

MainWindow::~MainWindow()
{
  delete ui;
}

