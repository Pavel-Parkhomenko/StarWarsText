#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include "element.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
  Q_OBJECT

  public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

  private:
    Ui::MainWindow *ui;
    QVector<Element*> els;
    int posX = 0;
    int posY = 0;

    void changeScale();

    QVector<QHBoxLayout*> hls;
    QVBoxLayout *vl;

  protected:
    void keyPressEvent(QKeyEvent *event) override;
};
#endif // MAINWINDOW_H
