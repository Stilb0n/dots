#ifndef window_h
#define window_h
#include <QtGui>
#include<QPushButton>
#include "area.h"
class Window : public QWidget
{
protected:
    Area * area; // область отображения рисунка
    QPushButton * btn;
public:
    Window();
};
#endif
