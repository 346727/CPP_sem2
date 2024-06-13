#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include <QTimer>

class MyWidget : public QWidget
{
    Q_OBJECT
  public:
    constexpr auto static timer_interval = 200;
    constexpr auto static num_disks = 12;
    explicit MyWidget(QWidget *parent = nullptr);
    virtual void paintEvent(QPaintEvent *event);


  signals:
    void updateButtonIcon(const QIcon &icon);

  public slots:
    void on_timer();
    void toggle_animation();
    //void updateButtonIcon(const QIcon &icon);

  private:
    int hidden = 0;
    QTimer timer;
};

#endif  // MYWIDGET_H
