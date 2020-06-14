#include "mybuttonhandler.h"

MyButtonHandler::MyButtonHandler(QObject *parent) :
    QObject(parent)
    {
    }

    void MyButtonHandler::someSlot(QString str, int index) {
        qDebug() << "someSlot received string: " << str;
        std::string output = "Please input number and then try";
        if (index == 0){
            output = primeNumber(str);
        }
        else if (index == 1){
            output = perfectNumber(str);
        }
        else if (index == 2){
            output = factorial(str);
        }
        QString qstr = QString::fromStdString(output);
        someSignal(qstr);
    }
