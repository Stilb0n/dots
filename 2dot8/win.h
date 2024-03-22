#ifndef WIN_H
#define WIN_H
#include <QtGui>
#include <QMainWindow>
#include <QFrame>
//#include <QTextCodec>
#include<QLabel>
#include<QLineEdit>
#include<QPushButton>
#include <QWidget>

class Counter:public QLineEdit
{
    Q_OBJECT
public:
    Counter(const QString & contents, QWidget *parent=0):
        QLineEdit(contents,parent){}
signals:
    void tick_signal();
public slots:
    void add_one()
    {
        QString str=text();
        int r=str.toInt();
        if (r!=0 && r%5 ==0) emit tick_signal();
        r++;
        str.setNum(r);
        setText(str);
    }
};

class win : public QWidget
{
    Q_OBJECT
protected:
   // QTextCodec *codec;
    QLabel *label1,*label2;
    Counter *edit1,*edit2;
    QPushButton *calcbutton;
    QPushButton *exitbutton;
public:
    win(QWidget *parent = 0);

};
#endif // WIN_H
