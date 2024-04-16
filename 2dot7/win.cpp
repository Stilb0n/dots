#include "win.h"
#include<QMessageBox>
#include<QBoxLayout>
#include<QValidator>

win::win(QWidget *parent)
    : QWidget(parent)
{
    codec = QTextCodec::codecForName("Windows-1251");
    setWindowTitle(codec->toUnicode("Возведение в квадрат"));
    frame = new QFrame(this);
    frame->setFrameShadow(QFrame::Raised); //тень будет поднятой
    frame->setFrameShape(QFrame::Panel);//рамка будет прямоугольной с простым угловым соединением
    inputLabel = new QLabel(codec->toUnicode("Введите число:"),
                            this);



    inputLabel = new QLabel(codec->toUnicode("Введите число:"),this); //метка для текста над редактором ввода
    inputEdit = new QLineEdit("",this);
    //Передача указателя на объект QLineEdit в конструктор StrValidator позволяет связать этот валидатор с конкретным полем ввода и применить к нему заданные правила валидации.
    StrValidator *v=new StrValidator(inputEdit); // передается указатель на объект QLineEdit в качестве аргумента конструктора
    inputEdit->setValidator(v); // устанавливаем валидатор для редактора ввода
    outputLabel = new QLabel(codec->toUnicode("Результат:"),
                             this); // метка для текста перед редактором вывода
    outputEdit = new QLineEdit("",this); // редактор вывода
    nextButton = new QPushButton(codec->toUnicode("Следующее"),
                                 this); // кнопка для ввода следующего числа
    exitButton = new QPushButton(codec->toUnicode("Выход"),
                                 this); //кнопка выхода из приложения
    // компоновка приложения
    QVBoxLayout *vLayout1 = new QVBoxLayout(frame); //Класс QVBoxLayout Выстраивает виджеты в вертикальную линию
    vLayout1->addWidget(inputLabel);
    vLayout1->addWidget(inputEdit);
    vLayout1->addWidget(outputLabel);
    vLayout1->addWidget(outputEdit); 
    vLayout1->addStretch(); //при растягивании окна объекты держатся вместе
    QVBoxLayout *vLayout2 = new QVBoxLayout(); // еще один объект класса QVBoxLayout, но в данном случае он создается без родительского виджета. Для особой рамки была только у ввода и вывода.
    vLayout2->addWidget(nextButton);
    vLayout2->addWidget(exitButton);
    vLayout2->addStretch();
    QHBoxLayout *hLayout = new QHBoxLayout(this); //Класс QVBoxLayout Выстраивает виджеты в горизонтальную линию
    hLayout->addWidget(frame);
    hLayout->addLayout(vLayout2);
    begin(); //слот, метод начальной настройки интерфейса

    // Подключение сигнала и слота для кнопки выхода
    connect(exitButton, &QPushButton::clicked, this, &win::close);

    // Подключение сигнала и слота для кнопки "Далее"
    connect(nextButton, &QPushButton::clicked, this, &win::begin);

    // Подключение сигнала и слота для редактирования ввода
    connect(inputEdit, &QLineEdit::returnPressed, this, &win::calc);
}



void win::begin()
{
    inputEdit->clear(); //очищаем редакор ввода
    nextButton->setEnabled(false); // делаем неактивной кнопку далее
    nextButton->setDefault(false); // отключаем автоматическое нажатие кнопки при нажатии кнопки Enter
    inputEdit->setEnabled(true);// делаем активным редактор ввода
    outputLabel->setVisible(false); // делаем невидимым метку вывода
    outputEdit->setVisible(false); // делаем невидимым редактор вывода
    outputEdit->setEnabled(false); // делаем неактивным редактор вывода
    inputEdit->setFocus(); // Предоставлям фокус ввода с клавиатуры редактору ввода
}
// метод реализации вычислений
void win::calc()
{
    bool Ok=true; float r,a;
    QString str=inputEdit->text(); //переносим текст в переменную str из редактора ввода
    //передаем адрес если бы не адрес то не скомпилировался бы (! далее идёт неверное утверждение -> передаем переменную по адресу для того чтобы функция могла её изменить!.)
    a=str.toDouble(&Ok);
    if ((Ok)&&(a<1000)) // если введены символы приемлимого типа,то есть числа то происходят дальнейшие вычисления так же если число меньше 1000
    {
        r=a*a; //возведение в квадрат
        str.setNum(r); // применение изменений к str
        outputEdit->setText(str); // помещаем str в редактор вывода
        inputEdit->setEnabled(false); //деактивируется редактор ввода
        outputLabel->setVisible(true); // активируется видимость метки вывода
        outputEdit->setVisible(true); // активируется видимость редактора вывода
        nextButton->setDefault(true); //активируется принятие нажатия кнопкой энтера кнопки следующее
        nextButton->setEnabled(true); //активируется возможность нажать кнопку следующее
        nextButton->setFocus(); // ставится фокусировка на кнопку следующее
    }
    else // если введены символы неприемлимого типа,то есть числа то происходят дальнейшие вычисления так же если число больше или равно 1000
        if (!str.isEmpty()) // дополнительная проверка если строка не пустая
        {
            QMessageBox msgBox(QMessageBox::Information,
                               codec->toUnicode("Возведение в квадрат."),
                               codec->toUnicode("Введено неверное значение."),
                               QMessageBox::Ok); //инициализируем объект типа информационного окна, который уведомляет о ситуации
            msgBox.exec(); // делает окно модальным, Модальным называется окно, которое блокирует работу пользователя с родительским приложением до тех пор, пока пользователь это окно не закроет.
        }
}


win::~win()
{
}

