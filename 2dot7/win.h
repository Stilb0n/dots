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
    /*следует следить, чтобы
    классы, определяющие новые сигналы и слоты, обязательно включали макрос Q_OBJECT,
обрабатываемый MOC. */
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

class StrValidator:public QValidator // класс компонента проверки ввода
{
public:
    StrValidator(QObject *parent):QValidator(parent){}
    virtual State validate(QString &str,int &pos)const
    {
        return Acceptable; // метод всегда принимает вводимую строку
    }
};
#endif
