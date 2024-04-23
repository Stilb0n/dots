#ifndef FIGURA_H
#define FIGURA_H
#include <QtGui>
class Figura
{
protected:
    int x,y,halflen,dx,dy,r; // протектед поля: координаты по x,y, половина длины фигуры, изменение по х,у и радиус.
    virtual void draw(QPainter *Painter)=0; // чисто виртуальный метод draw принимает указатель на класс отвечающий за прорисовку
public:
    Figura(int X,int Y,int Halflen): //конструктор, принимает координаты по х,у и половины длины фигуры
        x(X),y(Y),halflen(Halflen){}
    void move(float Alpha,QPainter *Painter); // Объявление функции move, которая перемещает фигуру. Alpha - угол.
};
class MyLine:public Figura // Объявление класса MyLine, унаследованного от класса Figura.
{
protected:
    void draw(QPainter *Painter); // Объявление виртуальной функции draw для класса MyLine.
public:
    MyLine(int x,int y,int halflen):Figura(x,y,halflen){} // Объявление конструктора для класса MyLine.
};
class MyRect:public Figura // Объявление класса MyRect, унаследованного от класса Figura.
{
protected:
    void draw(QPainter *Painter); // Объявление виртуальной функции draw для класса MyRect.
public:
    MyRect(int x,int y,int halflen):Figura(x,y,halflen){} // Объявление конструктора для класса MyRect.
};
#endif
