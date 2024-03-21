#ifndef WIN_H
#define WIN_H
#include <QtGui>
#include <QMainWindow>
#include <QFrame>
#include <QTextCodec>
#include<QLabel>
#include<QLineEdit>
#include<QPushButton>

class win : public QWidget // класс окна
{
    Q_OBJECT // макрос Qt, обеспечивающий корректное создание сигналов и слотов
protected:
    QTextCodec *codec; //перекодировщик
    QFrame *frame; // рамка
    QLabel *inputLabel; // метка ввода
    QLineEdit *inputEdit; // строчный редактор ввода
    QLabel *outputLabel; // метка вывода
    QLineEdit *outputEdit; // строчный редактор вывода
    QPushButton *nextButton; // кнопка Следующее
    QPushButton *exitButton; // кнопка Выход


public:
    win(QWidget *parent = 0);
    ~win();
public slots:
    void begin(); // метод начальной настройки интерфейса
    void calc(); // метод реализации вычислений
};
#endif // WIN_H
