#include <math.h>
#include "figura.h"
void Figura::move(float Alpha,QPainter *Painter) // определение  метода move, который перемещает фигуру.
{
    dx=halflen*cos(Alpha); //перемещение объекта по оси X.
    dy=halflen*sin(Alpha); //перемещение объекта по оси У.
    draw(Painter); // Вызывается функция draw(), она отвечает за отрисовку объекта и использует переданный объект Painter для рисования.
}
void MyLine::draw(QPainter *Painter) // реализация функции draw для класса MyLine
{
    Painter->drawLine(x+dx,y+dy,x-dx,y-dy); //Эта строка кода отрисовывает линию, начиная с координаты x+dx, y+dy и заканчивая в координатах x-dx, y-dy.
}
void MyRect::draw(QPainter *Painter) // реализация функции draw для класса MyRect
{
    //отрисовка прямоугольника
    Painter->drawLine(x+dx,y+dy,x+dy,y-dx);
    Painter->drawLine(x+dy,y-dx,x-dx,y-dy);
    Painter->drawLine(x-dx,y-dy,x-dy,y+dx);
    Painter->drawLine(x-dy,y+dx,x+dx,y+dy);
}
