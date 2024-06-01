#include "my_widget.h"

#include <QPainter>
#include <QMouseEvent>
#include <QRandomGenerator>

MyWidget::MyWidget(QWidget* parent)
    : QWidget(parent)
{
    setFocusPolicy(Qt::StrongFocus);
}

void MyWidget::paintEvent([[maybe_unused]] QPaintEvent* event)
{
    QPainter painter(this); // painter to obiekt odpowiedzialny za opisanie i rysowanie piórem, malowanie pędzlem itp.

    painter.setRenderHint(QPainter::Antialiasing);                   // bajer. Rysunki w tym trybie wyglądają nieco lepiej.
    painter.setBrush(QBrush(QColor(Qt::GlobalColor::darkMagenta)));  // pędzel (brush) maluje duż epowierzchnie
    auto r = this->rect();                                           // rect() zwraca prostokąt obszaru roboczego bieżącego okienka
    painter.drawRect(r);                                             // malujemy cały obszar roboczy kolorem darkMagenta

    for (const auto& circ : circles)                                // malujemy wszystkie "wyklikane" kółka
    {
        painter.setBrush(QBrush(circ.color));                       // ustawiamy kolor pędzla dla każdego kółka
        QPointF point(circ.center.x() * r.width(), circ.center.y() * r.height());
        painter.drawEllipse(point, circ.radius, circ.radius);  // koło jest przypadkiem szczególnym elipsy
    }
}

void MyWidget::mousePressEvent(QMouseEvent* event)
{
    auto pos = event->localPos();           // współrzędne położenia myszy we współrzędnych obszaru roboczego bieżącego okna
    auto rec = rect();                      // prostokąt obszaru roboczego bieżącego okna
    Circle c;                               // kolejne kółko
    c.radius = DEFAULT_RADIUS;              // w tej wersji programu wszystkie kółka mają ten sam promień
    c.center.setX(pos.x() / rec.width());   // składowa "x" środka kółka
    c.center.setY(pos.y() / rec.height());  // składowa "y" środka kółka
    c.color = Qt::darkYellow;               // ustawiamy domyślny kolor kółka
    circles.push_back(c);                   // dodanie kółka na koniec wektora `circles`
    repaint();                              // wymuszamy odświeżenie okna bieżącego obiektu (pośrednio uruchomi MyWidget::paintEvent)
}

void MyWidget::keyPressEvent(QKeyEvent* event)
{
    if (event->modifiers() & Qt::ControlModifier && event->key() == Qt::Key_Z) { // używam ctrl+U
        if (!circles.empty()) {
            circles.pop_back();  // usuwam kółko
            repaint();
        }
    } else {
        QWidget::keyPressEvent(event);
    }
}

void MyWidget::mouseDoubleClickEvent(QMouseEvent* event)
{
    for (auto& circ : circles) {
        circ.color = QColor::fromRgb(QRandomGenerator::global()->generate());
    }
    repaint();
    QWidget::mouseDoubleClickEvent(event);
}
