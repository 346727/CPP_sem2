#include "my_widget.h"

#include <QPainter>
#include <QRadialGradient>
#include <QIcon>

MyWidget::MyWidget(QWidget* parent)  //
    : QWidget(parent), timer(this)
{
    timer.start(timer_interval);
    connect(&timer, SIGNAL(timeout()), this, SLOT(on_timer()));
}

void MyWidget::paintEvent(QPaintEvent* event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    // Ustawienie tła na jasnoszare
    painter.fillRect(rect(), Qt::lightGray);

    painter.translate(rect().width() / 2.0, rect().height() / 2.0);
    auto side = std::min(rect().width(), rect().height());
    painter.scale(side / 200.0, side / 200.0);
    painter.setPen(Qt::NoPen);

    for (int i = 0; i < num_disks; i++)
    {
        if (i != hidden)
        {
            // Tworzenie radialnego gradientu
            QRadialGradient gradient(0, 60, 20); // Środek gradientu na środku kółka
            gradient.setColorAt(0, QColor(255, 20, 147, 255)); // Główny kolor kółka
            gradient.setColorAt(1, QColor(255, 20, 147, 0));   // Przezroczysty na krawędziach

            painter.setBrush(gradient);
            painter.drawEllipse(-20, 40, 40, 40); // Rozmiar kółka
        }
        painter.rotate(360.0 / num_disks);
    }

    // Ustawienie koloru pędzla
    QPen pen(Qt::black, 2);
    painter.setPen(pen);

    // Rysowanie krzyżyka
    int width = 5;
    int height = 5;
    int midX = 0;  // Środek przetransformowanego układu współrzędnych
    int midY = 0;  // Środek przetransformowanego układu współrzędnych
    painter.drawLine(midX, -height , midX, height); // Linia pionowa
    painter.drawLine(-width, midY, width, midY);   // Linia pozioma
}

void MyWidget::on_timer()
{
    hidden = (hidden + 1) % num_disks;
    update();
}

void MyWidget::toggle_animation()
{
    if (timer.isActive())
    {
        timer.stop();
        emit updateButtonIcon(QIcon(":/img/media-playback-start.png"));
    }
    else
    {
        timer.start(timer_interval);
        emit updateButtonIcon(QIcon(":/img/media-playback-stop.png"));
    }
}
//