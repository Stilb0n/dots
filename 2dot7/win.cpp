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
    frame->setFrameShadow(QFrame::Raised);
    frame->setFrameShape(QFrame::Panel);
    inputLabel = new QLabel(codec->toUnicode("Введите число:"),
                            this);
    inputEdit = new QLineEdit("",this);
    StrValidator *v=new StrValidator(inputEdit);
    inputEdit->setValidator(v);
    outputLabel = new QLabel(codec->toUnicode("Результат:"),
                             this);
    outputEdit = new QLineEdit("",this);
    nextButton = new QPushButton(codec->toUnicode("Следующее"),
 this);
    exitButton = new QPushButton(codec->toUnicode("Выход"),
 this);
    // компоновка приложения
    QVBoxLayout *vLayout1 = new QVBoxLayout(frame);
    vLayout1->addWidget(inputLabel);
    vLayout1->addWidget(inputEdit);
    vLayout1->addWidget(outputLabel);
    vLayout1->addWidget(outputEdit);
    //при растягивании окна объекты держатся вместе
    vLayout1->addStretch();
    QVBoxLayout *vLayout2 = new QVBoxLayout();
    vLayout2->addWidget(nextButton);
    vLayout2->addWidget(exitButton);
    // почему тут 2 пружины?
    vLayout2->addStretch();
    QHBoxLayout *hLayout = new QHBoxLayout(this);
    hLayout->addWidget(frame);
    hLayout->addLayout(vLayout2);
    begin();
    //рассказать про функционал connect
    // Подключение сигнала и слота для кнопки выхода
    connect(exitButton, &QPushButton::clicked, this, &win::close);

    // Подключение сигнала и слота для кнопки "Далее"
    connect(nextButton, &QPushButton::clicked, this, &win::begin);

    // Подключение сигнала и слота для редактирования ввода
    connect(inputEdit, &QLineEdit::returnPressed, this, &win::calc);
}



void win::begin()
{
    inputEdit->clear();
    nextButton->setEnabled(false);
    nextButton->setDefault(false);
    inputEdit->setEnabled(true);
    outputLabel->setVisible(false);
    outputEdit->setVisible(false);
    outputEdit->setEnabled(false);
    inputEdit->setFocus();
}

void win::calc()
{
    bool Ok=true; float r,a;
    QString str=inputEdit->text();
    //передаем адрес если бы не адрес то не скомпилировался бы (!передаем переменную по адресу для того чтобы функция могла её изменить!.)
    a=str.toDouble(&Ok);
    if ((Ok)&&(a<1000))
    {
        r=a*a;
        str.setNum(r);
        outputEdit->setText(str);
        inputEdit->setEnabled(false);
        outputLabel->setVisible(true);
        outputEdit->setVisible(true);
        nextButton->setDefault(true);
        nextButton->setEnabled(true);
        nextButton->setFocus();
    }
    else
        if (!str.isEmpty())
        {
            QMessageBox msgBox(QMessageBox::Information,
                               codec->toUnicode("Возведение в квадрат."),
                               codec->toUnicode("Введено неверное значение."),
                               QMessageBox::Ok);
            msgBox.exec();
        }
}


win::~win()
{
}

