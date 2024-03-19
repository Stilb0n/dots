#ifndef WIN_H
#define WIN_H

#include <QMainWindow>

class win : public QMainWindow
{
    Q_OBJECT

public:
    win(QWidget *parent = nullptr);
    ~win();
};
#endif // WIN_H
