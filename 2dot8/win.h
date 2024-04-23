#ifndef WIN_H
#define WIN_H
#include <QtGui>
#include <QMainWindow>
#include <QFrame>
#include<QLabel>
#include<QLineEdit>
#include<QPushButton>
#include <QWidget>

class Counter:public QLineEdit //класс счетчик наследуемый от QLineEdit
{
    Q_OBJECT
public:
    Counter(const QString & contents, QWidget *parent=0): // конструктор класса Counter с параметрами содержимого и родителя
        QLineEdit(contents,parent){} // вызов конструктора базового класса QLineEdit
signals:
    void tick_signal(); // новый сигнал. срабатывает если число счётчика кратно 5 и не равно 0
public slots:
    void add_one() // объявление слота для увеличения значения на 1
    {
        QString str=text(); // получение текстового значения из поля
        int r=str.toInt(); // преобразование текста в целое число
        if (r!=0 && r%5 ==0) emit tick_signal();
        r++;
        str.setNum(r); // преобразовать число в строку
        setText(str); // установить новое значение в текстовое поле
    }
};

class win : public QWidget
{
    Q_OBJECT
protected:
    QLabel *label1,*label2;
    Counter *edit1,*edit2;
    QPushButton *calcbutton;
    QPushButton *exitbutton;
public:
    win(QWidget *parent = 0);

};
#endif // WIN_H
