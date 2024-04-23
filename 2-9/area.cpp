#include "area.h"
Area::Area(QWidget *parent):QWidget(parent)
{
    setFixedSize(QSize(300,200)); // Устанавливает минимальный и максимальный размеры виджета.s, тем самым предотвращая его рост или уменьшение.
    myline=new MyLine(80,100,50);
    myrect=new MyRect(220,100,50);
    alpha=0;
}
void Area::showEvent(QShowEvent *)
{
    myTimer=startTimer(50); // создать таймер
}
void Area::paintEvent(QPaintEvent *) //рисование пошагово перемещающихся фигур. переопределям стандартное событие отрисовки для виджета Area
{
    QPainter painter(this); // создается объект QPainter для рисования на виджете Area
    painter.setPen(Qt::red); //  Устанавливает красный цвет пера для рисования объектов с помощью объекта painter
    myline->move(alpha,&painter); //  перемещение объекта типа MyLine на указанный угол alpha.
    myrect->move(alpha*(-0.5),&painter);//перемещение объекта MyRect на угол, умноженный на -0.5.
}
void Area::timerEvent(QTimerEvent *event) // инициация перерисовки Холста
{
    if (event->timerId() == myTimer) // если наш таймер
    {
        alpha=alpha+0.2;
        update(); // обновить внешний вид
    }
    else
        QWidget::timerEvent(event); // иначе передать для стандартной
    // обработки
}
void Area::hideEvent(QHideEvent *)  //выключение таймера
{
    killTimer(myTimer); // уничтожить таймер
}
Area::~Area()
{
    delete myline;
    delete myrect;
}

